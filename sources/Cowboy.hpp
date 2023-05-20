#pragma once
#include "Character.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int num_of_bullets;

    public:
        Cowboy(Point Current_location, string name);
        Cowboy( string name,Point Current_location);
        ~Cowboy();
        void shoot(Character *enemy);
        string print() const override;
        int get_num_of_bullets();
        void reload();
        bool isAlive();
        bool hasboolets();
        bool isNinja() const override;
    };
}