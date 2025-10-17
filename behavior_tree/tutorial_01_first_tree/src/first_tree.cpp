#include<iostream>
#include<behaviortree_cpp_v3/bt_factory.h>
#include<ament_index_cpp/get_package_share_directory.hpp>

// custom action node
class ApproachObject : public BT::SyncActionNode{
	public :
		ApproachObject(const std::string& name) : BT::SyncActionNode(name,{}){
		}
		BT::NodeStatus tick() override{
			std::cout <<"[Approach Object] : "<< this->name() <<'\n';
			return BT::NodeStatus::SUCCESS;
		}
};

// gripper interface
// We want to wrap into an ActionNode the methods open() and close()
class GripperInterface{
	public : 
		BT::NodeStatus open(){
			std::cout<< "[GripperInterface]::open"<<'\n';
			return BT::NodeStatus::SUCCESS;
		}

		BT::NodeStatus close(){
			std::cout<< "[GripperInterface]::close"<<'\n';
			return BT::NodeStatus::SUCCESS;
		}
};

// simple function 
BT::NodeStatus CheckBattery(BT::TreeNode&){
	std::cout<< "[Battery Func] : OK" <<'\n';
	return BT::NodeStatus::SUCCESS;
}

int main(){
	BT::BehaviorTreeFactory factory;

	std::string pkg_path = ament_index_cpp::get_package_share_directory("tutorial_01_first_tree");
	std::string xml_file = pkg_path+"/behavior_tree/my_tree.xml";
	std::cout << "Loading tree from: " << xml_file << '\n';

	factory.registerNodeType<ApproachObject>("ApproachObject");
	factory.registerSimpleCondition("CheckBattery",CheckBattery);

	GripperInterface gripper;
	factory.registerSimpleAction("OpenGripper",
			[&](BT::TreeNode&){
				return gripper.open();
			}		
	);

	factory.registerSimpleAction("CloseGripper",
			[&](BT::TreeNode&){
				return gripper.close();
			}		
	);

	auto tree = factory.createTreeFromFile(xml_file);
	tree.tickRootWhileRunning();
	
	return 0;
}

