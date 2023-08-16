#ifndef SLAM__SLAM_GOAL_RESULT__HPP_
#define SLAM__SLAM_GOAL_RESULT__HPP_
#include <iostream>
#include "rclcpp/rclcpp.hpp"
//#include "rclcpp_action/rclcpp_action.hpp"
//#include "actionlib_msgs/msg/goal_status_array.hpp"
#include "action_msgs/msg/goal_status_array.hpp"
#include <memory.h>
class SlamGoalResult : public rclcpp::Node{
    private :
        rclcpp::Subscription<action_msgs::msg::GoalStatusArray>::SharedPtr sub_goal_result_;

    public :
        SlamGoalResult();
        void goal_result_callback(const action_msgs::msg::GoalStatusArray::SharedPtr status);

};

#endif