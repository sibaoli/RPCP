///
/// Point clusters which are subsets of the point cloud
///

/// @file pointCluster.h
/// @details the definition of the PointCluster
/// @author Bao Li

#include <pointCluster.h>

const float PointCluster::DEFAULT_POINT_DISPLAY_SIZE_ = 2.0f;
const float PointCluster::DEFAULT_POINT_DISPLAY_COLOR_RED_ = 1.0f;
const float PointCluster::DEFAULT_POINT_DISPLAY_COLOR_GREEN_ = 1.0f;
const float PointCluster::DEFAULT_POINT_DISPLAY_COLOR_BLUE_ = 1.0f;

PointCluster::PointCluster()
{
	name_ = "unknown";
	point_size_ = DEFAULT_POINT_DISPLAY_SIZE_;
	color_[RED] = DEFAULT_POINT_DISPLAY_COLOR_RED_;
	color_[GREEN] = DEFAULT_POINT_DISPLAY_COLOR_GREEN_;
	color_[BLUE] = DEFAULT_POINT_DISPLAY_COLOR_BLUE_;
	indices_.resize(0);
	setIdentity(cluster_matrix_);
}

PointCluster::PointCluster(const PointCluster& other) : name_(other.name_), point_size_(other.point_size_)
{
	indices_.resize(other.indices_.size());
	std::copy(other.indices_.begin(), other.indices_.end(), indices_.begin());
	std::copy(other.cluster_matrix_, other.cluster_matrix_ + MATRIX_SIZE, cluster_matrix_);
	std::copy(other.color_, other.color_ + RGB, color_);
}

PointCluster& PointCluster::operator= (const PointCluster& other)
{
	name_ = other.name_;
	point_size_ = other.point_size_;
	indices_.resize(other.indices_.size());
	std::copy(other.indices_.begin(), other.indices_.end(), indices_.begin());
	std::copy(other.cluster_matrix_, other.cluster_matrix_ + MATRIX_SIZE, cluster_matrix_);
	std::copy(other.color_, other.color_ + RGB, color_);
	return *this;
}


PointCluster::~PointCluster()
{

}