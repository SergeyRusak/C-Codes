import matplotlib.pyplot as plt
import socket
import numpy as np


def recvall(sock, n):
    data = bytearray()
    while len(data) < n:
        packet = sock.recv(n - len(data))
        if not packet:
            return
        data.extend(packet)
    return data


plt.ion()
plt.figure()
host = "84.237.21.36"
port = 5152
pics = 0
dist = 0

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    packet_size = 40002
    sock.connect((host, port))
    while pics < 10:
        sock.send(b"get")
        bts = recvall(sock, packet_size)
        rows, cols = bts[:2]
        img = np.frombuffer(bts[2:rows * cols + 2], dtype="uint8").reshape(rows, cols)

        cords = []
        for i in range(1, len(img) - 1):
            for j in range(1, len(img[i] - 1)):
                nerby_x = list(img[i,j-1:j+2])
                nerby_y = list(img[i-1:i+2,j])
                if nerby_y.index(max(nerby_y))==1 and nerby_x.index(max(nerby_x))==1:
                    cords.append([i, j])
        if len(cords) >= 2:
            dist = str(round(((cords[0][0] - cords[1][0]) ** 2 + (cords[0][1] - cords[1][1]) ** 2) ** 0.5, 1))

        sock.send(dist.encode())
        beat = sock.recv(20)
        if beat == b'yep':
            pics += 1

        print(dist)
        print(beat.decode())
        print()
        plt.clf()
        plt.imshow(img)
        plt.pause(1)
