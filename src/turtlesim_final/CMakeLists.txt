cmake_minimum_required(VERSION 3.8)
project(turtlesim_final)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(my_robot_interfaces REQUIRED)
find_package(rclcpp_action REQUIRED)

add_executable(final_project src/final_project.cpp)
ament_target_dependencies(final_project rclcpp turtlesim geometry_msgs my_robot_interfaces rclcpp_action)

install(TARGETS
  final_project
  DESTINATION lib/${PROJECT_NAME}/
)

ament_package()
