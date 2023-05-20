#pragma once
#include "Ninja.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    private:

    public:
            TrainedNinja( string name, Point Current_location);
    };
    
}