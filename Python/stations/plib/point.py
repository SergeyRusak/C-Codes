import json


class PointError(Exception):
    ...


class Point:
    def __init__(self, x, y):
        if not((isinstance(x, int) or isinstance(x, float)) and (isinstance(y, int) or isinstance(y, float))):
            raise PointError("x, y should be integer or float type")
        self.y = y
        self.x = x


    def __add__(self, other: "Point"):
        return Point(self.x + other.x, self.y + other.y)

    def __sub__(self, other: "Point"):
        return Point(self.x - other.x, self.y - other.y)

    def __eq__(self, other: object):
        if isinstance(other, Point):
            return self.x == other.x and self.y == other.y
        elif isinstance(other, list) or isinstance(other, tuple):
            return self.x == other[0] and self.y == other[1]
        else:
            raise Exception

    def __neg__(self):
        return Point(-self.x, -self.y)

    def distance_to(self, p2: "Point"):
        return ((self.x - p2.x) ** 2 + (self.y - p2.y) ** 2) ** 0.5

    def to_json(self):
        return json.dumps({"x": self.x, "y": self.y})

    @classmethod
    def from_json(cls: type, s: str):
        js = json.loads(s)
        return cls(int(js["x"]), int(js["y"]))

    def is_center(self):
        return self.x == 0 and self.y == 0

    def __str__(self):
        return f"{self.__class__.__name__}({self.x}, {self.y})"

    def __repr__(self):
        return f"{self.__class__.__name__}({self.x}, {self.y})"

