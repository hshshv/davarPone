#include "davarPone.h"
#include <iostream>

#define PI 3.14159265359

double davarPone::direction()
{
    return myDirection;
}
void davarPone::direct(double newDirection)
{
    myDirection = inPositiveAngel(newDirection);
}
void davarPone::step(double steps)
{
    x += steps * cos(radiansOf(myDirection));
    y += steps * sin(radiansOf(myDirection));
}
void davarPone::turnTo(double newDirection)
{
    myDirection = fmod(newDirection, 360);
}
void davarPone::turn(double additionalDegrees)
{
    turnTo(myDirection + additionalDegrees);
}
void davarPone::goTo(double newX, double newY)
{
    x = newX;
    y = newY;
}
bool davarPone::isBetween(double x1, double y1, double x2, double y2)
{
    return (((x > x1 && x < x2) || (x < x1&& x > x2)) && ((y > y1 && y < y2) || (y < y1&& y > y2)));
}
double davarPone::distanceFrom(double x1, double y1)
{
    return(sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)));
}
void davarPone::print()
{
    std::cout << "X= " << x << ", Y= " << y << ". direction: " << myDirection << std::endl;
}
double davarPone::radiansOf(double degrees)
{
    return (PI * (degrees / 180));
}
void davarPone::reset()
{
    myDirection = 0;
    x = 0;
    y = 0;
}
double davarPone::AbsDirectionTo(double targetX, double targetY)
{
    if (x == targetX && y == targetY)
    {
        return(0.0f);
    }
    double theDirection = 180 * atan((targetY - y) / (targetX - x)) / PI;
    if (x > targetX)
    {
        theDirection += 180;
    }
    return (inPositiveAngel(theDirection));
}
double davarPone::ReletiveDirectionTo(double targetX, double targetY)
{
    return(inPositiveAngel(AbsDirectionTo(targetX, targetY) - direction()));
}

double davarPone::inPositiveAngel(double drctn)
{
    drctn = fmod(drctn, 360.0);
    if (drctn >= 0)
    {
        return drctn;
    }
    return (inPositiveAngel(drctn + 360));
}