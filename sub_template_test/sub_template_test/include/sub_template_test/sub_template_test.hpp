#ifndef SUB_TEMPLATE_TEST__HPP_
#define SUB_TEMPLATE_TEST__HPP_
#include "rclcpp/rclcpp.hpp"
#include <iostream>
#include <memory>
#include "rclcpp/serialized_message.hpp"
#include "sub_template_msgs/msg/test.hpp"
#include "std_msgs/msg/string.hpp"
class SubTemplateTest : public rclcpp::Node
{
public:
  SubTemplateTest();
private:
  void test_callback(const std::shared_ptr<rclcpp::SerializedMessage> msg);

  rclcpp::Subscription<rclcpp::SerializedMessage>::SharedPtr subscription_;
};


#endif