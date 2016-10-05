#ifndef POINT_H
#define POINT_H

#include "geometric_object.h"

struct Point : public GeometricObject {
    Point(double x, double y) : x { x }, y { y } {};
    double x;
    double y;

    // Implementing Cloneable
    Point * clone() const { return new Point { x, y }; };

    // Implementing Serializeable
    std::string str() {
            return "Point{x=" + std::to_string(x) + "y=" + 
                    std::to_string(y) + "}";
    };
};

#endif
