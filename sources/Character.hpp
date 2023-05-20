#pragma once
#include <string>
#include <iostream>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point Current_location;
        string name;
        int hit_points;
        int isInTeam;
    public:
        Character( Point Current_location, string name);
        Character( string name,Point Current_location);
        Character( Point Current_location, string name, int hit_points);
        Character(Character const &other);
        Character &operator=(Character const &other);
        ~Character();
        double distance(Character *other);
        void hit(int damage);
        string getName();
        int get_Hit_points();
        Point getLocation();
        virtual string print() ;
        void moveTowards(Point dest, double maxDistance);
        void setLocation(Point newLocation);
        void setName(string newName);
        void set_Hit_points(int new_Hit_points);
        void set_isInTeam(int isInTeam);
        int get_isInTeam();
        virtual bool isNinja() const = 0;
        
    };
    
}