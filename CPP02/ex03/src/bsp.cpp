#include "../includes/Point.hpp"

bool bsp(Point const& point, Point const& a, Point const& b, Point const& c) {
	int point_pos_ab = point.point_position(a, b);
	int point_pos_bc = point.point_position(b, c);
	int point_pos_ca = point.point_position(c, a);

	if (point_pos_ab != point_pos_bc || point_pos_ab != point_pos_ca) return (false);
	return (true);
}

// ab -> left
// bc -> bottom
// ac -> right
// https://www.baeldung.com/cs/check-if-point-is-in-2d-triangle for reference, but it's modified a bit here