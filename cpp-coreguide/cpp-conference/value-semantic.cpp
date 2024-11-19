#include <iostream>
#include <variant>
#include <vector>

class Circle {
public:
    explicit Circle(double radius) : radius(radius) {}
    
    double getArea() const {
        return 3.14159 * radius * radius;
    }

    double getRadius() const {
        return radius;
    }

private:
    double radius;
};

class Rectangle {
public:
    explicit Rectangle(double width, double height) : width(width), height(height) {}
    
    double getArea() const {
        return width * height;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

private:
    double width;
    double height;
};

class Draw {
public:
    void operator()(Circle const& circle) const {
        std::cout << "Drawing Circle with radius: " << circle.getRadius()
                  << " and area: " << circle.getArea() << std::endl;
    }

    void operator()(Rectangle const& rectangle) const {
        std::cout << "Drawing Rectangle with width: " << rectangle.getWidth()
                  << ", height: " << rectangle.getHeight()
                  << " and area: " << rectangle.getArea() << std::endl;
    }
};

using Shape = std::variant<Circle, Rectangle>;

void drawAllShapes(std::vector<Shape> const& shapes) {
    for (auto const& shape : shapes) {
        std::visit(Draw{}, shape);  // Calls the correct operator() based on the shape type
    }
}

int main() {
    using Shapes = std::vector<Shape>;
    // Creating some shapes
    Shapes shapes;
    shapes.emplace_back(Circle{2.0});
    shapes.emplace_back(Rectangle{1.5, 2.3});
    shapes.emplace_back(Circle{4.2});

    // Drawing all shapes
    drawAllShapes(shapes);
    
    return 0;
}
