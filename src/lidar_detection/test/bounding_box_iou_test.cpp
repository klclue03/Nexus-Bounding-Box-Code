#include <gtest/gtest.h>

#include "bounding_box.hpp"

TEST(BoundingBoxIoUTest, ComputesExact3DOverlap) {
    Eigen::Vector4f min_a(0.0f, 0.0f, 0.0f, 1.0f);
    Eigen::Vector4f max_a(2.0f, 2.0f, 2.0f, 1.0f);
    Eigen::Vector4f min_b(1.0f, 1.0f, 1.0f, 1.0f);
    Eigen::Vector4f max_b(3.0f, 3.0f, 3.0f, 1.0f);

    const double iou = BoundingBox::computeBoxIoU(min_a, max_a, min_b, max_b);
    EXPECT_NEAR(iou, 1.0 / 15.0, 1e-6);
}

TEST(BoundingBoxIoUTest, IdenticalBoxesHaveIoU1) {
    Eigen::Vector4f min_a(0.0f, 0.0f, 0.0f, 1.0f);
    Eigen::Vector4f max_a(2.0f, 2.0f, 2.0f, 1.0f);

    const double iou = BoundingBox::computeBoxIoU(min_a, max_a, min_a, max_a);
    EXPECT_NEAR(iou, 1.0, 1e-6);
}
