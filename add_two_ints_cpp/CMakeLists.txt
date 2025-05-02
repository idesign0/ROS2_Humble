cmake_minimum_required(VERSION 3.8)
project(add_two_ints_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

#execuatables
add_executable(add_two_ints_server_cpp src/add_two_ints_server.cpp)
ament_target_dependencies(add_two_ints_server_cpp rclcpp example_interfaces)

add_executable(add_two_ints_client_no_oop src/add_two_ints_client_no_oop.cpp)
ament_target_dependencies(add_two_ints_client_no_oop rclcpp example_interfaces)


add_executable(add_two_ints_client src/add_two_ints_client.cpp)
ament_target_dependencies(add_two_ints_client rclcpp example_interfaces)

#install
install(TARGETS
add_two_ints_server_cpp
add_two_ints_client_no_oop
add_two_ints_client
DESTINATION lib/${PROJECT_NAME})

ament_package()
