# segmented_pointcloud
2d segmentation output used for point cloud processing
ReZoom E-Scooter
https://github.com/REZOOM-UMD/escooter/tree/dev_mi

Semantic segmentation of the e-scooter(ReZoom 2.0 and 3.0) pathway to distinguish road from sidewalk and grass using Jetson Developer Kit and ZED stereo camera.

All samples taken inside the University of Maryland,CP.

### ReZoom 2.0

<img src="https://user-images.githubusercontent.com/90351952/191350972-240d0441-c8f3-4768-9f51-ddfad16f2b57.jpg" width="300" height="400">

### Semantic segmentation Overlay and Mask(Using cityscape dataset)

![Screenshot from 2022-09-20 15-36-32](https://user-images.githubusercontent.com/90351952/191348944-6e2cd1a6-52d4-4c72-8bf5-cbc2732036ed.png)

### Point Cloud Processing to filter out obstacle space (Viewed with pcl_viewer)

Libraries used : rosbag,pcl_ros,pypcd,open3D

![Screenshot from 2022-09-20 15-43-44](https://user-images.githubusercontent.com/90351952/191350367-fee77eea-4a0d-4e94-a8be-f1569f8326cb.png)

## Requirements

- [Jetson Segmentation package](https://github.com/dusty-nv/jetson-inference)
- [ZED SDK](https://www.stereolabs.com/developers/release/)
- [ZED ROS Wrapper](https://github.com/stereolabs/zed-ros-wrapper)

## Code Flow:

![Rezoom nov 18](https://user-images.githubusercontent.com/90351952/202696896-6416899e-c1f4-4f31-9f1e-b88a8e4802b6.png)



