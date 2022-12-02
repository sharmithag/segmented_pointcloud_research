
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
pcl_ros
pcl_conversions
sensor_msgs
message_filters
image_transport
cv_bridge
std_msgs
)
catkin_package(
    CATKIN_DEPENDS image_transport cv_bridge roscpp sensor_msgs message_filters pcl_ros pcl_conversions
)
include_directories(${catkin_INCLUDE_DIRS})
add_executable(pcl_alter scripts/pcl_alter.cpp)
<<<<<<< HEAD
target_link_libraries(pcl_alter ${catkin_LIBRARIES} ${OpenCV_LIBS})
=======
target_link_libraries(pcl_alter ${catkin_LIBRARIES})
>>>>>>> afadd1aba6f6a1d6ceb9edc85fc16e503122a715
