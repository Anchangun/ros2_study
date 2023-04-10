#ifndef EXECUTE_PUB
#define EXECUTE_PUB
// cpp header
#include <chrono>
#include <functional>
#include <memory>
#include <iostream>
#include <unistd.h>
// 
#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class thread_execute_pub : public rclcpp::Node{
    public : 
        thread_execute_pub(std::string );
        void timer_callback();
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    private :
        std::string pub_name;
};

#endif