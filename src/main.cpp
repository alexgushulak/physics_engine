#include <iostream>
#include "ball.h"


int main() {
    Ball ball;

    for (int i = 0; i < 50; i++) {
        ball.updatePosition();
        std::cout << "Time: " << i << " X: " << ball.x << " Y: " << ball.y << std::endl; 
    }

    return 0;
}