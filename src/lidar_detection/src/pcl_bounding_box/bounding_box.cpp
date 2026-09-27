#include "bounding_box.hpp"

// Compute the intersection-over-union (IoU) for two 3D axis-aligned boxes.
double BoundingBox::computeBoxIoU(
    const Eigen::Vector4f &min_a,
    const Eigen::Vector4f &max_a,
    const Eigen::Vector4f &min_b,
    const Eigen::Vector4f &max_b)
{
    const Eigen::Vector3f min_a_3 = min_a.head<3>();
    const Eigen::Vector3f max_a_3 = max_a.head<3>();
    const Eigen::Vector3f min_b_3 = min_b.head<3>();
    const Eigen::Vector3f max_b_3 = max_b.head<3>();

    const Eigen::Vector3f overlap_min = min_a_3.cwiseMax(min_b_3);
    const Eigen::Vector3f overlap_max = max_a_3.cwiseMin(max_b_3);
    const Eigen::Vector3f overlap_size = overlap_max - overlap_min;

    const float intersection_volume = std::max(0.0f, overlap_size.x()) *
                                     std::max(0.0f, overlap_size.y()) *
                                     std::max(0.0f, overlap_size.z());

    const float box_a_size_x = std::max(0.0f, max_a_3.x() - min_a_3.x());
    const float box_a_size_y = std::max(0.0f, max_a_3.y() - min_a_3.y());
    const float box_a_size_z = std::max(0.0f, max_a_3.z() - min_a_3.z());
    const float box_b_size_x = std::max(0.0f, max_b_3.x() - min_b_3.x());
    const float box_b_size_y = std::max(0.0f, max_b_3.y() - min_b_3.y());
    const float box_b_size_z = std::max(0.0f, max_b_3.z() - min_b_3.z());

    const float union_volume = (box_a_size_x * box_a_size_y * box_a_size_z) +
                              (box_b_size_x * box_b_size_y * box_b_size_z) -
                              intersection_volume;

    if (union_volume <= 0.0f)
    {
        return 0.0;
    }

    return static_cast<double>(intersection_volume) / static_cast<double>(union_volume);
}

// Helper function to create the corners of the cube
std::vector<geometry_msgs::msg::Point> BoundingBox::createCubeCorners(const Eigen::Vector4f &min_point, const Eigen::Vector4f &max_point)
{
    std::vector<geometry_msgs::msg::Point> corners(8);

    corners[0].x = min_point.x();
    corners[0].y = min_point.y();
    corners[0].z = min_point.z();

    corners[1].x = max_point.x();
    corners[1].y = min_point.y();
    corners[1].z = min_point.z();

    corners[2].x = max_point.x();
    corners[2].y = max_point.y();
    corners[2].z = min_point.z();

    corners[3].x = min_point.x();
    corners[3].y = max_point.y();
    corners[3].z = min_point.z();

    corners[4].x = min_point.x();
    corners[4].y = min_point.y();
    corners[4].z = max_point.z();

    corners[5].x = max_point.x();
    corners[5].y = min_point.y();
    corners[5].z = max_point.z();

    corners[6].x = max_point.x();
    corners[6].y = max_point.y();
    corners[6].z = max_point.z();

    corners[7].x = min_point.x();
    corners[7].y = max_point.y();
    corners[7].z = max_point.z();

    return corners;
}

// Create a bounding box marker using LINE_LIST
visualization_msgs::msg::Marker BoundingBox::createBoundingBoxMarker(
    const pcl::PointCloud<pcl::PointXYZ>::Ptr &cluster,
    const std_msgs::msg::Header &header,
    int id)
{
    // Compute the bounding box for the cluster
    Eigen::Vector4f min_point, max_point;
    pcl::getMinMax3D(*cluster, min_point, max_point);

    // Create a marker
    visualization_msgs::msg::Marker marker;
    marker.header = header;
    marker.ns = "bounding_box";
    marker.id = id;
    marker.type = visualization_msgs::msg::Marker::LINE_LIST;
    marker.action = visualization_msgs::msg::Marker::ADD;
    marker.scale.x = 0.02; // Line width

    // Set marker color
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0f;

    // Get the corners of the bounding box
    std::vector<geometry_msgs::msg::Point> corners = createCubeCorners(min_point, max_point);

    // Add line segments (12 lines to form a cube)
    std::vector<std::pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}, // Bottom square
        {4, 5}, {5, 6}, {6, 7}, {7, 4}, // Top square
        {0, 4}, {1, 5}, {2, 6}, {3, 7}  // Connecting edges
    };

    for (const auto &edge : edges)
    {
        marker.points.push_back(corners[edge.first]);
        marker.points.push_back(corners[edge.second]);
    }

    return marker;
}
