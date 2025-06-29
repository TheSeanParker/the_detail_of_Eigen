cmake_minimum_required(VERSION 2.8)
project(Matrix3d_use)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

# add_executable(eigen_Matrixd eigen_Matrixd.cpp)
add_executable(print_Matrixd print_Matrixd.cpp)
