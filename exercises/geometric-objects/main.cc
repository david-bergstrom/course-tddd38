#include <iostream>
#include <assert.h>

#include "point.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include "circle.h"

void test_point() {
    Point point { 1, 3 };

    assert(point.x == 1);
    assert(point.y == 3);
}

void test_line() {
    Line line {0, 0, 2, 2};
    assert(line.x1 == 0);
    assert(line.y1 == 0);
    assert(line.x2 == 2);
    assert(line.y2 == 2);

    assert(line.length() == std::sqrt(8));
}

void test_rectangle() {
    Rectangle rectangle { 10, 15 };
}

int main() {

    test_point();
    test_line();

    return 0;
}
