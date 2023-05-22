#include "../includes/Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::~Point() {}

Fixed Point::calc_x_pos(void) const { return _x; }
Fixed Point::calc_y_pos(void) const { return _y; }
Point::Point(Point const &number) { *this = number; }
Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) {}

Point &Point::operator=(Point const &number) {
    if (this != &number) {
        _x = number.calc_x_pos();
        _y = number.calc_y_pos();
    }
    return *this;
}

int Point::point_position(Point const &a, Point const &b) const {
    Point ab(a.calc_x_pos() - b.calc_x_pos(), a.calc_y_pos() - b.calc_y_pos());
    Point ap(a.calc_x_pos() - calc_x_pos(), a.calc_y_pos() - calc_y_pos());
    float point_pos;

    point_pos = (ab.calc_x_pos() * ap.calc_y_pos() - ab.calc_y_pos() * ap.calc_x_pos()).toFloat();

    if (point_pos > 0) return (POINT_OUTSIDE);
    return (POINT_INSIDE);
}
