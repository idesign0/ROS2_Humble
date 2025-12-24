cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
cmake_policy(SET CMP0100 NEW)

project(Turtlebot4Hmi LANGUAGES CXX)

# ------------------------------------------------------------
# Qt setup
# ------------------------------------------------------------
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# ------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------
find_package(Qt5 REQUIRED COMPONENTS
  Core
  Quick
  QuickControls2
)

find_package(tinyxml2 REQUIRED)
find_package(gz-gui9 REQUIRED)
find_package(gz-common6 REQUIRED)

# ------------------------------------------------------------
# Plugin library
# ------------------------------------------------------------
add_library(Turtlebot4Hmi SHARED
  Turtlebot4Hmi.cc
  Turtlebot4Hmi.hh
  Turtlebot4Hmi.qrc
)

# ------------------------------------------------------------
# Compile settings
# ------------------------------------------------------------
target_compile_features(Turtlebot4Hmi PRIVATE cxx_std_17)

# ------------------------------------------------------------
# Link libraries (TARGET-BASED, NO GLOBAL VARIABLES)
# ------------------------------------------------------------
target_link_libraries(Turtlebot4Hmi
  Qt5::Core
  Qt5::Quick
  Qt5::QuickControls2

  gz-gui9::gz-gui9
  gz-common6::gz-common6
)

# ------------------------------------------------------------
# Install location (REQUIRED for gz gui plugins)
# ------------------------------------------------------------
install(
  TARGETS Turtlebot4Hmi
  LIBRARY DESTINATION lib/gz/gui/plugins
)
