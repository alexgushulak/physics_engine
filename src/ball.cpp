#include "ball.h"

const double gravity = 9.8;
const double timeStep = 1;

Ball::Ball() {
    x = 0.0;
    y = 0.0;
    vy = 0.0;
    vx = 0.0;
}

void Ball::updatePosition() {
    vy -= gravity * timeStep;
    y += vy * timeStep;
}

