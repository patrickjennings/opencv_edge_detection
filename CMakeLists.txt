cmake_minimum_required(VERSION 3.10)
project(edge_detector)

set(CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(edge_detector src/main.cpp src/ImageEdgeDetection.cpp src/ImageEdgeDetection.h src/DisplayWindow.cpp src/DisplayWindow.h src/Image.cpp src/Image.h src/CannyConfiguration.cpp src/CannyConfiguration.h)

target_link_libraries(edge_detector ${OpenCV_LIBS})
