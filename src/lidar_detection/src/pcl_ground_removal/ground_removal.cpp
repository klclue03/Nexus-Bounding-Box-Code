#include "ground_removal.hpp"

GroundRemoval::GroundRemoval(double distance_threshold, double ground_clearance)
    : ground_clearance_(ground_clearance)
{
    seg_.setOptimizeCoefficients(true);
    // PERPENDICULAR_PLANE (not PLANE) is what makes setAxis/setEpsAngle take effect, so a wall or a
    // large flat object face can no longer win the fit and get removed instead of the floor.
    seg_.setModelType(pcl::SACMODEL_PERPENDICULAR_PLANE);
    seg_.setMethodType(pcl::SAC_RANSAC);
    seg_.setAxis(Eigen::Vector3f(0, 0, 1));
    seg_.setEpsAngle(10.0 * M_PI / 180.0);
    seg_.setDistanceThreshold(distance_threshold);
    seg_.setMaxIterations(500);  // PCL defaults to 50, which makes the fitted plane jitter between frames
}


// Function to remove ground
pcl::PointCloud<pcl::PointXYZ>::Ptr GroundRemoval::removeGround(const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
    pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
    pcl::ExtractIndices<pcl::PointXYZ> extract;

    // Perform RANSAC-based plane segmentation
    seg_.setInputCloud(cloud);
    seg_.segment(*inliers, *coefficients);

    // Check if a plane was detected
    if (inliers->indices.empty())
    {
        throw std::runtime_error("No ground plane detected.");
    }

    // Extract points that are not part of the ground plane
    extract.setInputCloud(cloud);
    extract.setIndices(inliers);
    extract.setNegative(true);
    extract.filter(*cloud_filtered);

    if (ground_clearance_ <= 0.0)
    {
        return cloud_filtered;
    }

    // Drop everything lower than ground_clearance_ above the fitted plane. Points just above the ground
    // survive the plane fit but bridge separate objects together during clustering.
    Eigen::Vector3f normal(coefficients->values[0], coefficients->values[1], coefficients->values[2]);
    float d = coefficients->values[3];
    float norm = normal.norm();
    if (norm <= 0.0f)
    {
        return cloud_filtered;
    }
    normal /= norm;
    d /= norm;

    // The sign of the plane equation is arbitrary, so orient it so that most remaining points sit above
    // the plane -- those are the objects.
    int above = 0;
    for (const auto &p : cloud_filtered->points)
    {
        if (normal.dot(p.getVector3fMap()) + d > 0.0f)
        {
            ++above;
        }
    }
    float sign = (above * 2 >= static_cast<int>(cloud_filtered->size())) ? 1.0f : -1.0f;

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_above(new pcl::PointCloud<pcl::PointXYZ>);
    cloud_above->reserve(cloud_filtered->size());
    for (const auto &p : cloud_filtered->points)
    {
        if (sign * (normal.dot(p.getVector3fMap()) + d) > ground_clearance_)
        {
            cloud_above->push_back(p);
        }
    }
    cloud_above->width = cloud_above->size();
    cloud_above->height = 1;
    cloud_above->is_dense = true;

    return cloud_above;
}


