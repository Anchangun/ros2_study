#include "behaviortree_cpp_v3/bt_factory.h"
#include "ament_index_cpp/get_package_share_directory.hpp"
#include "say_something.cpp"

int main()
{
  BT::BehaviorTreeFactory factory;
  factory.registerNodeType<SaySomething>("SaySomething");

  auto blackboard = BT::Blackboard::create();
  blackboard->set("my_message", "Hello from Blackboard!");
  blackboard->set("my_number",0);

  std::string pkg_path = ament_index_cpp::get_package_share_directory("bt_test_pkg");
  std::string xml_path = pkg_path + "/behavior_tree/bt_test.xml";

  auto tree = factory.createTreeFromFile(xml_path, blackboard);

  tree.tickRootWhileRunning();

  return 0;
}

