#ifndef CIRCLE_H
#define CIRCLE_H

#include "geometric_object.h"

constexpr double PI = 3.1415;

class Circle : GeometricObject {
    public:
        Circle() : radius{ 1 } {};
        Circle(double r) : radius { r } {};
        double getRadius() { return radius; };
        double getArea() { return PI * radius * radius; }; 
        double getPerimeter() { return PI * radius * 2; };

        // Implementing Cloneable
        Circle * clone() const { return new Circle { radius }; };

        // Implementing Serializeable
        std::string str() {
            return "Circle{radius=" + std::to_string(radius) + "}";
        };
    private:
        double radius;
};

#endif
