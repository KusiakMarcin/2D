//
// Created by kusia on 25.04.2025.
//

#ifndef INC_2D_PHISICAL_H
#define INC_2D_PHISICAL_H
#include "Line.h"

class Phisical {

private:
    double xVelocity,yVelocity;
    bool phisical;
public:
    void setVelocityX(double velocity);
    void setVelocityY(double velocity);
    double getVelocityX();
    double getVelocityY();
    virtual bool Colision(Point point);
    virtual bool Colision(Line line);
};


#endif //INC_2D_PHISICAL_H
