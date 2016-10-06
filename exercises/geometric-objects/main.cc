#include <iostream>
#include <assert.h>
#include <vector>

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

    std::vector<GeometricObject*> v;

    v.push_back(new Point { 1, 4 });
    v.push_back(new Line {0, 0, 2, 2 });
    v.push_back(new Rectangle { 300, 4 });
    v.push_back(new Circle { 83 });

    for (GeometricObject * object : v) {
        Cloneable * clone { object->clone() };

        if (Serializeable * s { dynamic_cast<Serializeable*>(object) }) {
            std::cout << s->str() << std::endl;
        }

        if (dynamic_cast<Point*>(object)) {
            std::cout << "A point!" << std::endl;
        } else if (dynamic_cast<Line*>(object)) {
            std::cout << "A line!" << std::endl;
        } else if (dynamic_cast<Rectangle*>(object)) {
            std::cout << "A rectangle" << std::endl;
        } else if (dynamic_cast<Circle*>(object)) {
            std::cout << "A circle" << std::endl;
        }


        delete object;
        delete clone;
    }

    return 0;
}
