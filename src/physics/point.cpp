#include "point.h"

Point::Point()
    : x(0)
    , y(0)
{
}

Point::Point(int x, int y)
    : x(x)
    , y(y)
{
}

Point::Point(Point& point)
    : Point(point.getX(), point.getY())
{
}

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

void Point::setX(const int x)
{
    this->x = x;
}

void Point::setY(const int y)
{
    this->y = y;
}

