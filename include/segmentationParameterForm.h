///
/// Region growing based point cloud segmentation following the tutorial:
/// http://www.pointclouds.org/documentation/tutorials/region_growing_segmentation.php
///

/// @file segmentationCommand.cpp
/// @details the implementation of the class SegmentationCommand
/// @author Bao Li

#ifndef SEGMENTATION_PARAMETER_FORM_H_
#define SEGMENTATION_PARAMETER_FORM_H_

#include <QLineEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLineEdit>

class SegmentationParameterForm : public QDialog
{
  Q_OBJECT

  public:
    /// @brief Default Constructor
    SegmentationParameterForm();

    /// @brief Destructor
	~SegmentationParameterForm();

    /// @brief Returns the number of nbrs for normal estimation
    inline
    float
    getNumNbrsNormal () const
    {
		return (num_nbrs_normal_);
    }

    /// @brief Returns the minimum numbers of cluster
    inline
    float
    getMinClusterSize () const
    {
		return (min_cluster_size_);
    }

	/// @brief Returns the maximum numbers of cluster
	inline
		float
		getMaxClusterSize() const
	{
			return (max_cluster_size_);
		}

	/// @brief Returns the number of nbrs for region growing
	inline
		float
		getNumNbrsSeg() const
	{
			return (num_nbrs_seg_);
		}

	/// @brief Returns the threshold of normal deviation
	inline
		float
		getDevNormalThresh() const
	{
			return (dev_normal_thresh_);
		}

	/// @brief Returns the threshold of curvature deviation
	inline
		float
		getDevCurThresh() const
	{
			return (dev_cur_thresh_);
		}

    /// @brief Checks whether the OK button was pressed.
    inline
    bool
    ok () const
    {
      return (ok_);
    }

  private slots:
    /// @brief Accepts and stores the current user inputs, and turns off the
    /// dialog box.
    void
    accept ();

    /// @brief Rejects the current inputs, and turns off the dialog box.
    void
    reject ();

  private:
    /// The line for entering the number of neighbors for estimating normal
    QLineEdit *num_nbrs_normal_line_;
    /// The line for entering the threshold for the minimum size of a cluster
    QLineEdit *min_cluster_size_line_;
	/// The line for entering the threshold for the maximum size of a cluster
	QLineEdit *max_cluster_size_line_;
	/// The line for entering the number of neighbors for region growing
	QLineEdit *num_nbrs_seg_line_;
	/// The line for entering the threshold for deviation of normal
	QLineEdit *dev_normal_thresh_line_;
	/// The line for entering the threshold for the minimum size of a cluster
	QLineEdit *dev_cur_thresh_line_;
    /// The button box.
    QDialogButtonBox *button_box_;
    /// The layout of the two input QLineEdit objects
    QFormLayout *layout_;
    /// The main layout for the dialog
    QVBoxLayout* main_layout_;
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
    /// The flag indicating whether the OK button was pressed
    bool ok_;
};

#endif // SEGMENTATION_PARAMETER_FORM_H_
