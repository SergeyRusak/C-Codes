import numpy as np
from matplotlib import pyplot as plt
from skimage.measure import label
import cv2

img = cv2.imread("balls_and_rects.png")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
img = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
th, th_otsu = cv2.threshold(gray, 128, 192, cv2.THRESH_OTSU)
labeled = label(th_otsu)

results = {}

for i in range(1, np.max(labeled) + 1):
    wh = np.where(labeled == i)
    y_min = wh[0][0]
    x_min = wh[1][0]
    y_max = wh[0][-1]
    x_max = wh[1][-1]
    color = img[y_min][x_min][0]
    results[color] = results.get(color, [0, 0])
    if (x_max - x_min + 1) * (y_max - y_min + 1) == len(wh[0]):
        results[color][0]+=1
    else:
        results[color][1]+=1




circles = 0
rects = 0
for i in results:
    rects+=results[i][0]
    circles+=results[i][1]
print("Total figures: ",np.max(labeled))
print("Total colors: ",len(results))
print("Totals rects: ",rects," circles: ",circles)
for color in results:
    print("Color: ",color," Rects: ", results[color][0], " Circles: ",results[color][1])

