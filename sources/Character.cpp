#include "Character.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    Character::Character(Point Current_location, string name) : Current_location(Current_location), name(name), hit_points(0) ,isInTeam(0)
    {
    }
    Character::Character(string name, Point Current_location): Current_location(Current_location), name(name), hit_points(0),isInTeam(0)
    {
    }
    Character::Character(Point Current_location, string name, int hit_points) : Current_location(Current_location), name(name), hit_points(hit_points),isInTeam(0)
    {
    }

    Character::Character(Character const &other)
    {
        Current_location = other.Current_location;
        name = other.name;
        hit_points = other.hit_points;
        isInTeam = other.isInTeam;
    }

    Character &Character::operator=(Character const &other)
    {
        if (this != &other)
        {
            Current_location = other.Current_location;
            name = other.name;
            hit_points = other.hit_points;
            isInTeam = other.isInTeam;
        }
        return *this;
    }
  
    Character::~Character()
    {
        this->name = "";
        this->hit_points = 0;
        this->Current_location = Point(0, 0);
    }
    double Character::distance(Character *other)
    {
        return Current_location.distance(other->Current_location);
    }
    void Character::hit(int damage)
    {
        if (damage < 0)
        {
            throw std::invalid_argument("damage cant be negative");
        }
        else{
            if (damage > hit_points)
            {
                hit_points = 0;
            }
            else
            {
                hit_points -= damage;
            }
        }
    }
    string Character::getName()
    {
        return name;
    }
    int Character::get_Hit_points()
    {
        return hit_points;
    }
    Point Character::getLocation()
    {
        return Current_location;
    }

    string Character::print()
    {
        string str_to_return = "";
        
        if (this->isNinja())
        {
            str_to_return += " N ";
        }
        else{
            str_to_return += " C ";
        }
        if(this->get_Hit_points()>0)
        {
        str_to_return += "name: " + name + "\n";
        str_to_return += "hit_points: " + to_string(hit_points) + "\n";
        str_to_return += "Current_location: " + Current_location.print() + "\n";
        }
        else{
            str_to_return += "(" + name + ")\n";
        }
        return str_to_return;
    }

    void Character::moveTowards(Point dest, double maxDistance)
    {
        if (Current_location.distance(dest) <= maxDistance)
        {
            Current_location = dest;
        }
        else
        {
            Current_location = Current_location.moveTowards(Current_location,dest, maxDistance);
        }
    }
    void Character::setLocation(Point newLocation)
    {
        Current_location = newLocation;
    }
    void Character::setName(string newName)
    {
        name = newName;
    }
    void Character::set_Hit_points(int new_Hit_points)
    {
        hit_points = new_Hit_points;
    }
    void Character::set_isInTeam(int isInTeam)
    {
        this->isInTeam = isInTeam;
    }
    int Character::get_isInTeam()
    {
        return this->isInTeam;
    }
}
