///
/// Region growing based point cloud segmentation following the tutorial:
/// http://www.pointclouds.org/documentation/tutorials/region_growing_segmentation.php
///

/// @file segmentationCommand.h
/// @details provides functionalities for segment the point cloud by region growing
/// @author Bao Li

#ifndef SEGMENTATION_COMMAND_H_
#define SEGMENTATION_COMMAND_H_

#include <command.h>
#include <localTypes.h>
#include <selection.h>
#include <copyBuffer.h>

class SegmentationCommand : public Command
{
public:
  /// @brief Constructor
  /// @param selection_ptr a shared pointer pointing to the selection object.
  /// @param cloud_ptr a shared pointer pointing to the cloud object.
  /// @param mean the number of points to use for mean distance estimation.
  /// @param threshold the standard deviation multiplier threshold
  SegmentationCommand (SelectionPtr selection_ptr, CloudPtr cloud_ptr,
                  int num_nbrs_normal, int min_cluster_size, int max_cluster_size, 
				  int num_nbrs_seg, float dev_normal, float dev_cur)
    : selection_ptr_(selection_ptr), cloud_ptr_(cloud_ptr), 
	  num_nbrs_normal_(num_nbrs_normal), min_cluster_size_(min_cluster_size), max_cluster_size_(max_cluster_size),
	  num_nbrs_seg_(num_nbrs_seg), dev_normal_thresh_(dev_normal), dev_cur_thresh_(dev_cur),
	  removed_indices_(cloud_ptr)
  {
  }

  /// @brief Destructor
  ~SegmentationCommand ()
  {
  }

protected:
  /// @brief Runs the denois algorithm to remove all the outliers.
  void
  execute ();

  /// @brief Adds the removed noisy points back to the cloud
  void
  undo ();

private:
  /// @brief Default Constructor
  SegmentationCommand () : removed_indices_(CloudPtr())
  {
  }

  /// @brief Copy constructor - commands are non-copyable
  SegmentationCommand (const SegmentationCommand&)
    : removed_indices_(CloudPtr())
  {
    assert(false);
  }

  /// @brief Equal operator - commands are non-copyable
  SegmentationCommand&
  operator= (const SegmentationCommand&)
  {
    assert(false); return (*this);
  }

  /// A shared pointer pointing to the selection object of the widget
  SelectionPtr selection_ptr_;

  /// A pointer pointing to the cloud of the widget
  CloudPtr cloud_ptr_;

  /// The number of neighbors for normal estimation
  int num_nbrs_normal_;
  /// The minimum cluster size
  int min_cluster_size_;
  /// The maximum cluster size
  int max_cluster_size_;
  /// The number of neighbors for region growing
  int num_nbrs_seg_;
  /// The normal deviation threshold
  float dev_normal_thresh_;
  /// The curvature deviation threshold
  float dev_cur_thresh_;

  /// A copy buffer which backs up the noisy point removed after denoising.
  CopyBuffer removed_points_;

  /// A selection object which backs up the indices of the noisy points removed.
  Selection removed_indices_;
};

#endif // SEGMENTATION_COMMAND_H_
