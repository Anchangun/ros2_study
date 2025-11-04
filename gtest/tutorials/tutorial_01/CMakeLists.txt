cmake_minimum_required(VERSION 3.8)
project(tutorial_01)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_gtest REQUIRED)

ament_add_gtest(${PROJECT_NAME}_test test/tutorial_test.cpp)

ament_package()

