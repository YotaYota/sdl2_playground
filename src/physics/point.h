#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x;
    int y;

public:
    Point(Point& point);
    Point operator=(Point& point) = delete;

    Point();
    Point(int x, int y);

    int getX();
    int getY();

    void setX(const int x);
    void setY(const int y);
};

#endif /* POINT_H */

