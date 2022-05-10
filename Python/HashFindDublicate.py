import re
import os
import sys
import time
import random

def CRC(chars):
    h = 0
    for char in chars:
        highorder = h & 0xf8000000
        h = h << 5
        h = h ^ (highorder >> 27)
        h = h ^ ord(char)
    return h


def PJW(chars):
    h = 0
    for char in chars:
        h = (h << 4) + ord(char)
        g = h & 0xf0000000
        if g != 0:
            h = h ^ (g >> 24)
            h = h ^ g
    return h

def generate_R():
    R = []
    for i in range(0,128):
        k = random.randint(0,127)
        while k in R:
            k = random.randint(0, 127)
        R.append(k)
    return R

R = generate_R()

def BUZ(chars):
    h = 0
    for char in chars:
        highorder = h & 0x80000000
        h = h << 1
        h = h ^ (highorder >> 31)
        h = h ^ R[ord(char)]
    return h


def prepare(text):
    return re.sub('\W+', '', text.lower())


def check_dublicate(files_list, hash_func):
    hashes = []
    count = 0
    for file in files_list:
        with open(file, "r") as f:
            tex = prepare(f.read())
            hashes.append(hash_func(tex))
    hashes.sort()
    for i in range(len(hashes) - 1):
        if hashes[i] == hashes[i + 1]:
            count += 1
    return count

def find_files(path):
    filelist = []
    for (root, dirs, file) in os.walk(path):
        for f in file:
            filelist.append(os.path.join(root, f))
    return filelist


def timetest(files, func):
    print("____________________________")
    print("Hash-func : "+ (func.__name__ if func.__name__ !="hash" else "build-in hash function"))
    timer = time.time_ns()
    print("Dublicate files : " + str(check_dublicate(files, func)))
    print("Elapsed time: " + str((time.time_ns() - timer) / 1000) + " milliseconds")
    print("____________________________")



if __name__ == "__main__":



    hash1 = CRC
    hash2 = PJW
    hash3 = BUZ
    hash4 = hash

    files = find_files(sys.argv[1])

    timetest(files, hash1)
    timetest(files, hash2)
    timetest(files, hash3)
    timetest(files, hash4)

