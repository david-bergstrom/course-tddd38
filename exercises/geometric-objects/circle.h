#ifndef CIRCLE_H
#define CIRCLE_H

constexpr double PI = 3.1415;

class Circle {
    public:
        Circle() : radius{ 1 } {};
        Circle(double r) : radius { r } {};
        double getRadius() { return radius; };
        double getArea() { return PI * radius * radius; }; 
        double getPerimeter() { return PI * radius * 2; };
    private:
        double radius;
};

#endif
