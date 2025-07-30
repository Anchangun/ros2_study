cmake_minimum_required(VERSION 3.8)
project(bt_test_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(behaviortree_cpp_v3 REQUIRED)
find_package(ament_index_cpp REQUIRED)

add_executable(bt_test
  src/main.cpp
)

target_include_directories(bt_test PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

ament_target_dependencies(bt_test
  rclcpp
  behaviortree_cpp_v3
  ament_index_cpp
)

install(TARGETS bt_test
  DESTINATION lib/${PROJECT_NAME}
)

# Install XML
install(DIRECTORY behavior_tree
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
