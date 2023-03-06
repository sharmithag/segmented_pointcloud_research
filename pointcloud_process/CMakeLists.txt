
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
std_msgs
cv_bridge
)
catkin_package(
    CATKIN_DEPENDS roscpp sensor_msgs pcl_ros pcl_conversions cv_bridge
)
include_directories(${catkin_INCLUDE_DIRS})
add_executable(rezoom scripts/rezoom.cpp)
target_link_libraries(rezoom ${catkin_LIBRARIES} ${OpenCV_LIBS})
