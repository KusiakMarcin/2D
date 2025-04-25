//
// Created by kusia on 25.04.2025.
//

#include "Phisical.h"

void Phisical::setVelocityX(double velocity) {
    this->xVelocity = velocity;
}
void Phisical::setVelocityY(double velocity) {
    this->yVelocity = velocity;
}

double Phisical::getVelocityY() {
    return yVelocity;

}
double Phisical::getVelocityX() {
    return  xVelocity;
}

bool Phisical::Colision(Point point) {
    return false;
}

bool Phisical::Colision(Line line) {
    return false;
}