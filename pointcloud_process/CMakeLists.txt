
cmake_minimum_required(VERSION 3.5)
project(pointcloud_process)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


link_directories(/usr/lib/aarch64-linux-gnu/tegra)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
roscpp
sensor_msgs
image_transport
cv_bridge
std_msgs
)
catkin_package(
    CATKIN_DEPENDS image_transport cv_bridge roscpp sensor_msgs
)
include_directories(${catkin_INCLUDE_DIRS})
add_executable(pcl_alter scripts/pcl_alter.cpp)
target_link_libraries(pcl_alter ${catkin_LIBRARIES})
