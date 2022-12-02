import time

import numpy as np
import pyautogui
import cv2.cv2 as cv2
import mss
import numpy

with mss.mss() as sct:
    # Part of the screen to capture
    monitor = {"top": 250, "left": 650, "width": 800, "height": 100}
    alarm_zone = 30
    alarm_grow = 0.01

    while "Screen capturing":
        last_time = time.time()
        img = numpy.array(sct.grab(monitor))
        ret, thresh1 = cv2.threshold(cv2.cvtColor(img, cv2.COLOR_BGRA2GRAY), 127, 255, cv2.THRESH_BINARY)
        result = cv2.erode(thresh1,np.ones((3,3)))
        result = cv2.dilate(thresh1,np.ones((3,3)))
        contours ,_ = cv2.findContours(result, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        imgdet = np.ones((monitor["height"], monitor["width"]))
        for c in contours:
            x,y,w,h = cv2.boundingRect(c)
            if w == monitor["width"]:
                continue
            cv2.rectangle(imgdet,(x,y),(x+w,y+h),0,-1)

        if np.any(imgdet[:,150:150+int(alarm_zone)] <1):
            pyautogui.press('space')
            cv2.rectangle(img, (150, 0), (150 + int(alarm_zone), monitor["height"]), (0, 0, 255), 5)
        else:
            cv2.rectangle(img, (150, 0), (150 + int(alarm_zone), monitor["height"]), (0, 0, 0), 2)


        cv2.imshow("Image detection", img)

        alarm_zone+=alarm_grow
        # Press "q" to quit
        key = cv2.waitKey(1)
        if key == ord("q"):
            cv2.destroyAllWindows()
            break
        if key == ord("r"):
            alarm_zone = 10
