// vector2d.cpp
#include "vector2d.h"

Vector2D::Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

double Vector2D::dot(const Vector2D& other) const {
    return x * other.x + y * other.y;
}