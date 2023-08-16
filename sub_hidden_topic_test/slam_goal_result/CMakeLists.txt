cmake_minimum_required(VERSION 3.5)
project(slam_goal_result)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(action_msgs REQUIRED)
include_directories(
  include
  include/${PROJECT_NAME}
  #${EXTERNAL_INCLUDE_DIRS}
)


add_executable(slam_goal_result_node 
  src/main.cpp
  src/slam_goal_result.cpp
)
ament_target_dependencies(slam_goal_result_node 
rclcpp 
std_msgs 
action_msgs
)
install(TARGETS
  slam_goal_result_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
