cmake_minimum_required(VERSION 3.8)
project(my_robot_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/HardwareStatus.msg"
  "msg/LedStates.msg"
  "msg/Turtle.msg"
  "msg/TurtleArray.msg"
  "srv/ComputeRectangleArea.srv"
  "srv/SetLED.srv"
  "srv/Catch.srv"
  "action/CountUntil.action"
  "action/ReachUntil.action"
  "action/MoveTurtle.action"
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
