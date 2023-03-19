cmake_minimum_required(VERSION 3.24)
project(cpp_stopwatch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(cpp_stopwatch main.cpp mainwindow.cpp mainwindow.h mainwindow.ui)
target_link_libraries(cpp_stopwatch
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

