///
/// Point clusters which are subsets of the point cloud
///

/// @file pointCluster.h
/// @details the definition of the PointCluster
/// @author Bao Li

#ifndef POINT_CLUSTER_H_
#define POINT_CLUSTER_H_

#include <QtGui/QColor>
#include <localTypes.h>
#include <statistics.h>

class PointCluster : public Statistics
{
public:
	PointCluster();

	PointCluster(const PointCluster& copy);

	~PointCluster();

	PointCluster& operator= (const PointCluster& cluster);
private:
	std::string name_;
	float color_[RGB];
	std::vector<unsigned int> indices;
};

#endif // POINT_CLUSTER_H_