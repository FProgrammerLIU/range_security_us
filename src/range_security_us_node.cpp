#include "range_security_us.h"

int main(int argc, char** argv) {

    ros::init(argc, argv, "range_security_us");
    ros::NodeHandle node_us;
    IQR::RangeSecurityUs rangeSecurityUs(node_us);
    ros::spin();
}