cmake_minimum_required(VERSION 3.0.1)
project(fromENU2NED)
find_package (GeographicLib REQUIRED)
message(" GeographicLib_INCLUDE_DIRS= " ${GeographicLib_INCLUDE_DIRS})
message(" GeographicLib_LIBRARIES= " ${GeographicLib_LIBRARIES})

find_package(GeographicLib REQUIRED)
include_directories(${GeographicLib_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} fromENU2NED.cpp)
 
# 链接GeographicLib库（根据你的安装调整库名）
target_link_libraries( ${PROJECT_NAME} ${GeographicLib_LIBRARIES})