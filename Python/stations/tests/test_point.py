import pytest
from plib import Point, PointError


@pytest.fixture
def points():
    return Point(0, 0), Point(0, 5)


class TestPoint:
    def test_creation(self):
        Point(1, 2)
        Point(3, 0)
        with pytest.raises(PointError):
            Point(1.5, "2")

    def test_addition(self, points):
        p1, p2 = points
        assert p1 + p2 == p2

    def test_subtract(self, points):
        p1, p2 = points
        assert p1 - p2 == -p2

    def test_distance(self, points):
        p1, p2 = points
        assert p1.distance_to(p2) == 5.0

    @pytest.mark.parametrize(
        "p1, p2, distance",
        [(Point(0, 0), Point(0, 10), 10),
         (Point(0, 0), Point(10, 0), 10),
         (Point(0, 0), Point(1, 1), 1.4),
         ]
    )
    def test_distances_all_axis(self, p1, p2, distance):
        assert p1.distance_to(p2) == pytest.approx(distance, 0.1)

    def test_to_json(self):
        js = '{"x": 0, "y": 0}'
        assert Point(0, 0).to_json() == js

    def test_from_json(self):
        js = '{"x": 0, "y": 0}'
        assert Point.from_json(js) == Point(0, 0)

    def test_center(self, points):
        p1, p2 = points
        assert p1.is_center()
        assert not p2.is_center()

    def test_eq_with_other_type(self, points):
        p1, p2 = points
        assert p1 == [0, 0]
        assert p2 == (0, 5)

    def test_eq_with_other_other_type(self, points):
        p1, p2 = points
        with pytest.raises(Exception):
            bla = p1 == 1

    def test_str(self):
        assert Point(1, 2).__str__() == "Point(1, 2)"

    def test_repr(self):
        assert Point(1, 2).__repr__() == "Point(1, 2)"
