cmake_minimum_required( VERSION 2.8 )
project( geometry )

# 添加Eigen头文件
include_directories( "/usr/include/eigen3" )
add_executable(quanternion_coeffs quanternion_coeffs.cpp )
# add_executable( eigenGeometry eigenGeometry.cpp )
