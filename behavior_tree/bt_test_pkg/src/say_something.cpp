#include "behaviortree_cpp_v3/action_node.h"
#include <iostream>

class SaySomething : public BT::SyncActionNode
{
public:
  SaySomething(const std::string& name, const BT::NodeConfiguration& config)
      : BT::SyncActionNode(name, config) {}

  static BT::PortsList providedPorts()
  {
    return { BT::InputPort<std::string>("message"),
	    BT::InputPort<int>("number")};
  }

  BT::NodeStatus tick() override
  {
    auto msg = getInput<std::string>("message");
    auto num = getInput<int>("number");
    if (!msg)
    {
      throw BT::RuntimeError("missing required input [message]: ", msg.error());
    }
    if(!num){
      throw BT::RuntimeError("missing required input [number]: ",num.error());
    }

    std::cout << "SaySomething: " << " message: "<<msg.value() <<
    		" number "<< num.value() << std::endl;
    return BT::NodeStatus::SUCCESS;
  }
};

