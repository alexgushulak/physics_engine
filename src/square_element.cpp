// square_element.cpp
#include "square_element.h"
#include <cmath>
#include <iostream>

SquareElement::SquareElement(const Vector2D& n1, const Vector2D& n2, const Vector2D& n3, const Vector2D& n4)
    : nodes{n1, n2, n3, n4} {
    std::cout << "SquareElement constructor called" << std::endl;
}

double SquareElement::area() const {
    return std::abs((nodes[0].x - nodes[2].x) * (nodes[1].y - nodes[2].y) -
                    (nodes[1].x - nodes[2].x) * (nodes[0].y - nodes[2].y));
}

double SquareElement::m_perimeter() {
    return a * b;
}