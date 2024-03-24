#include "node.h"

Node::Node() {
    center_x_pos = 0;
    center_y_pos = 0;
}

Node::Node(double center_x_pos, double center_y_pos) {
    this->center_x_pos = center_x_pos;
    this->center_y_pos = center_y_pos;
}

double Node::get_pressure() {
    return pressure;
}