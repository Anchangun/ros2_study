#ifndef EXECUTE_MAIN
#define EXECUTE_MAIN
// cpp header
#include <memory>
#include <iostream>
#include <unistd.h>
#include <signal.h>
// 
#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"
using std::placeholders::_1;

class thread_execute_main : public rclcpp::Node{
    public : 
        thread_execute_main();
    private :
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_msg_one;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_msg_two;
        void msg_one_callback(const std_msgs::msg::String::SharedPtr msg);
        void msg_two_callback(const std_msgs::msg::String::SharedPtr msg);
};


#endif
