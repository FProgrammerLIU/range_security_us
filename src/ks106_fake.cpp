#include "ros/ros.h"
#include "sensor_msgs/Range.h"
#include "std_msgs/String.h"
int main(int argc, char *argv[])
{
  ros::init(argc, argv, "dauxi_ks106_cmd_fake");
  ros::NodeHandle n;
  ros::Publisher fake_pub_1 = n.advertise<sensor_msgs::Range>("ks106_us1", 1);  
  ros::Publisher fake_pub_2 = n.advertise<sensor_msgs::Range>("ks106_us2", 1);  
  ros::Publisher fake_pub_3 = n.advertise<sensor_msgs::Range>("ks106_us3", 1);  
  ros::Publisher fake_pub_4 = n.advertise<sensor_msgs::Range>("ks106_us4", 1);  

  ros::Rate loop_pub(10);
  while(true) {
    sensor_msgs::Range range_ks_fake1;
    range_ks_fake1.header.frame_id = "111111";
    range_ks_fake1.range = -1.0;
    fake_pub_1.publish(range_ks_fake1);
    
    sensor_msgs::Range range_ks_fake2;
    range_ks_fake2.header.frame_id = "22222";
    range_ks_fake2.range = 1.0;
    fake_pub_2.publish(range_ks_fake2);
   
    sensor_msgs::Range range_ks_fake3;
    range_ks_fake3.range = 0.25;
    range_ks_fake3.header.frame_id = "333333";
    fake_pub_3.publish(range_ks_fake3);
    
    sensor_msgs::Range range_ks_fake4;
    range_ks_fake4.range = 0.3;
    range_ks_fake4.header.frame_id = "4444444";
    fake_pub_4.publish(range_ks_fake4);
    loop_pub.sleep();
}
  return 0;
}