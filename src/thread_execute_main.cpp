#include "thread_excute_test/thread_execute_main.hpp"
thread_execute_main::thread_execute_main():Node("thread_execute_main"){


}

void thread_execute_main::msg_one_callback(const std_msgs::msg::String::SharedPtr msg){
    while(true){
        RCLCPP_INFO(this->get_logger(),"msg_one_callback : %s",msg->data.c_str());
        sleep(100);
    }
}

void thread_execute_main::msg_two_callback(const std_msgs::msg::String::SharedPtr msg){
    while(true){
        RCLCPP_INFO(this->get_logger(),"msg_two_callback : %s",msg->data.c_str());
        sleep(100);
    }
}

int main(int argc,char** argv){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<thread_execute_main>());
    rclcpp::shutdown();
    return 0;
}