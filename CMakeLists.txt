cmake_minimum_required(VERSION 3.12)
project(Metronome)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp Ticker.cpp Ticker.h MainWindow.cpp MainWindow.h Timer.cpp Timer.h)


#set(CMAKE_AUTOUIC ON) # if you have any .ui files
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui Multimedia)


# Add the include directories for the Qt 5 Widgets module to
# the compile lines.

include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Multimedia_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Gui_INCLUDE_DIRS})

add_executable(Metronome ${SOURCE_FILES} )
target_link_libraries(Metronome Qt5::Gui Qt5::Core Qt5::Widgets Qt5::Multimedia)

