cmake_minimum_required(VERSION 2.8)
project( Canny_edge)
find_package( OpenCV REQUIRED )
add_executable( Canny_edge canny_edge.cpp )
target_link_libraries( Canny_edge ${OpenCV_LIBS} )
