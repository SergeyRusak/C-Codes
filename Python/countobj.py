import numpy as np
from skimage.morphology import binary_opening
from skimage.measure import label

type1 = np.array([[0, 0, 0, 0, 0, 0],
                  [0, 1, 1, 1, 1, 0],
                  [0, 1, 1, 1, 1, 0],
                  [0, 0, 0, 1, 1, 0],
                  [0, 0, 0, 1, 1, 0],
                  [0, 1, 1, 1, 1, 0],
                  [0, 1, 1, 1, 1, 0],
                  [0, 0, 0, 0, 0, 0],
                  ])

type2 = np.array([[0, 0, 0, 0, 0, 0],
                  [0, 1, 1, 1, 1, 0],
                  [0, 1, 1, 1, 1, 0],
                  [0, 1, 1, 0, 0, 0],
                  [0, 1, 1, 0, 0, 0],
                  [0, 1, 1, 1, 1, 0],
                  [0, 1, 1, 1, 1, 0],
                  [0, 0, 0, 0, 0, 0],
                  ])

type3 = np.array([[0, 0, 0, 0, 0, 0, 0, 0],
                  [0, 1, 1, 1, 1, 1, 1, 0],
                  [0, 1, 1, 1, 1, 1, 1, 0],
                  [0, 1, 1, 1, 1, 1, 1, 0],
                  [0, 1, 1, 1, 1, 1, 1, 0],
                  [0, 0, 0, 0, 0, 0, 0, 0],
                  ])

type4 = np.array([[0, 0, 0, 0, 0, 0, 0, 0],
                  [0, 1, 1, 1, 1, 1, 1, 0],
                  [0, 1, 1, 1, 1, 1, 1, 0],
                  [0, 1, 1, 0, 0, 1, 1, 0],
                  [0, 1, 1, 0, 0, 1, 1, 0],
                  [0, 0, 0, 0, 0, 0, 0, 0],
                  ])

type5 = np.array([[0, 0, 0, 0, 0, 0, 0, 0],
                  [0, 1, 1, 0, 0, 1, 1, 0],
                  [0, 1, 1, 0, 0, 1, 1, 0],
                  [0, 1, 1, 1, 1, 1, 1, 0],
                  [0, 1, 1, 1, 1, 1, 1, 0],
                  [0, 0, 0, 0, 0, 0, 0, 0],
                  ])



types = [type1, type2, type3, type4, type5]

image = np.load("ps.npy.txt")
all_items = label(image).max()
for i in range(len(types)):
    types[i]=label(binary_opening(image, types[i])).max()
types[3]-=types[2]
types[4]-=types[2]

print("Total: ",all_items)
for i in range(len(types)):
    print("Type#",i+1 ," count:", types[i])