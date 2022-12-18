import json
from typing import List
from plib.station import Station, StationError

data = json.load(open('stations.json'))

points: List[Station] = []

for elem in data:
    try:
        points.append(Station(elem))
    except StationError as e:
        print(e)


min_sq = float('inf')
a, b, c = 0,0,0

for i in range(0, len(points)):
    for j in range(i + 1, len(points)):
        for k in range(j + 1, len(points)):
            sq = Station.count_triangle_square(points[i], points[j], points[k])
            if sq < min_sq:
                min_sq = sq
                a, b, c = points[i], points[j], points[k]


print(min_sq)
print(a)
print(b)
print(c)
