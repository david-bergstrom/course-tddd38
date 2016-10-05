#ifndef LINE_H
#define LINE_H

#include <cmath>

#include "geometric_object.h"

struct Line : GeometricObject {
    Line(double x1, double y1, double x2, double y2)
        : x1 { x1 }, y1 { y1 }, x2 { x2 }, y2 { y2 } {};

    double x1, y1, x2, y2;

    double length() {
        return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    }

    // Implementing Cloneable
    Line * clone() const { return new Line { x1, y1, x2, y2 }; };

    // Implementing Serializeable
    std::string str() {
        return "Line{x1=" + 
            std::to_string(x1) + "y1=" + std::to_string(y1) + "x2=" +
            std::to_string(x2) + "y2=" + std::to_string(y2) +  "}"; };
};

#endif
