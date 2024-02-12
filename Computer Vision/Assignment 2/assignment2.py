# IMPORTING
import cv2
import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

# READING IMAGES
img = cv2.imread('bicycle.bmp')
imgGray = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)

# BOX FILTER
## Manual Box Filter
mask3 = np.ones((3,3))/255
box3 = signal.convolve2d(imgGray,mask3,boundary='symm',mode='same')
fig,(ax1,ax2) = plt.subplots(1,2,figsize=(10,15))

mask5 = np.ones((5,5))/255
box5 = signal.convolve2d(imgGray,mask5,boundary='symm',mode='same')
fig,(ax1,ax2) = plt.subplots(1,2,figsize=(10,15))

## Built in Box Filter
bBox3 = cv2.boxFilter(imgGray,-1,(3,3))
bBox5 = cv2.boxFilter(imgGray,-1,(5,5))

# SOBEL FILTERS
## Horizontal Edge
xEdge3 = np.array([[-1,-2,-1],[0,0,0],[1,2,1]], dtype=np.float32)
xSobel3 = cv2.filter2D(imgGray, -1, xEdge3)
xEdge5 = np.array([[-2,-2,-4,-2,-2],[-1,-1,-2,-1,-1],[0,0,0,0,0],[1,1,2,1,1],[2,2,4,2,2]], dtype=np.float32)
xSobel5 = cv2.filter2D(imgGray, -1, xEdge5)
 
## Vertical Edge
yEdge3 = np.array([[-1,0,1],[-2,0,2],[-1,0,1]], dtype=np.float32)
ySobel3 = cv2.filter2D(imgGray, -1, yEdge3)
yEdge5 = np.array([[-2,-1,0,1,2],[-2,-1,0,1,2],[-4,-2,0,2,4],[-2,-1,0,1,2],[-2,-1,0,1,2]], dtype=np.float32)
ySobel5 = cv2.filter2D(imgGray, -1, yEdge5)

## Combined
fx3 = signal.convolve2d(imgGray, xEdge3, boundary='symm', mode='same')
fy3 = signal.convolve2d(imgGray, yEdge3, boundary='symm', mode='same')
combined3 = (fx3**2 + fy3**2)**0.5

fx5 = signal.convolve2d(imgGray, xEdge5, boundary='symm', mode='same') 
fy5 = signal.convolve2d(imgGray, yEdge5, boundary='symm', mode='same')
combined5 = (fx5**2 + fy5**2)**0.5

## Built-in Sobel
bSobel3 = cv2.Sobel(imgGray, cv2.CV_64F, 1, 1, 3)
bSobel5 = cv2.Sobel(imgGray, cv2.CV_64F, 1, 1, 5)

# GAUSIAN
gausian3 = cv2.GaussianBlur(imgGray, (3,3), 0)
gausian5 = cv2.GaussianBlur(imgGray, (5,5), 0)

# SHOWING IMAGES

cv2.imshow("Original", img)
cv2.moveWindow("Original", 20,20)
cv2.imshow("Gray", imgGray)
cv2.moveWindow("Gray", 40,20)
ax1.imshow(box3,cmap='gray')# 1
ax2.imshow(box5,cmap='gray')
plt.show()
cv2.waitKey(0)

cv2.imshow("bBox3", bBox3) # 2
cv2.moveWindow("bBox3", 60,20)
cv2.imshow("bBox5", bBox5)
cv2.moveWindow("bBox5", 80,20)
cv2.waitKey(0)

cv2.imshow("xSobel3", xSobel3) # 3
cv2.imshow("xSobel5", xSobel5)
cv2.waitKey(0)

cv2.imshow("ySobel3", ySobel3) # 4
cv2.imshow("ySobel5", ySobel5)
cv2.waitKey(0)

cv2.imshow("combined3", combined3) # 5
cv2.imshow("combined5", combined5)
cv2.waitKey(0)

cv2.imshow("bSobel3", bSobel3) # 6
cv2.imshow("bSobel5", bSobel5)
cv2.waitKey(0) 

cv2.imshow("gausian3", gausian3) # 7
cv2.imshow("gausian5", gausian5)
cv2.moveWindow("gausian3", 40,20)
cv2.moveWindow("gausian5", 40,20)
cv2.waitKey(0)
