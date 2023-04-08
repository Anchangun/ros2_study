cmake_minimum_required(VERSION 3.5)
project(thread_excute_test)


# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
include_directories(
  include
  include/${PROJECT_NAME}
)
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(thread_execute_main src/thread_execute_main.cpp)
ament_target_dependencies(thread_execute_main std_msgs rclcpp)

add_executable(thread_execute_pub src/thread_execute_pub.cpp)
ament_target_dependencies(thread_execute_pub std_msgs rclcpp)

install(TARGETS thread_execute_main DESTINATION lib/${PRJOECT_NAME})
install(TARGETS thread_execute_pub DESTINATION lib/${PRJOECT_NAME})
ament_package()
