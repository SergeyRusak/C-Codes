import pytest
from plib import Station, Point, XYZ
from plib.station import StationError


class TestStation:
    def test_creation(self):
        d = {'code': 'uiii',
             'height': 123.1,
             'status': 'new',
             'location': {
                 'lat': 1.0,
                 'lon': 2
             },
             'xyz': [12, 43, 12]
             }
        Station(d)

    @pytest.mark.parametrize(
        "d",
        [({'code': "5235434",
           'height': 12,
           'status': 342,
           'location': {
               'lat': "1.0",
               'lon': "2.5"
           },
           'xyz': "[12, 43, 12]"
           }),
         ({'code': 5235434,
           'height': "dsadas",
           'status': 342,
           'location': {},
           'xyz': ""
           }),
         ({'code': 'uiii',
           'height': "123.1",
           'status': 'new',
           'location': {
               'lat': 1.0,
               'lon': 2
           },
           'xyz': [12, 43, 12]
           }),
         ({'code': 'uiii',
           'height': 123.1,
           'status': [],
           'location': {
               'lat': 1.0,
               'lon': 2
           },
           'xyz': [12, 43, 12]
           }),
         ({'code': 'uiii',
           'height': 123.1,
           'status': 'new',
           'location': {
               'lattt': 1.0,
               'lonttt': 2
           },
           'xyz': [12, 43, 12]
           }),
         ({'code': 'uiii',
           'height': 123.1,
           'status': 'new',
           'location': {
               'lat': "1.0",
               'lon': "2"
           },
           'xyz': [12, 43, 12]
           }),
         ({'code': 'uiii',
           'height': 123.1,
           'status': 'new',
           'location': {
               'lat': 1.0,
               'lon': 2
           },
           'xyz': []
           }),
         ({'code': 'uiii',
           'height': 123.1,
           'status': 'new',
           'location': {
               'lat': 1.0,
               'lon': 2
           },
           'xyz': ["12", "13", "14"]
           })
         ]
    )
    def test_creation_fail(self, d):
        with pytest.raises(StationError):
            Station(d)

    def test_str(self):
        d = {'code': 'xxxx',
             'height': 123.1,
             'status': 'new',
             'location': {
                 'lat': 1.0,
                 'lon': 2
             },
             'xyz': [12, 43, 12]
             }
        Station(d)
        assert Station(
            d).__str__() == "Station code: xxxx, height: 123.1, status: new, location: Point(1.0, 2), xyz: (x: 12, " \
                            "y: 43, z: 12)"

    def test_xyz_creation(self):
        XYZ(1, 2.0, 3)

    @pytest.mark.parametrize(
        "x, y, z",
        [("dsadds", "asdasd", "qweqw")]
    )
    def test_xyz_creation_fail(self, x, y, z):
        with pytest.raises(StationError):
            XYZ(x, y, z)

    def test_xyz_str(self):
        assert XYZ(1, 2, 3).__str__() == "x: 1, y: 2, z: 3"

    @pytest.mark.parametrize(
        "p1, p2, p3, a",
        [({'code': 'xxxx',
           'height': 123.1,
           'status': 'new',
           'location': {
               'lat': 0,
               'lon': 0
           },
           'xyz': [12, 43, 12]
           }, {'code': 'xxxx',
               'height': 123.1,
               'status': 'new',
               'location': {
                   'lat': 5,
                   'lon': 0
               },
               'xyz': [12, 43, 12]
               }, {'code': 'xxxx',
                   'height': 123.1,
                   'status': 'new',
                   'location': {
                       'lat': 0,
                       'lon': 5
                   },
                   'xyz': [12, 43, 12]
                   }, 12.5)]
    )
    def test_square(self, p1, p2, p3, a):
        assert Station.count_triangle_square(Station(p1), Station(p2), Station(p3)) == a
