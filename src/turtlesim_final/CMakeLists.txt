cmake_minimum_required(VERSION 3.8)
project(turtlesim_final)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(turtlesim REQUIRED)

add_executable(final_project src/final_project.cpp)
ament_target_dependencies(final_project rclcpp turtlesim)

install(TARGETS
  final_project
  DESTINATION lib/${PROJECT_NAME}/
)

ament_package()
