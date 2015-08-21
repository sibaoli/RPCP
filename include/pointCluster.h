///
/// Point clusters which are subsets of the point cloud
///

/// @file pointCluster.h
/// @details the definition of the PointCluster
/// @author Bao Li

#ifndef POINT_CLUSTER_H_
#define POINT_CLUSTER_H_

#include <QtGui/QColor>
#include <common.h>
#include <localTypes.h>
#include <statistics.h>

class PointCluster : public Statistics
{
public:
	PointCluster();
	PointCluster(const PointCluster& copy);

	~PointCluster();

	PointCluster& operator= (const PointCluster& cluster);

	//default point display size and color of the cluster
	static const float DEFAULT_POINT_DISPLAY_SIZE_;
	static const float DEFAULT_POINT_DISPLAY_COLOR_RED_;
	static const float DEFAULT_POINT_DISPLAY_COLOR_GREEN_;
	static const float DEFAULT_POINT_DISPLAY_COLOR_BLUE_;

	void setRGB(float r, float g, float b)
	{
		color_[RED] = r;
		color_[GREEN] = g;
		color_[BLUE] = b;
	}
	void append(unsigned int id)
	{
		indices_.push_back(id);
	}
	const unsigned int operator[](unsigned int id) const
	{
		assert(index < indices_.size());
		return (indices_[id]);
	}

private:
	std::string name_;
	float color_[RGB];
	std::vector<unsigned int> indices_;
	float cluster_matrix_[MATRIX_SIZE];
	float point_size_;
};

#endif // POINT_CLUSTER_H_