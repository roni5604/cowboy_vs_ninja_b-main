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
        void attack(Team *enemy) override;
        void print() override;
        int findClosestEnemy_toNinja(Team *enemy);
        int find_min_life_enemy(Team *enemy);
    };
}