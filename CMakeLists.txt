cmake_minimum_required(VERSION 3.18..3.20)

project(NumberOfIslands)

# find_package(boost REQUIRED)

add_executable(MyApp Solution.cpp main.cpp)

target_link_libraries(MyApp readline)