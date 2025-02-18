cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(my_robot_interfaces REQUIRED)

#create executable
add_executable(cpp_node src/my_first_node.cpp)
ament_target_dependencies(cpp_node rclcpp)

add_executable(robot_radio_station src/robot_radio_station.cpp)
ament_target_dependencies(robot_radio_station rclcpp example_interfaces)

add_executable(smartphone src/smartphone.cpp)
ament_target_dependencies(smartphone rclcpp example_interfaces)

add_executable(hardwarestatus_pub src/hardwareStatus_pub)
ament_target_dependencies(hardwarestatus_pub rclcpp my_robot_interfaces)

add_executable(hardwarestatus_sub src/hardwarestatus_sub)
ament_target_dependencies(hardwarestatus_sub rclcpp my_robot_interfaces)

add_executable(client_battery src/battery_node)
ament_target_dependencies(client_battery rclcpp my_robot_interfaces)

add_executable(LED_panel src/LED_panel)
ament_target_dependencies(LED_panel rclcpp my_robot_interfaces)

# install in WS
install(TARGETS
cpp_node
robot_radio_station
smartphone
hardwarestatus_pub
hardwarestatus_sub
client_battery
LED_panel
DESTINATION lib/${PROJECT_NAME}
)

ament_package()
