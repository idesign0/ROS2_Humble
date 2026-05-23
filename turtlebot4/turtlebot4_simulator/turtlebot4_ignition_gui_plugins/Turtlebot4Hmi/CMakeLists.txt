cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

if(POLICY CMP0100)
  cmake_policy(SET CMP0100 NEW)
endif()

set(CMAKE_AUTOMOC ON)
set(OpenGL_GL_PREFERENCE LEGACY)

# Find Qt5
find_package(Qt5
  COMPONENTS
    Core
    Quick
    QuickControls2
  REQUIRED
)

# Find the Gazebo gui library (replaces ignition-gui6 in Harmonic)
find_package(tinyxml2 REQUIRED)
find_package(gz-gui8 REQUIRED)
find_package(gz-common5 REQUIRED)
find_package(gz-msgs10 REQUIRED)
find_package(gz-transport13 REQUIRED)

qt5_add_resources(resources_rcc Turtlebot4Hmi.qrc)

# Generate examples
add_library(Turtlebot4Hmi SHARED ${headers_MOC}
Turtlebot4Hmi.cc
  ${resources_rcc}
)
target_link_libraries(Turtlebot4Hmi
  gz-gui8::gz-gui8
  gz-common5::gz-common5
  gz-msgs10::gz-msgs10
  gz-transport13::gz-transport13
  ${Qt5Core_LIBRARIES}
  ${Qt5Qml_LIBRARIES}
  ${Qt5Quick_LIBRARIES}
  ${Qt5QuickControls2_LIBRARIES}
)

install(
  TARGETS Turtlebot4Hmi
  DESTINATION share/${PROJECT_NAME}/lib
)
