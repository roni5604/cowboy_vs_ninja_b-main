#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include "Team.hpp"
#include <vector>

using namespace std;

namespace ariel{
    class Team2 : public Team
    {
    private:
    public:
        Team2(Character *leader);
        ~Team2();
        void attack(Team *enemy) override;
        void print() override;
    };
}