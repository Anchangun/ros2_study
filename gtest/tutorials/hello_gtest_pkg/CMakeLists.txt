cmake_minimum_required(VERSION 3.8)
project(hello_gtest_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_gtest REQUIRED)

include_directories(include)

add_library(hello_lib src/calculator.cpp)

ament_add_gtest(test_calculator test/test_calculator.cpp)
target_link_libraries(test_calculator hello_lib)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
