// square_element.h
#ifndef SQUARE_ELEMENT_H
#define SQUARE_ELEMENT_H

#include <array>
#include "vector2d.h"

class SquareElement {
public:
    SquareElement(const Vector2D& n1, const Vector2D& n2, const Vector2D& n3, const Vector2D& n4);
    double area() const;
    double m_perimeter();

private:
    std::array<Vector2D, 4> nodes;
    static const int a = 10;
    static const int b = 20;
};

#endif // SQUARE_ELEMENT_H