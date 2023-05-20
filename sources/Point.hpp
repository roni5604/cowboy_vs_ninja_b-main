#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x_Location;
        double y_Location;

    public:
        Point(double x_Location = 0, double y_Location = 0);
        double distance(const Point &other) const;
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();
        void print() const;
        static Point moveTowards( Point &source_point,Point &other_point, double maxDistance);
        double getX() const;
        double getY() const;
        void setX(double x_Location);
        void setY(double y_Location);
    };

}
