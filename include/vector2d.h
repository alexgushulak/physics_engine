// vector2d.h
#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
public:
    double x, y;
    Vector2D(double x_val, double y_val);

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    double dot(const Vector2D& other) const;
};

#endif // VECTOR2D_H