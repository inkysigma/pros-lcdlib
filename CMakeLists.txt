cmake_minimum_required(VERSION 3.6)
project(lcdTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/API.h
    include/main.h
    lib/lcd/lcd.cpp
    lib/lcd/lcd.h
    lib/lcd/lcdcore.h
    lib/lcd/lcdSelectMenu.h
    lib/lcd/menuPanel.h
    lib/lcd/navigateCallback.cpp
    lib/lcd/panel.cpp
    lib/lcd/selectMenu.cpp
    lib/lcd/selectorCallback.cpp
    lib/lcd/selectorPanel.cpp
    lib/lcd/voidCallback.cpp
    src/auto.cpp
    src/init.cpp
    src/opcontrol.cpp)

include_directories(include)

add_executable(lcdTest ${SOURCE_FILES})