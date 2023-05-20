#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include "Team.hpp"
#include <vector>

using namespace std;

namespace ariel{
    class SmartTeam : public Team
    {
    private:
      
    public:
        SmartTeam(Character *leader);
        ~SmartTeam();
    };
}