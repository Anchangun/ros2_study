#include "slam_goal_result.hpp"
int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    std::cout<<"hi"<<std::endl;
    rclcpp::spin(std::make_shared<SlamGoalResult>());
    rclcpp::shutdown();
    return 0;
}