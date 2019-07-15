#include "range_security_us.h"

IQR::RangeSecurityUs::RangeSecurityUs(ros::NodeHandle& n){

  n.param<double>("us_min_range", range_security, 0.3);
  n.param<std::string>("us_cmd_pub", topic_pub_, "us_cmd");
  n.param<std::string>("us1_cmd_id", us_id_[0], "ks106_us1");
  n.param<std::string>("us2_cmd_id", us_id_[1], "ks106_us2");
  n.param<std::string>("us3_cmd_id", us_id_[2], "ks106_us3");
  n.param<std::string>("us4_cmd_id", us_id_[3], "ks106_us4");
  ks106_pub_ = n.advertise<geometry_msgs::Twist>("ks106_cmd", 1);
  for(int i=0;i<4;i++) {
  ks106_sub_[i] = n.subscribe<sensor_msgs::Range>(us_id_[i], 10, &IQR::RangeSecurityUs::usCallback, this);
  }
}

void IQR::RangeSecurityUs::usCallback(const sensor_msgs::Range::ConstPtr &range) {
  geometry_msgs::Twist twist;
    if(range->range!=-1 && range->range<range_security) {
      twist.linear.x = 0;
      twist.angular.z = 0;
      ks106_pub_.publish(twist);
    }
}

