#include "thread_excute_test/thread_execute_main.hpp"
thread_execute_main::thread_execute_main():Node("thread_execute_main"){
    m_stop_one_flag = false;
    m_stop_two_flag =false;
    sub_msg_cb_group_one = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    sub_msg_cb_group_two = create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    rclcpp::SubscriptionOptions sub_one_options;
    rclcpp::SubscriptionOptions sub_two_options;
    sub_one_options.callback_group= sub_msg_cb_group_one;
    sub_two_options.callback_group= sub_msg_cb_group_two;
    sub_msg_one = this->create_subscription<std_msgs::msg::String>("test_one",10,std::bind(&thread_execute_main::fn_msg_one_callback,this,_1),sub_one_options);
    sub_msg_two = this->create_subscription<std_msgs::msg::String>("test_two",10,std::bind(&thread_execute_main::fn_msg_two_callback,this,_1),sub_two_options);

    std::thread thread_run(&thread_execute_main::fn_test,this);
    thread_run.detach();
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

void thread_execute_main::fn_test(){
    while(true){
        RCLCPP_INFO(this->get_logger(),"test : %s","Start");
        sleep(1);
    }
}


int main(int argc,char** argv){
    rclcpp::init(argc, argv);
    rclcpp::executors::MultiThreadedExecutor executor;
    auto node = std::make_shared<thread_execute_main>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}