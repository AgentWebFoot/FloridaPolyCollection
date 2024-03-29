import numpy as np
import cv2

circle1 = cv2.imread('circles1.png')  
circle2 = cv2.imread('circles2.png')  
circle3 = cv2.imread('circles3.png')  

def CircleFinder1(img):
    print("New Image")
    ## Image Processing
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    blur = cv2.medianBlur(gray, 5)
    edges = cv2.Canny(blur, 50, 300)
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

    ## Circle Detection
    circles = []
    for contour in contours:
        circumference = cv2.arcLength(contour, 1)
        area = cv2.contourArea(contour)
        if circumference == 0:
            continue
        circularity = 4 * np.pi * (area / (circumference * circumference))
        if 0.3 < circularity < 3:
            (x, y), radius = cv2.minEnclosingCircle(contour)
            center = (int(x), int(y))
            radius = int(radius)
            if 20 < radius:
                circles.append((center, radius))
                print("Center: ", center, "Radius: ", radius)

    ## Drawing Circles
    for center, radius in circles:
        cv2.circle(img, center, radius, (0, 255, 0), 2)

    cv2.imshow('Detected Circles', img)
    cv2.waitKey(0)

def CircleFinder2(img):
    print("New Image")
    ## Image Processing
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    blur = cv2.medianBlur(gray, 5)
    _, edges = cv2.threshold(blur, 0, 200, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    edges = cv2.Canny(edges, 50, 300)
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

    ## Circle Detection
    circles = []
    for contour in contours:
        circumference = cv2.arcLength(contour, 1)
        area = cv2.contourArea(contour)
        if circumference == 0:
            continue
        circularity = 4 * np.pi * (area / (circumference * circumference))
        if 0.3 < circularity < 3:
            (x, y), radius = cv2.minEnclosingCircle(contour)
            center = (int(x), int(y))
            radius = int(radius)
            if 20 < radius:
                circles.append((center, radius))
                print("Center: ", center, "Radius: ", radius)

    ##Drawing Circles
    for center, radius in circles:
        cv2.circle(img, center, radius, (0, 255, 0), 2)

    cv2.imshow('Detected Circles', img)
    cv2.waitKey(0)

def CircleFinder3(img):
    print("New Image")
    ## Image Processing
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    blur = cv2.medianBlur(gray, 5)
    _, edges = cv2.threshold(blur, 0, 200, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    edges = cv2.Canny(edges, 50, 300)
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

    ## Circle Detection
    circles = []
    for contour in contours:
        circumference = cv2.arcLength(contour, 1)
        area = cv2.contourArea(contour)
        if circumference == 0:
            continue
        circularity = 4 * np.pi * (area / (circumference * circumference))
        if 0.3 < circularity < 3:
            (x, y), radius = cv2.minEnclosingCircle(contour)
            center = (int(x), int(y))
            radius = int(radius)
            if 20 < radius:
                circles.append((center, radius))
                print("Center: ", center, "Radius: ", radius)

    ## Drawing Circles
    for center, radius in circles:
        cv2.circle(img, center, radius, (0, 255, 0), 2)

    ## Image Processing
    edges = cv2.Canny(blur, 50, 300)
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

    ## Circle Detection
    circles = []
    for contour in contours:
        circumference = cv2.arcLength(contour, True)
        area = cv2.contourArea(contour)
        if circumference == 0:
            continue
        circularity = 4 * np.pi * (area / (circumference * circumference))
        if 0.3 < circularity < 3:
            (x, y), radius = cv2.minEnclosingCircle(contour)
            center = (int(x), int(y))
            radius = int(radius)
            if 20 < radius:
                circles.append((center, radius))
                print("Center: ", center, "Radius: ", radius)

    ## Drawing Circles
    for center, radius in circles:
        cv2.circle(img, center, radius, (0, 255, 0), 2)

    cv2.imshow('Detected Circles', img)
    cv2.waitKey(0)

CircleFinder1(circle1)
CircleFinder2(circle2)
CircleFinder3(circle3)