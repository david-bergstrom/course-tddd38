#ifndef RECTANGLE_H
#define RECTANGLE_H

/*
 * Defines a Rectangle with a given width and height
 */
class Rectangle {
    public:
        Rectangle() : width { 1 }, height { 1 } {};
        Rectangle(double w, double h) : width { w }, height { h } {};
        double getWidth() { return width; }
        double getHeight() { return height; }
        double getArea() { return width * height; }
        double getPerimeter() { return 2 * width + 2 * height; }
    private:
        double width, height;
};

#endif
