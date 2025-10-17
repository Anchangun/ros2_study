cmake_minimum_required(VERSION 3.8)
project(tutorial_01_first_tree)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(behaviortree_cpp_v3 REQUIRED)
find_package(ament_index_cpp REQUIRED)

include_directories(
	include
	include${PROJECT_NAME}
)
set(dependencies
	rclcpp
	behaviortree_cpp_v3
	ament_index_cpp	
)
set(node_name
	first_tree_node	
)
set(source_list
	src/first_tree.cpp	
)
add_executable(${node_name}
	${source_list}
)
target_link_libraries(${node_name}
	BT::behaviortree_cpp_v3
)

ament_target_dependencies(${node_name}
	${dependencies}
)
install(TARGETS
	${node_name}
	DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY behavior_tree
	DESTINATION share/${PROJECT_NAME}
	)	

ament_package()
