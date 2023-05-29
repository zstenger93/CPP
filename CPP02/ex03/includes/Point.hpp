#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

#define POINT_INSIDE 1
#define POINT_OUTSIDE -1
#define TRUE "\033[1;92mtrue\033[0;39m"
#define FALSE "\033[1;91mfalse\033[0;39m"
#define RESULT "\033[1;4;37mThe Result Is:\033[0;39m "

class Point {
   public:
    Point();
    Point(Point const &number);
    Point &operator=(Point const &number);
    ~Point();
    Point(Fixed const x, Fixed const y);
    Fixed calc_x_pos(void) const;
    Fixed calc_y_pos(void) const;
    int point_position(Point const &a, Point const &b) const;

   private:
    Fixed _x;
    Fixed _y;
};

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point);

#endif