#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <boost/foreach.hpp>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>


class pcl_processor
{
  ros::NodeHandle nh_;

  typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

public:
  pcl_processor()
    : nh_
  {
    // Subscribe to segmented mask and zed_pointcloud
    message_filters::Subscriber<sensor_msgs::Image> image_sub(nh_,"/segnet/color_mask", 1);
    message_filters::Subscriber<PointCloud> pcl_sub(nh_,"/zed2i/zed_node/point_cloud/cloud_registered", 1);
    
    message_filters::TimeSynchronizer<Image, PointCloud> sync(image_sub, pcl_sub, 10);
    sync.registerCallback(boost::bind(&callback, _1, _2));
    //ros::Publisher pcl_pub = nh_.advertise<PointCloud> ("processed_points", 1);
  }

  ~pcl_processor()
  {
    
  }

  void callback(const sensor_msgs::ImageConstPtr& msg,const PointCloud::ConstPtr& msg2)
  {
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
    // Compare seg image and pointcloud
    int count = 0;
    for (int i =0; i< cv_ptr-> image.rows; i++){
    for (int j =0; j< cv_ptr->image.cols; j++){
    count = count +1
    if( (cv_ptr->image[i][j][0] ==107 && cv_ptr->image[i][j][1]== 142 && cv_ptr->image[i][j][2]== 35 && cv_ptr->image[i][j][3]== 255) || (cv_ptr->image[i][j][0] ==152 && cv_ptr->image[i][j][1]== 251 && cv_ptr->image[i][j][2]== 152 && cv_ptr->image[i][j][3]== 255)) {

   
    printf ("Cloud: width = %d, height = %d\n", msg2->width, msg2->height);
    BOOST_FOREACH (const pcl::PointXYZ& pt, msg2->points)
    printf ("\t(%f, %f, %f)\n", pt.x[count], pt.y[count], pt.z[count]);
    }}}
    
  }

};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "pcl_process");
  pcl_processor pp;
  ros::spin();
  return 0;
}
