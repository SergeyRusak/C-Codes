import cv2
import numpy as np

def neighbors4(y, x):
  return (y - 1, x), (y, x + 1), (y + 1, x), (y, x - 1)


def neighbors8(y, x):
  return (y - 1, x), (y - 1, x + 1), (y, x + 1), (y + 1, x + 1), (y + 1, x), (y + 1, x - 1), (y, x - 1), (y - 1, x - 1)


def get_boundaries(image):
  pos = np.where(image)
  boundaries = []
  for y, x in zip(*pos):
    for yn, xn in neighbors4(y, x):
      if yn < 0 or yn > image.shape[0] - 1:
        boundaries.append((y, x))
        break
      elif xn < 0 or xn > image.shape[1] - 1:
        boundaries.append((y, x))
        break
      elif image[yn, xn] == 0:
        boundaries.append((y, x))
        break
  return boundaries

def euclid(p1, p2):
    return ((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) ** 0.5


def cblock(p1, p2):
  return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])


def distance_map(image, dist_f=euclid):
  dmap = np.zeros_like(image)
  bounds = get_boundaries(image)
  pos = np.where(image)
  for p1 in zip(*pos):
    dists = [dist_f(p1, p2) for p2 in bounds]
    dmap[p1[0], p1[1]] = min(dists)
  return dmap

vidcap = cv2.VideoCapture('balls.mp4')
success,image = vidcap.read()
frame = 0
while success:
  img = image
  img0 = img[:, :, 0]
  img1 = img[:, :, 1]
  img2 = img[:, :, 2]
  gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
  _, th0 = cv2.threshold(img0, 100, 200, cv2.THRESH_BINARY)
  _, th2 = cv2.threshold(img2, 50, 200, cv2.THRESH_BINARY)
  thb = th0 - th2
  thr = th2 - th0
  _, th = cv2.threshold(thb, 10, 255, cv2.THRESH_BINARY)
  th = cv2.erode(th, np.ones((7,7)), iterations=3)

  contours, _ = cv2.findContours(th, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
  count = 0
  for c in contours:
    (x, y), radius = cv2.minEnclosingCircle(c)
    if radius > 50:
      if radius > 100:
        #print("alarm")
        area = cv2.boundingRect(c)
        dists = distance_map(th[area[1]:area[1]+area[3],area[0]:area[0]+area[2]])
        th_dists = np.zeros_like(dists)
        th_dists[dists > np.max(dists)/2]= 255

        insidecontours, _ = cv2.findContours(th_dists, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        #cv2.imshow("th_dists",th_dists)
        for i in insidecontours:
          (ix, iy), iradius = cv2.minEnclosingCircle(i)
          count += 1
          cv2.circle(img, (int(ix+area[0]), int(iy+area[1])), int(iradius), (255, 255, 255), 5)
      else:
        count += 1
        cv2.circle(img, (int(x), int(y)), int(radius), (255, 255, 255), 5)

  cv2.putText(img, f"Balls:{count}", (10, 70), cv2.FONT_HERSHEY_SIMPLEX, 2.0,
              (10, 255, 10))
  #cv2.imshow("threshold Blue-Red", th)
  #cv2.imshow("original", img)
  #cv2.waitKey(0)
  cv2.imwrite("result/frame%d.jpg" % frame, img)     # save frame as JPEG file
  success,image = vidcap.read()
  frame += 1
