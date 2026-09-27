#ifndef BOUNDING_BOX_HPP
#define BOUNDING_BOX_HPP

#include <vector>

#include <pcl/point_types.h>
#include <pcl/common/common.h>
#include <visualization_msgs/msg/marker.hpp>

class BoundingBox
{
public:
    BoundingBox() = default;

    static double computeBoxIoU(
        const Eigen::Vector4f &min_a,
        const Eigen::Vector4f &max_a,
        const Eigen::Vector4f &min_b,
        const Eigen::Vector4f &max_b);

    // Function to compute a bounding box marker for a given cluster
    visualization_msgs::msg::Marker createBoundingBoxMarker(
        const pcl::PointCloud<pcl::PointXYZ>::Ptr &cluster,
        const std_msgs::msg::Header &header,
        int id);

private:
    std::vector<geometry_msgs::msg::Point> createCubeCorners(const Eigen::Vector4f &min_point, const Eigen::Vector4f &max_point);
};

#endif // BOUNDING_BOX_HPP
