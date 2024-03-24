#include "node.h"
#include <iostream>

int main() {
    const int HEIGHT = 5;
    const int WIDTH = 5;
    Node nodeMatrix[HEIGHT][WIDTH];
    
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            nodeMatrix[i][j] = Node(i, j);
        }
    }

    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            std::cout << "Node at (" << i << ", " << j << ") has center_x_pos: " << nodeMatrix[i][j].center_x_pos << " and center_y_pos: " << nodeMatrix[i][j].center_y_pos << std::endl;
        }
    }

    std::cout << "Node::staticVariable: " << nodeMatrix[0][0].staticVariable << std::endl;
    Node::staticVariable = 10;
    std::cout << "Node::staticVariable: " << nodeMatrix[0][0].staticVariable << std::endl;
    
    return 0;
}