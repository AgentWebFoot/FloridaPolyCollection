import numpy as np
import matplotlib.pyplot as plt
import cv2
from sklearn.cluster import MeanShift, estimate_bandwidth

# Read images
bench = cv2.imread('meanshit S00-150x150.png')
standing = cv2.imread('OTSU Multiple Class-S01-150x150.png')
man = cv2.imread('OTSU2class-andreas_L-150x150.png')
classEdge = cv2.imread('OTSU2class-edge_L-150x150.png')


def meanImageSegmentation(image):
    image = cv2.medianBlur(image, 3)

    # flatten the image
    flat_image = image.reshape((-1,3))
    flat_image = np.float32(flat_image)

    # meanshift
    bandwidth = estimate_bandwidth(flat_image, quantile=.06, n_samples=3000)
    ms = MeanShift(bandwidth=bandwidth)
    ms.fit(flat_image)
    labeled=ms.labels_

    # get number of segments
    segments = np.unique(labeled)
    print('Number of segments: ', segments.shape[0])

    # get the average color of each segment
    total = np.zeros((segments.shape[0], 3), dtype=float)
    count = np.zeros(total.shape, dtype=float)
    for i, label in enumerate(labeled):
        total[label] = total[label] + flat_image[i]
        count[label] += 1
    avg = total/count
    avg = np.uint8(avg)

    # cast the labeled image into the corresponding average color
    res = avg[labeled]
    image_mean = res.reshape((image.shape))

    # Display results
    cv2.imshow('Original Image', image)
    cv2.imshow('Mean Image', image_mean)
    cv2.waitKey(0)

# Perform mean image segmentation
meanImageSegmentation(bench)

def otsuTwoClassImageSegmentation(image):
    # Convert image to gray
    image_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Perform Otsu thresholding on gray image
    _, thresh_gray = cv2.threshold(image_gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    # Perform Otsu thresholding on RGB
    r, g, b = cv2.split(image)
    _, thresh_r = cv2.threshold(r, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    _, thresh_g = cv2.threshold(g, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    _, thresh_b = cv2.threshold(b, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    # Combine RGB thresholded results
    thresh_color = cv2.merge((thresh_r, thresh_g, thresh_b))

    # Display results
    cv2.imshow('Original Image', image)
    cv2.imshow('Thresholded Image (Gray)', thresh_gray)
    cv2.imshow('Thresholded Image (Color)', thresh_color)
    cv2.waitKey(0)


# Perform segmentation
otsuTwoClassImageSegmentation(classEdge)
otsuTwoClassImageSegmentation(man)

def otsuMultiClassImageSegmentation(image):
    # Convert image to gray
    image_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Perform Otsu thresholding on gray image
    _, thresh_gray = cv2.threshold(image_gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    _, thresh_gray2 = cv2.threshold(thresh_gray, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    # Perform Otsu thresholding on RGB
    r, g, b = cv2.split(image)
    _, thresh_r = cv2.threshold(r, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    _, thresh_r2 = cv2.threshold(thresh_r, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    _, thresh_g = cv2.threshold(g, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    _, thresh_g2 = cv2.threshold(thresh_g, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    _, thresh_b = cv2.threshold(b, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    _, thresh_b2 = cv2.threshold(thresh_b, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)

    # Combine RGB thresholded results
    thresh_color = cv2.merge((thresh_r2, thresh_g2, thresh_b2))

    # Display results
    cv2.imshow('Original Image', image)
    cv2.imshow('Thresholded Image (Gray)', thresh_gray2)
    cv2.imshow('Thresholded Image (Color)', thresh_color)
    cv2.waitKey(0)


otsuMultiClassImageSegmentation(standing)