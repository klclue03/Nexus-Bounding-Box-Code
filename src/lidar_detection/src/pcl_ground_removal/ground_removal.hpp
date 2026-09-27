#ifndef GROUND_REMOVAL_HPP
#define GROUND_REMOVAL_HPP

#include <pcl/point_types.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/msg/point_cloud2.hpp>

class GroundRemoval
{
    public:
        // Constructor. Points within distance_threshold of the fitted plane are treated as ground, and
        // ground_clearance additionally drops anything lower than that height above the plane, which is
        // what keeps leftover floor points from linking separate objects into one cluster.
        GroundRemoval(double distance_threshold = 0.05, double ground_clearance = 0.0);

        // Function to remove ground
        pcl::PointCloud<pcl::PointXYZ>::Ptr removeGround(const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);

    private:
        pcl::SACSegmentation<pcl::PointXYZ> seg_;
        double ground_clearance_;
};

#endif // GROUND_REMOVAL_HPP