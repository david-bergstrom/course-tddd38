#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

/*
 * Defines a Triangle where a, b and c are its sides length
 */
class Triangle {
    public:
        Triangle() : a { 1 }, b { 1 }, c { 1 } {};
        Triangle(double a, double b, double c) : a { a }, b { b }, c { c } {};
        double getA() { return a; }
        double getB() { return b; }
        double getC() { return c; }
        double getArea() {
            // Uses Heron's formula, read more
            // here:http://www.mathopenref.com/heronsformula.html
            double p = (a + b + c) / 2;
            return std::sqrt(p * (p - a) * (p - b) * (p - c));
        }
        double getPerimeter() {
            return a + b + c;
        }
    private:
        double a, b, c;
}

#endif
