///
/// Region growing based point cloud segmentation following the tutorial:
/// http://www.pointclouds.org/documentation/tutorials/region_growing_segmentation.php
///

/// @file segmentationCommand.cpp
/// @details the implementation of the class SegmentationCommand
/// @author Bao Li

#include <pcl/PointIndices.h>
#include <pcl/point_types.h>
#include <pcl/search/search.h>
#include <pcl/search/kdtree.h>
#include <pcl/features/normal_3d.h>
#include <pcl/segmentation/region_growing.h>
#include <segmentationCommand.h>
#include <selection.h>
#include <cloud.h>

void
SegmentationCommand::execute ()
{
  Cloud3D temp_cloud;
  // segmentation
  // uses region growing to segment data: merging the points that are close enough in terms of the smoothness constraint.
  // For a more detailed explanation, see PCL's tutorial on segmentation:
  // http://www.pointclouds.org/documentation/tutorials/region_growing_segmentation.php

  //// back up the removed indices.
  //pcl::IndicesConstPtr indices_ptr = filter.getRemovedIndices();
  //std::vector<int>::const_iterator it;
  //for(it = indices_ptr->begin(); it != indices_ptr->end(); ++it)
  //  removed_indices_.addIndex(static_cast<unsigned int>(*it));
  //// back up the removed points.
  //removed_points_.set(cloud_ptr_, removed_indices_);
  //// remove the noisy points.
  //cloud_ptr_->remove(removed_indices_);
  //selection_ptr_->clear();

  pcl::search::Search<Point3D>::Ptr tree = boost::shared_ptr<pcl::search::Search<Point3D> >(new pcl::search::KdTree<Point3D>);
  pcl::PointCloud <pcl::Normal>::Ptr normals(new pcl::PointCloud <pcl::Normal>);
  pcl::NormalEstimation<Point3D, pcl::Normal> normal_estimator;
  normal_estimator.setSearchMethod(tree);
  normal_estimator.setInputCloud(cloud_ptr_->getInternalCloud().makeShared());
  normal_estimator.setKSearch(num_nbrs_normal_);
  normal_estimator.compute(*normals);

  pcl::RegionGrowing<Point3D, pcl::Normal> reg;
  reg.setMinClusterSize(min_cluster_size_);
  reg.setMaxClusterSize(max_cluster_size_);
  reg.setSearchMethod(tree);
  reg.setNumberOfNeighbours(num_nbrs_seg_);
  reg.setInputCloud(cloud_ptr_->getInternalCloud().makeShared());
  reg.setInputNormals(normals);
  reg.setSmoothnessThreshold(dev_normal_thresh_ / 180.0 * M_PI);
  reg.setCurvatureThreshold(dev_cur_thresh_);

  std::vector <pcl::PointIndices> clusters;
  reg.extract(clusters);

  if (clusters.size() == 0)
  {
	  qDebug() << "No segmentation occured." << clusters.size();
	  return;
  }

  qDebug() << "The number of clusters after segmentation" << clusters.size();
  std::string status = cloud_ptr_->getStat();
  qDebug() << "The info of original point cloud is:" << status.c_str();
  qDebug() << "The size of each cluster is: ";
  for (size_t i = 0; i < clusters.size(); i++)
	  qDebug() << clusters[i].indices.size() << " ";
  qDebug() << endl;

  pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = reg.getColoredCloud();

  for (size_t i_point = 0; i_point < cloud_ptr_->size(); i_point++)
  {
	  (*cloud_ptr_)[i_point].r = colored_cloud->at(i_point).r;
	  (*cloud_ptr_)[i_point].g = colored_cloud->at(i_point).g;
	  (*cloud_ptr_)[i_point].b = colored_cloud->at(i_point).b;
  }
  ////This is actually the internal code of pcl::RegionGrowing, help us to solve the R/B problem
  //srand(static_cast<unsigned int> (time(0)));
  //std::vector<unsigned char> colors;
  //for (size_t i_segment = 0; i_segment < clusters.size(); i_segment++)
  //{
	 // colors.push_back(static_cast<unsigned char> (rand() % 256));
	 // colors.push_back(static_cast<unsigned char> (rand() % 256));
	 // colors.push_back(static_cast<unsigned char> (rand() % 256));
  //}

  //for (size_t i_point = 0; i_point < cloud_ptr_->size(); i_point++)
  //{
	 // (*cloud_ptr_)[i_point].r = 0;
	 // (*cloud_ptr_)[i_point].g = 0;
	 // (*cloud_ptr_)[i_point].b = 255;
  //}

  //std::vector< pcl::PointIndices >::iterator i_segment;
  //int next_color = 0;
  //for (i_segment = clusters.begin(); i_segment != clusters.end(); i_segment++)
  //{
	 // std::vector<int>::iterator i_point;
	 // for (i_point = i_segment->indices.begin(); i_point != i_segment->indices.end(); i_point++)
	 // {
		//  int index;
		//  index = *i_point;
		//  (*cloud_ptr_)[index].r = colors[3 * next_color];
		//  (*cloud_ptr_)[index].g = colors[3 * next_color + 1];
		//  (*cloud_ptr_)[index].b = colors[3 * next_color + 2];
	 // }
	 // next_color++;
  //}
}

void
SegmentationCommand::undo ()
{
  cloud_ptr_->restore(removed_points_, removed_indices_);
}
