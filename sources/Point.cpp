#include <iostream>
#include <cmath>
#include "Point.hpp"
using namespace std;

namespace ariel
{

    Point::Point(double x_Location, double y_Location) : x_Location(x_Location), y_Location(y_Location) {}

    double Point::distance(const Point &other) const
    {
        return std::sqrt(std::pow(x_Location - other.x_Location, 2) + std::pow(y_Location - other.y_Location, 2));
    }

    Point::Point(const Point &other)
    {
        x_Location = other.x_Location;
        y_Location = other.y_Location;
    }

    Point &Point::operator=(const Point &other)
    {
        if (this != &other)
        {
            x_Location = other.x_Location;
            y_Location = other.y_Location;
        }
        return *this;
    }

    Point::~Point()
    {
        x_Location = 0;
        y_Location = 0;
    }

    void Point::print() const
    {
        std::cout << "(" << x_Location << ", " << y_Location << ")" << std::endl;
    }

    Point Point::moveTowards(Point &source_point,Point &other_point ,double maxDistance) 
    {
        if (maxDistance < 0)
        {
            throw std::invalid_argument( "maxDistance must be positive");
        }
        if (source_point.x_Location == other_point.x_Location && source_point.y_Location == other_point.y_Location)
        {
            return other_point;
        }
        double distance = source_point.distance(other_point);
        if (distance <= maxDistance)
        {
            return other_point;
        }
        double ratio = maxDistance / distance;
        double x = source_point.x_Location + (other_point.x_Location - source_point.x_Location) * ratio;
        double y = source_point.y_Location + (other_point.y_Location - source_point.y_Location) * ratio;
        return Point(x, y);
     
    }

    double Point::getX() const
    {
        return x_Location;
    }

    double Point::getY() const
    {
        return y_Location;
    }

    void Point::setX(double x_Location)
    {
        this->x_Location = x_Location;
    }

    void Point::setY(double y_Location)
    {
        this->y_Location = y_Location;
    }
}
