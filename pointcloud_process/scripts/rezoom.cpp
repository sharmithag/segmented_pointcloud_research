#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <opencv2/opencv.hpp>
ros::Publisher pub;
cv_bridge::CvImagePtr cv_ptr;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
  // Convert the ROS image message to OpenCV format
  cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("cv::Exception caught in imageCallback function: %s", e.what());
    return;
  }
}

void cloudCallback(const sensor_msgs::PointCloud2ConstPtr& input)
{  

  // Convert the sensor_msgs/PointCloud2 data to pcl/PointCloud
  pcl::PointCloud<pcl::PointXYZRGB> cloud;
  pcl::fromROSMsg(*input, cloud);
  
  // Process the filtered point cloud and image data
  for(int i=0;i<cloud.size();i++){
  pcl::PointXYZRGB point = cloud[i];
  if(!isnan(point.x) and !isinf(point.x)){
  
  cv::Vec3b color = cv_ptr->image.at<cv::Vec3b>(point.y, point.x);
  // Vegetation color class
  if (color[2] == 107 and color[1] == 142 and color[0] == 35){
  cloud[i].y= cloud[i].y + 10;
  // ROS_INFO("vegetation");
  }
  }
    
  }
  
 

  // Convert the pcl/PointCloud data back to sensor_msgs/PointCloud2
  sensor_msgs::PointCloud2 pcl_output;
  pcl::toROSMsg(cloud, pcl_output);

  // Publish the processed point cloud
  pub.publish(pcl_output);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "point_cloud_image_processing");
  ros::NodeHandle nh;

  // Subscribe to the image topic
  ros::Subscriber sub_image = nh.subscribe<sensor_msgs::Image>("/segnet/color_mask", 1, imageCallback);

  // Subscribe to the input point cloud topic
  ros::Subscriber sub_cloud = nh.subscribe<sensor_msgs::PointCloud2>("/zed2i/zed_node/point_cloud/cloud_registered", 1, cloudCallback);

  // Advertise the output point cloud topic
  pub = nh.advertise<sensor_msgs::PointCloud2>("pcl_output", 1);
  ros::spin();

  return 0;
}
