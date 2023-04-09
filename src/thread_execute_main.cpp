#include "thread_excute_test/thread_execute_main.hpp"
thread_execute_main::thread_execute_main():Node("thread_execute_main"){
    m_stop_one_flag = false;
    m_stop_two_flag =false;
}
void thread_execute_main::fn_thread_ready_one(){
    sub_msg_one = this->create_subscription<std_msgs::msg::String>("test_one",10,std::bind(&thread_execute_main::fn_msg_one_callback,this,_1));
}
void thread_execute_main::fn_thread_ready_two(){
    sub_msg_two = this->create_subscription<std_msgs::msg::String>("test_two",10,std::bind(&thread_execute_main::fn_msg_two_callback,this,_1));
}

void thread_execute_main::fn_msg_one_callback(const std_msgs::msg::String::SharedPtr msg){
    RCLCPP_INFO(this->get_logger(),"fn_msg_one_callback : %s","Start");
    while(!m_stop_one_flag){
        RCLCPP_INFO(this->get_logger(),"fn_msg_one_callback : %s",msg->data.c_str());
        sleep(1);
        signal(SIGINT,SIG_DFL);
      
    }
}

void thread_execute_main::fn_msg_two_callback(const std_msgs::msg::String::SharedPtr msg){
    RCLCPP_INFO(this->get_logger(),"fn_msg_two_callback : %s","Start");
    while(!m_stop_two_flag){
        RCLCPP_INFO(this->get_logger(),"fn_msg_two_callback : %s",msg->data.c_str());
        sleep(1);
        signal(SIGINT,SIG_DFL);
 
    }
}

void thread_execute_main::fn_thread_run() {
    m_thread_one = std::thread(&thread_execute_main::fn_thread_ready_one, this);
    m_thread_two = std::thread(&thread_execute_main::fn_thread_ready_two, this);
}

int main(int argc,char** argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<thread_execute_main>();
    node->fn_thread_run();
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    /*
    rclcpp::executors::MultiThreadedExecutor executor;
    auto node = std::make_shared<thread_execute_main>();
    executor.add_node(node);
    executor.spin();
    */
    rclcpp::shutdown();
    return 0;
}