cmake_minimum_required(VERSION 3.19)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(TicTacToe main.cpp MainClass.cpp MainClass.h Frame.cpp Frame.h)
target_link_libraries(TicTacToe ${wxWidgets_LIBRARIES})