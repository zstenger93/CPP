#include "../includes/Point.hpp"

static void print_result(int res) {
    if (res == true)
        std::cout << RESULT << TRUE << std::endl;
    else
        std::cout << RESULT << FALSE << std::endl;
}

int main(void) {
    Point p(4.5f, 3.5f), a(1.0f, 1.0f), b(7.0f, 1.0f), c(4.0f, 6.0f);
    print_result(bsp(p, a, b, c));

    Point p2(8.0f, 3.0f), a2(1.0f, 1.0f), b2(7.0f, 1.0f), c2(4.0f, 6.0f);
    print_result(bsp(p2, a2, b2, c2));

    Point p3(4.5f, 3.5f), a3(1.0f, 1.0f), b3(7.0f, 1.0f), c3(4.0f, 6.0f);
    print_result(bsp(p3, a3, b3, c3));

    Point p4(2.0f, 2.0f), a4(1.0f, 1.0f), b4(7.0f, 1.0f), c4(4.0f, 6.0f);
    print_result(bsp(p4, a4, b4, c4));

    Point p5(2.0f, 4.0f), a5(1.0f, 1.0f), b5(7.0f, 1.0f), c5(4.0f, 6.0f);
    print_result(bsp(p5, a5, b5, c5));

    Point p6(5.0f, 2.0f), a6(3.0f, 1.0f), b6(9.0f, 1.0f), c6(6.0f, 5.0f);
    print_result(bsp(p6, a6, b6, c6));

    Point p7(3.0f, 3.0f), a7(2.0f, 1.0f), b7(6.0f, 1.0f), c7(4.0f, 4.0f);
    print_result(bsp(p7, a7, b7, c7));

    Point p8(6.0f, 4.0f), a8(5.0f, 1.0f), b8(9.0f, 1.0f), c8(7.0f, 5.0f);
    print_result(bsp(p8, a8, b8, c8));

    Point p9(1.0f, 1.0f), a9(0.0f, 0.0f), b9(2.0f, 0.0f), c9(1.0f, 2.0f);
    print_result(bsp(p9, a9, b9, c9));

    return 0;
}
