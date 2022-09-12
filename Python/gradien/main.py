import numpy as np
import matplotlib.pyplot as plt

def lerp(v0, v1, t):
    return (1 - t) * v0 + t * v1

size = 100
imagex, imagey = np.meshgrid(np.linspace(0, 1, size), np.linspace(0, 1, size))
image = (imagex+imagey)/2
fin = np.zeros((size, size, 3), dtype="uint8")

assert image.shape[0] == image.shape[1]

color1 = [255, 128, 0]
color2 = [0, 128, 255]

for i in range(size):
    for j in range(size):
        r = lerp(color1[0], color2[0], image[i,j])
        g = lerp(color1[1], color2[1], image[i,j])
        b = lerp(color1[2], color2[2], image[i,j])
        image[i, j, :] = [r, g, b]


plt.figure(1)
plt.imshow(fin)
plt.show()