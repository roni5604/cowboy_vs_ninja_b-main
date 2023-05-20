#include "OldNinja.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    
    OldNinja::OldNinja(string name, Point Current_location):Ninja(name, Current_location)
    {
        this->set_Hit_points(150);        
        this->set_speed(8);
    }
}