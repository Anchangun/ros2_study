#ifndef EXECUTE_MAIN
#define EXECUTE_MAIN
// cpp header
#include <memory>
#include <iostream>
#include <unistd.h>
// 
#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

class thread_execute_main : public rclcpp::Node{
    public : 
        thread_execute_main();
    private :
        void msg_one_callback(const std_msgs::msg::String::SharedPtr msg);
        void msg_two_callback(const std_msgs::msg::String::SharedPtr msg);
};

#endif
