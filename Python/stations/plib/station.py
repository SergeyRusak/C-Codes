from plib import Point


class StationError(Exception):
    ...


class XYZ:
    def __init__(self, x,y,z):
        if not((isinstance(x, int) or isinstance(x, float)) and (isinstance(y, int) or isinstance(y, float))
               and (isinstance(z, int) or isinstance(z, float))):
            raise StationError("x, y, z should be integer or float type")
        self.x = x
        self.y = y
        self.z = z

    def __str__(self):
        return "x:",self.x,", y: ",self.y," z: ",self.z


class Station:
    def __init__(self, d: dict):
        if not isinstance(d['code'], str):
            raise StationError("Code should be str")
        self.code: str = d['code']
        if not (isinstance(d['height'], float) or isinstance(d['height'], int)):
            raise StationError("Height should be int or float")
        self.height: float = d['height']
        if not isinstance(d['status'], str):
            raise StationError("status should be str")
        self.status: str = d['status']
        if 'lat' not in d['location'] or 'lon' not in d['location']:
            raise StationError("location should have lat and lon")
        if not (isinstance(d['location']['lat'], float) or isinstance(d['location']['lat'], int)
                and isinstance(d['location']['lon'], float) or isinstance(d['location']['lon'], int)):
            raise StationError("lat, lon should be int or float")
        self.location: Point = Point(d['location']['lat'], d['location']['lon'])
        for coord in d["xyz"]:
            if not(isinstance(coord, int) or isinstance(coord, float)):
                raise StationError("x, y, z should be int or float")
        if not d['xyz']:
            raise StationError("xyz should be list, length 3")
        self.xyz: XYZ = XYZ(d["xyz"][0], d["xyz"][1], d["xyz"][2])

    def __str__(self):
        return "Station code: %s, height: %s, status: %s, location: %s, xyz: (%s,%s,%s)" % (self.code, self.height,
                                                                                      self.status, str(self.location),
                                                                                      str(self.xyz.x),str(self.xyz.y),str(self.xyz.z))

    @staticmethod
    def count_triangle_square(a, b, c):
        return abs((b.location.x - a.location.x) * (c.location.y - a.location.y) -
                   (c.location.x - a.location.x) * (b.location.y - a.location.y)) / 2
