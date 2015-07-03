///
/// Region growing based point cloud segmentation following the tutorial:
/// http://www.pointclouds.org/documentation/tutorials/region_growing_segmentation.php
///

/// @file segmentationCommand.cpp
/// @details the implementation of the class SegmentationCommand
/// @author Bao Li

#include <segmentationParameterForm.h>

SegmentationParameterForm::SegmentationParameterForm() : ok_(false)
{
	num_nbrs_normal_line_ = new QLineEdit(tr("20"));
	min_cluster_size_line_ = new QLineEdit(tr("50"));
	max_cluster_size_line_ = new QLineEdit(tr("1000"));
	num_nbrs_seg_line_ = new QLineEdit(tr("20"));
	dev_normal_thresh_line_ = new QLineEdit(tr("3.0"));
	dev_cur_thresh_line_ = new QLineEdit(tr("1.0"));
	button_box_ = new QDialogButtonBox;
	button_box_->addButton(tr("Cancel"),
		QDialogButtonBox::RejectRole);
	button_box_->addButton(tr("OK"),
		QDialogButtonBox::AcceptRole);
	connect(button_box_, SIGNAL(accepted()),
		this, SLOT(accept()));
	connect(button_box_, SIGNAL(rejected()),
		this, SLOT(reject()));
	layout_ = new QFormLayout;
	layout_->addRow(tr("&Number of Neighbors for Normal Estimation:"), num_nbrs_normal_line_);
	layout_->addRow(tr("&Minimum Size of Cluster:"), min_cluster_size_line_);
	layout_->addRow(tr("&Maximum Size of Cluster:"), max_cluster_size_line_);
	layout_->addRow(tr("&Number of Neigbors for Region Growing:"), num_nbrs_seg_line_);
	layout_->addRow(tr("&Threshold of Normal Deviation:"), dev_normal_thresh_line_);
	layout_->addRow(tr("&Curvature Threshold:"), dev_cur_thresh_line_);

	main_layout_ = new QVBoxLayout;
	main_layout_->addLayout(layout_);
	main_layout_->addWidget(button_box_);
	setLayout(main_layout_);
	setWindowTitle(tr("Segmentation Parameters"));
}

SegmentationParameterForm::~SegmentationParameterForm()
{
	delete num_nbrs_normal_line_;
	delete min_cluster_size_line_;
	delete max_cluster_size_line_;
	delete num_nbrs_seg_line_;
	delete dev_normal_thresh_line_;
	delete dev_cur_thresh_line_;
	delete button_box_;
	delete layout_;
	delete main_layout_;
}

void
SegmentationParameterForm::accept()
{
	bool ok;
	num_nbrs_normal_ = num_nbrs_normal_line_->text().toInt(&ok);
	// validates the input.
	if (!ok)
	{
		ok_ = false;
		return;
	}
	min_cluster_size_ = min_cluster_size_line_->text().toInt(&ok);
	// validates the input.
	if (!ok)
	{
		ok_ = false;
		return;
	}
	max_cluster_size_ = max_cluster_size_line_->text().toInt(&ok);
	// validates the input.
	if (!ok)
	{
		ok_ = false;
		return;
	}
	num_nbrs_seg_ = num_nbrs_seg_line_->text().toInt(&ok);
	// validates the input.
	if (!ok)
	{
		ok_ = false;
		return;
	}
	dev_normal_thresh_ = dev_normal_thresh_line_->text().toFloat(&ok);
	// validates the input.
	if (!ok)
	{
		ok_ = false;
		return;
	}
	dev_cur_thresh_ = dev_cur_thresh_line_->text().toFloat(&ok);
	// validates the input.
	if (!ok)
	{
		ok_ = false;
		return;
	}
	this->done(0);
	ok_ = true;
}

void
SegmentationParameterForm::reject()
{
	ok_ = false;
	this->done(0);
}

