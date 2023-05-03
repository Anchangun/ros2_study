cmake_minimum_required(VERSION 3.5)
project(sub_template_test)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

include_directories(
  include
  include/${PROJECT_NAME}
)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sub_template_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rosidl_typesupport_cpp REQUIRED)  # rosidl_typesupport_cpp 패키지 추가

add_executable(sub_template_test src/sub_template.cpp)
ament_target_dependencies(sub_template_test
  std_msgs
  rclcpp
  sub_template_msgs
)

rosidl_target_interfaces(sub_template_test ${PROJECT_NAME} "rosidl_typesupport_cpp")

install(TARGETS sub_template_test DESTINATION lib/${PROJECT_NAME})
ament_package()
