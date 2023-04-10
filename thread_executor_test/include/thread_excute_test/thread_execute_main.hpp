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
        std::thread m_thread_two;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_msg_one;
        rclcpp::CallbackGroup::SharedPtr sub_msg_cb_group_one;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_msg_two;
        rclcpp::CallbackGroup::SharedPtr sub_msg_cb_group_two;
        void fn_msg_one_callback(const std_msgs::msg::String::SharedPtr msg);
        void fn_msg_two_callback(const std_msgs::msg::String::SharedPtr msg);
        void fn_test();
        bool m_stop_one_flag;
        bool m_stop_two_flag;
};


#endif
