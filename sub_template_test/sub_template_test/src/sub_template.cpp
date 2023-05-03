#include "sub_template_test/sub_template_test.hpp"
 SubTemplateTest::SubTemplateTest(): Node("minimal_subscriber"){
    subscription_ = this->create_subscription<rclcpp::SerializedMessage>(
      "topic", 10, std::bind(&SubTemplateTest::test_callback,
                             this,
                             std::placeholders::_1));
  }

  void SubTemplateTest::test_callback(const std::shared_ptr<rclcpp::SerializedMessage> msg){
        sub_template_msgs::msg::Test t;

        std_msgs::msg::String string_msg;
        auto buffer = msg->get_rcl_serialized_message();
        
        //uint32_t serialized_size = buffer.buffer_length;
        //(void)string_msg.deserialize(buffer.data(), serialized_size);
        for (size_t i = 0; i < buffer.buffer_length; ++i) {
            printf("%02X ", buffer.buffer[i]);
        }
  }

int main(int argc, char *argv[]){
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<SubTemplateTest>());
	rclcpp::shutdown();
	return 0;
}