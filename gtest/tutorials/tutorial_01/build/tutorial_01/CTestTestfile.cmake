# CMake generated Testfile for 
# Source directory: /home/ubuntu/ros2_study/gtest/tutorials/tutorial_01
# Build directory: /home/ubuntu/ros2_study/gtest/tutorials/tutorial_01/build/tutorial_01
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(tutorial_01_test "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/ubuntu/ros2_study/gtest/tutorials/tutorial_01/build/tutorial_01/test_results/tutorial_01/tutorial_01_test.gtest.xml" "--package-name" "tutorial_01" "--output-file" "/home/ubuntu/ros2_study/gtest/tutorials/tutorial_01/build/tutorial_01/ament_cmake_gtest/tutorial_01_test.txt" "--command" "/home/ubuntu/ros2_study/gtest/tutorials/tutorial_01/build/tutorial_01/tutorial_01_test" "--gtest_output=xml:/home/ubuntu/ros2_study/gtest/tutorials/tutorial_01/build/tutorial_01/test_results/tutorial_01/tutorial_01_test.gtest.xml")
set_tests_properties(tutorial_01_test PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/ubuntu/ros2_study/gtest/tutorials/tutorial_01/build/tutorial_01/tutorial_01_test" TIMEOUT "60" WORKING_DIRECTORY "/home/ubuntu/ros2_study/gtest/tutorials/tutorial_01/build/tutorial_01" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/ubuntu/ros2_study/gtest/tutorials/tutorial_01/CMakeLists.txt;11;ament_add_gtest;/home/ubuntu/ros2_study/gtest/tutorials/tutorial_01/CMakeLists.txt;0;")
subdirs("gtest")
