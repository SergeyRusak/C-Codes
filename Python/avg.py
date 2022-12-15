import cv2
import matplotlib.pyplot as plt
import numpy as np

def average(image, x_blocks, y_blocks):
    image = image.copy()
    img = np.zeros((image.shape[0] + (image.shape[0] // x_blocks - image.shape[0] % x_blocks),
                        image.shape[1] +(image.shape[1] // y_blocks - image.shape[1] % y_blocks)))
    img[:,:]=np.average(image)
    img[:image.shape[0], :image.shape[1]] = image[:image.shape[0], :image.shape[1]]
    x_size = img.shape[0] // x_blocks
    y_size = img.shape[1] // y_blocks
    for i in range(x_blocks):
        for j in range(y_blocks):
            img[i * x_size: (i + 1) * x_size, j * y_size: (j + 1) * y_size] = \
                np.average(img[i * x_size: (i + 1) * x_size, j * y_size: (j + 1) * y_size])

    return img


img = cv2.imread("cat.jpg")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

image = average(gray,100,100)
plt.imshow(image,cmap='gray')

plt.show()
