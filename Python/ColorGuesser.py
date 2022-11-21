import random

import cv2
import numpy as np
from functools import cmp_to_key

cv2.namedWindow("Camera",cv2.WINDOW_KEEPRATIO)


cam = cv2.VideoCapture(0)
#cam.set(cv2.CAP_PROP_AUTO_EXPOSURE, 1)
position = [0,0]
pred = None
count_of_colors = 1
def compare(item1,item2):
    if item1[0]> item2[0]:
        return 1
    if item1[0] < item2[0]:
        return -1
    if item1[0] == item2[0]:
        return 0

def on_mouse_click (event,x,y,flags,param):
    if event == cv2.EVENT_LBUTTONDOWN:
        global position
        position = [y,x]

cv2.setMouseCallback("Camera",on_mouse_click)
measures = []
hsv = []
orders = []


def generate(n):
     return random.sample(['B','G','R','Y'],n)


while cam.isOpened():
    ret, frame = cam.read()
    pixel = frame[position[0],position[1],:]
    measures.append(pixel)
    if len(measures) == 10:
        bgr = np.uint8([[np.mean(measures,0)]])
        hsv = cv2.cvtColor(bgr,cv2.COLOR_BGR2HSV)
        measures.clear()

    lower_red = np.array([0, 130, 130])
    upper_red = np.array([5, 255, 255])

    lower_red1 = np.array([175, 130, 130])
    upper_red1 = np.array([190, 255, 255])

    #lower_orange = np.array([6, 100, 90])
    #upper_orange = np.array([10, 255, 255])

    lower_yellow = np.array([20, 100, 90])
    upper_yellow = np.array([40, 255, 255])

    lower_green = np.array([65, 100, 80])
    upper_green = np.array([85, 255, 255])

    lower_blue = np.array([95,120,120])
    upper_blue = np.array([105,255,255])

    hsvi = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    mask_red1 = cv2.inRange(hsvi, lower_red, upper_red)
    mask_red2 = cv2.inRange(hsvi, lower_red1, upper_red1)
    mask_green = cv2.inRange(hsvi, lower_green, upper_green)
    mask_blue = cv2.inRange(hsvi, lower_blue, upper_blue)
    mask_yellow = cv2.inRange(hsvi, lower_yellow, upper_yellow)
    #mask_orange = cv2.inRange(hsvi, lower_orange, upper_orange)

    mask_red = cv2.erode(mask_red1+mask_red2,None,iterations=3)
    mask_red = cv2.dilate(mask_red,None,iterations=3)
    res_red = cv2.bitwise_and(frame, frame, mask=mask_red)

    mask_green = cv2.erode(mask_green,None,iterations=3)
    mask_green = cv2.dilate(mask_green,None,iterations=3)
    res_green = cv2.bitwise_and(frame, frame, mask=mask_red)

    mask_yellow = cv2.erode(mask_yellow,None,iterations=3)
    mask_yellow = cv2.dilate(mask_yellow,None,iterations=3)
    res_yellow = cv2.bitwise_and(frame, frame, mask=mask_red)

    mask_blue = cv2.erode(mask_blue,None,iterations=3)
    mask_blue = cv2.dilate(mask_blue,None,iterations=3)
    res_blue = cv2.bitwise_and(frame, frame, mask=mask_red)

    #mask_orange = cv2.erode(mask_orange,None,iterations=3)
   # mask_orange = cv2.dilate(mask_orange,None,iterations=3)
    #res_orange = cv2.bitwise_and(frame, frame, mask=mask_orange)

    contours_r,_ = cv2.findContours(mask_red,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    contours_g,_ = cv2.findContours(mask_green,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    contours_b,_ = cv2.findContours(mask_blue,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    contours_y,_ = cv2.findContours(mask_yellow,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    #contours_o,_ = cv2.findContours(mask_orange,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)



    orders=[]

    if len(contours_r) >0:
        c = max(contours_r,key=cv2.contourArea)
        (x,y),radius = cv2.minEnclosingCircle(c)
        if radius > 10:
            cv2.circle(frame,(int(x),int(y)),int(radius),(0,0,255),2)
            orders.append([int(x),int(y),"R"])
    if len(contours_g) >0:
        c = max(contours_g,key=cv2.contourArea)
        (x,y),radius = cv2.minEnclosingCircle(c)
        if radius > 10:
            cv2.circle(frame,(int(x),int(y)),int(radius),(0,255,0),2)
            orders.append([int(x), int(y), "G"])
    if len(contours_b) >0:
        c = max(contours_b,key=cv2.contourArea)
        (x,y),radius = cv2.minEnclosingCircle(c)
        if radius > 10:
            cv2.circle(frame,(int(x),int(y)),int(radius),(255,0,0),2)
            orders.append([int(x), int(y), "B"])
    if len(contours_y) >0:
        c = max(contours_y,key=cv2.contourArea)
        (x,y),radius = cv2.minEnclosingCircle(c)
        if radius > 10:
            cv2.circle(frame, (int(x), int(y)),int(radius),(0,255,255),2)
            orders.append([int(x), int(y), "Y"])
    #if len(contours_o) < 0:
     #   c = max(contours_o,key=cv2.contourArea)
      #  (x,y),radius = cv2.minEnclosingCircle(c)
       # if radius > 10:
        #    cv2.circle(frame, (int(x), int(y)),int(radius),(0,125,255),2)
         #   orders.append([int(x), int(y), "O"])



    if len(orders)==0:
        orders = [[0,0,"NONE"]]
    else:
        orders = sorted(orders, key=cmp_to_key(compare))
    oords =''.join( np.array(orders)[:,2])




    cv2.rectangle(frame, (10,10),(630,470),(0,255,0) if (pred==oords) else (0,0,0),20)
    cv2.putText(frame,f"Count of colors:{count_of_colors}", (10,20),cv2.FONT_HERSHEY_SIMPLEX,0.7,(255,255,127))
    cv2.circle(frame,position[::-1],5,(0,255,127))
    cv2.imshow("Camera",frame)
    key = cv2.waitKey(1)
    if key ==ord('q'):
        break
    if key ==ord('1'):
        count_of_colors = 1
    if key ==ord('2'):
        count_of_colors = 2
    if key ==ord('3'):
        count_of_colors = 3
    if key ==ord('4'):
        count_of_colors = 4
    #if key ==ord('5'):
     #   count_of_colors = 5

    if key ==ord('e'):
        pred = ''.join(generate(count_of_colors))





cam.release()
cv2.destroyAllWindows()
