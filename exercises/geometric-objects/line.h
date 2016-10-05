#ifndef LINE_H
#define LINE_H

#include <cmath>

struct Line {
    double x1, y1, x2, y2;

    double length() {
        return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    }
};

#endif
