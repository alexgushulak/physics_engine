#ifndef BALL_H
#define BALL_H

class Ball {
    public:
        double x,y; // coords
        double vy, vx; // velocity
    
    Ball();

    void updatePosition();
};

#endif