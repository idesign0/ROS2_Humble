cmake_minimum_required(VERSION 3.8)
project(irobot_create_ignition_plugins)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

set(OpenGL_GL_PREFERENCE LEGACY)

find_package(gz-gui9 QUIET)
find_package(gz-msgs11 QUIET)
find_package(gz-transport14 QUIET)
find_package(gz-plugin3 QUIET)

if(NOT gz-gui9_FOUND OR NOT gz-msgs11_FOUND OR NOT gz-transport14_FOUND OR NOT gz-plugin3_FOUND)
  message(WARNING "Gazebo (gz-gui9/gz-msgs11/gz-transport14/gz-plugin3) not found. Skipping ${PROJECT_NAME} package.")
  ament_package()
  return()
endif()

add_subdirectory(Create3Hmi)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
