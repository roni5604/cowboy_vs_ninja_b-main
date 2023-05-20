#include "YoungNinja.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{

    YoungNinja::YoungNinja(string name, Point Current_location):Ninja(name,Current_location)
    {
        this->set_Hit_points(100) ;
        this->set_speed(14);
    }
    
}