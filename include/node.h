#ifndef NODE_H
#define NODE_H

class Node {
public:
    static int staticVariable;
    Node();
    Node(double center_x_pos, double center_y_pos);
    double center_x_pos;
    double center_y_pos;
    double get_pressure();
    double vy, vx;
    double density_y, density_x;
    double dx, dy;
private:
    double pressure;
};

#endif