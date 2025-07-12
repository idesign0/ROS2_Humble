cmake_minimum_required(VERSION 3.8)
project(irobot_create_ignition_plugins)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

set(OpenGL_GL_PREFERENCE LEGACY)

# Find the Ignition gui library
find_package(ignition-common4 QUIET)

# Find tinyxml2 manually, since Homebrew doesn't export CMake targets
find_path(TINYXML2_INCLUDE_DIR tinyxml2.h PATHS /opt/homebrew/include)
find_library(TINYXML2_LIBRARY NAMES tinyxml2 PATHS /opt/homebrew/lib)

if(NOT TINYXML2_INCLUDE_DIR OR NOT TINYXML2_LIBRARY)
  message(FATAL_ERROR "Could not find TinyXML2")
endif()

add_library(tinyxml2_imported STATIC IMPORTED GLOBAL)
set_target_properties(tinyxml2_imported PROPERTIES
  IMPORTED_LOCATION "${TINYXML2_LIBRARY}"
  INTERFACE_INCLUDE_DIRECTORIES "${TINYXML2_INCLUDE_DIR}"
)

add_library(tinyxml2::tinyxml2 ALIAS tinyxml2_imported)

find_package(ignition-gazebo6 QUIET)

find_package(ignition-plugin1 QUIET)

if(NOT ignition-gazebo6_FOUND OR NOT ignition-common4_FOUND OR NOT ignition-plugin1_FOUND)
  message(WARNING "Ignition not found. Skipping ${PROJECT_NAME} package.")
  ament_package()
  return()
endif()

add_subdirectory(Create3Hmi)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
