from pypcd import pypcd
import numpy as np
from pprint import pprint
import cv2


p_cld = pypcd.PointCloud.from_path('/media/sharmitha/TOSHIBA EXT/bagfiles/pcl/1658009788.526458716.pcd')
#1658009920.372541716.pcd
pc_data_arr = p_cld.pc_data
pc_array = np.array([pc_data_arr["x"], pc_data_arr["y"], pc_data_arr["z"],pc_data_arr["rgb"]], dtype=np.float32)
image = cv2.imread('/media/sharmitha/TOSHIBA EXT/data/seg_mask/0.jpg')
print(image.shape)
image_1d = np.reshape(image,(252672,3))
print(image_1d[0][0])
print(pc_array[3].shape)

for i in range(len(pc_array[3])):
	if (130 > image_1d[i][0]> 125 and 68>image_1d[i][1] > 60 and 130> image_1d[i][2] >125):
		pc_array[0][i] = None;
		pc_array[1][i] = None;		
		pc_array[2][i] = None;
		pc_array[3][i] = None;

p_cld.pc_data["x"] = pc_array[0]
p_cld.pc_data["y"] = pc_array[1]
p_cld.pc_data["z"] = pc_array[2]		
p_cld.pc_data["rgb"] = pc_array[3]
p_cld.save_pcd('0.pcd',compression='binary_compressed')





