#include "slam_goal_result/slam_goal_result.hpp"
#include <vector>
#include <stdio.h>
using std::placeholders::_1;
SlamGoalResult::SlamGoalResult():Node("slam_goal_result"){
    sub_goal_result_ = this->create_subscription<action_msgs::msg::GoalStatusArray>("/navigate_to_pose/_action/status",1,std::bind(&SlamGoalResult::goal_result_callback,this,_1));
	
}

void SlamGoalResult::goal_result_callback(const action_msgs::msg::GoalStatusArray::SharedPtr status){
    std::cout<<"test "<<'\n';
       int data_int = static_cast<int>( status->status_list.back().status);

    // int8_t 데이터를 %x 포맷으로 출력
    std::cout << "int8_t data in hexadecimal: " << std::hex << static_cast<int>(data_int) << std::endl;


    std::cout<< status->status_list.back().status<< "  "<<status->status_list[status->status_list.size()-1].status<< "  "<<data_int <<'\n';
    std::cout<<"for : ";
    for (auto iter : status->status_list) {
        //std::cout << iter.status <<" ";
        printf("%x ",iter.status);
    }
    std::cout<<'\n';
}