#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "geometric_object.h"

/*
 * Defines a Rectangle with a given width and height
 */
class Rectangle : public GeometricObject {
    public:
        Rectangle() : width { 1 }, height { 1 } {};
        Rectangle(double w, double h) : width { w }, height { h } {};
        double getWidth() { return width; }
        double getHeight() { return height; }
        double getArea() { return width * height; }
        double getPerimeter() { return 2 * width + 2 * height; }

         // Implementing Cloneable
        Rectangle * clone() const { return new Rectangle { width, height }; };

        // Implementing Serializeable
        std::string str() {
            return "Rectangle{width=" + std::to_string(width) +
                "height=" + std::to_string(height) + "}";
        };
       
    private:
        double width, height;
};

#endif
