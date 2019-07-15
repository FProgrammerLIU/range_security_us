#include "ros/ros.h"
#include "sensor_msgs/Range.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
namespace IQR {
  class RangeSecurityUs
  {
  public:
    RangeSecurityUs(ros::NodeHandle& n);
  private:
    void usCallback(const sensor_msgs::Range::ConstPtr &range); 
    ros::Publisher ks106_pub_, fake_pub_;
    ros::Subscriber ks106_sub_[4];
    std::string us_id_[4], topic_pub_, us_cmd_id_;
    double range_security;
  };
}