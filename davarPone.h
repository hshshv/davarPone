#pragma once


class davarPone
{
public:
    double x = 0.0;
    double y = 0.0;
    double myDirection = 0.0;

    double direction();
    void direct(double newDirection);
    void step(double steps);
    void turnTo(double newDirection);
    void turn(double additionalDegrees);
    void goTo(double newX, double newY);
    bool isBetween(double x1, double y1, double x2, double y2);
    double distanceFrom(double x1, double y1);
    void print();
    static double radiansOf(double degrees);
    void reset();
    double AbsDirectionTo(double targetX, double targetY);
    double ReletiveDirectionTo(double targetX, double targetY);
    static double inPositiveAngel(double drctn);
};

