#pragma once
#include "Character.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(string name, Point Current_location);
        ~Ninja();
        void move(Character *enemy);
        void slash(Character *enemy);
        int get_speed();
        string print() const override;
        void set_speed(int speed);
        bool isAlive();
        bool isNinja() const override;
    };

}