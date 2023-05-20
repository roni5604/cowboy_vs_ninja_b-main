#include "Team2.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader)
    {
    }
    Team2::~Team2()
    {
    }

    void Team2::attack(Team *enemy) 
    {
        if (enemy == nullptr)
        {
            throw std::invalid_argument("enemy is null");
        }
        else
        {
            if (this->leader->get_Hit_points() <= 0)
            {
                // find a new leader
                int minDistance = INFINITY;
                Character *pCharacter;
                bool notfound = true;
                for (size_t i = 0; i < this->fighters.size(); i++)
                {
                    if (this->fighters[i]->get_Hit_points() > 0)
                    {
                        if (this->leader != this->fighters[i])
                        {
                            notfound = false;
                            int distance = this->leader->getLocation().distance(this->fighters[i]->getLocation());
                            if (distance < minDistance)
                            {
                                minDistance = distance;
                                pCharacter = this->fighters[i];
                            }
                        }
                    }
                }
                if (notfound)
                {
                    throw std::runtime_error("all team is dead");
                }
                else
                {
                    this->set_leader(pCharacter);
                }
            }
            // found a leader

            // find the closest enemy to the leader and attack him
            int location_leader = this->findClosestEnemy(this->get_leader(), enemy);
            if (location_leader == -1)
            {
                throw std::runtime_error("all enemy team is dead");
            }
            Character *pNearEnemy = enemy->get_fighters()[(size_t)location_leader];
            

            for (size_t i = 0; i < this->fighters.size(); i++)
            {
                if (pNearEnemy->get_Hit_points() <= 0)
                {
                    location_leader = this->findClosestEnemy(this->leader, enemy);
                    if (location_leader == -1)
                    {
                        break;
                    }
                    pNearEnemy = enemy->get_fighters()[(size_t)location_leader];
                }

                if (this->fighters[i]->get_Hit_points() > 0)
                {
                    if (this->fighters[i]->isNinja())
                    {
                        Ninja *pNinjaToAttack = dynamic_cast<Ninja *>(this->fighters[i]);
                        if (pNinjaToAttack->getLocation().distance((*pNearEnemy).getLocation()) <= 1)
                        {
                            pNinjaToAttack->slash(pNearEnemy);
                        }
                        else
                        {
                            pNinjaToAttack->move(pNearEnemy);
                        }
                    }
                    else
                    {
                        Cowboy *pCowboyToAttack = dynamic_cast<Cowboy *>(this->fighters[i]);
                        pCowboyToAttack->shoot(pNearEnemy);
                    }
                }
            }
        }
    }
    void Team2::print()
    {
        cout << "Team2:" << endl;
        for (size_t i = 0; i < this->fighters.size(); i++)
        {
            this->fighters[i]->print();
        }
    }
}