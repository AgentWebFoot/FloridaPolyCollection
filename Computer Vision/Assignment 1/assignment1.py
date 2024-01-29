import cv2
import matplotlib.pyplot as plt
import os.path
import numpy as np

## Pulling data
if not os.path.exists("Data.txt"):
    with open("Data.txt", 'w') as file:
        file.write("10\n0")

with open("Data.txt", 'r') as file:
    contrast = int(file.readline())
    brightness = int(file.readline())
maxContrast = 100
maxBrightness = 100

## Load Images and Create Window
window = "Dog"
img1 = cv2.imread('dog.bmp')
img1 = np.float32(img1/255)

## Functions
def changeImage():
    global img2
    img2 = np.clip(img1 * contrast + brightness, 0, 1)
    horizontal = np.hstack((img1, img2))
    cv2.imshow(window, horizontal)
    updateHistograms()

def changeBrightness(val):
    global brightness
    brightness = val/100
    changeImage()

def changeContrast(val):
    global contrast
    contrast = val/10
    changeImage()

def updateHistograms():
    hist1 = cv2.calcHist([np.uint8(img1*255)], [0], None, [256], [0, 256])
    hist2 = cv2.calcHist([np.uint8(img2*255)], [0], None, [256], [0, 256])

    plt.subplot(211)
    plt.plot(hist1, color='blue')
    plt.title('Histogram for img1')
    plt.subplot(212)
    plt.plot(hist2, color='red')
    plt.title('Histogram for img2')
    plt.draw()

## Create Trackbars
cv2.imshow(window, img1)
cv2.createTrackbar("Brightness", window, int(brightness), maxBrightness, changeBrightness)
cv2.createTrackbar("Contrast", window, int(contrast), maxContrast, changeContrast)

## Save Function
key = cv2.waitKey(0)
if key == 115:
    with open("Data.txt", 'w') as file:
        file.write(str(int(contrast * 10)) + "\n" + str(int(brightness * 100)))

plt.show()