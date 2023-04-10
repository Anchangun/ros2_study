#include "thread_excute_test/thread_execute_pub.hpp"

thread_execute_pub::thread_execute_pub(std::string pub_name) : Node("thread_execute_pub",rclcpp::NodeOptions().arguments({pub_name})){
    publisher_ = this->create_publisher<std_msgs::msg::String>(pub_name,10);
    timer_ = this->create_wall_timer(500ms,std::bind(&thread_execute_pub::timer_callback,this));
}

void thread_execute_pub::timer_callback(){
    auto message = std_msgs::msg::String();
    message.data = "Hello thead_executor";
    publisher_->publish(message);

}

int main(int argc,char** argv){
    rclcpp::init(argc,argv);
    std::string argv_temp = "topic"; // 초기 토픽 이름을 설정합니다.
    if (argc > 1) {
        argv_temp = argv[1]; // 터미널에서 입력받은 값을 이용해 토픽 이름을 설정합니다.
    }
    auto node = std::make_shared<thread_execute_pub>(argv_temp);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}