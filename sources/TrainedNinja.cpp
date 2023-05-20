#include "TrainedNinja.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
   
    TrainedNinja::TrainedNinja(string name, Point Current_location):Ninja(name,Current_location)
    {
        this->set_Hit_points(120) ;
        this->set_speed(12);
    }
    
}