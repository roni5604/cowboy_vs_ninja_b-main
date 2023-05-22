#include "SmartTeam.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : Team(leader)
    {
    }
    SmartTeam::~SmartTeam()
    {
    }

    void SmartTeam::attack(Team *enemy)
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
            if (this->findClosestEnemy(this->get_leader(), enemy) == -1)
            {
                throw std::runtime_error("all enemy team is dead");
            }
            else
            {
                // find the closest enemy to the all team and attack him
                int location_leader = this->findClosestEnemy_toNinja(enemy);
                Character *pNearEnemy = enemy->get_fighters()[(size_t)location_leader];

                for (size_t i = 0; i < this->fighters.size(); i++)
                {
                    if (pNearEnemy->get_Hit_points() <= 0)
                    {
                        location_leader = this->findClosestEnemy_toNinja(enemy);
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
    }

    void SmartTeam::print()
    {
        cout << "Smart Team:" << endl;
        for (size_t i = 0; i < fighters.size(); i++)
        {
            if (fighters[i]->get_Hit_points() > 0)
            {
                cout << fighters[i]->print() << endl;
            }
        }
        for (size_t i = 0; i < fighters.size(); i++)
        {
            if (fighters[i]->get_Hit_points() <= 0)
            {
                cout << fighters[i]->print() << endl;
            }
        }
    }

    int SmartTeam::findClosestEnemy_toNinja(Team *enemy)
    {
        if (this->findClosestEnemy(this->get_leader(), enemy) == -1)
        {
            return -1;
        }
        else
        {
            // Create an array of integers with size equal to fighters.size()
            size_t size_enemy = (*enemy).get_fighters().size();
            int* array = new int[size_enemy];

            // Initialize all elements to 0
            for (size_t i = 0; i < size_enemy; i++)
            {
                array[i] = 0;
            }
            bool ninjaNotFound = true;
            // Find the closest enemy to each fighter
            for (size_t i = 0; i < fighters.size(); i++)
            {
                if ((fighters[i]->get_Hit_points() > 0)&&(fighters[i]->isNinja()))
                {
                    ninjaNotFound = false;
                    size_t enemy_location = (size_t)this->findClosestEnemy(fighters[i], enemy);
                    array[enemy_location]++;
                    if(fighters[i]->getLocation().distance(enemy->get_fighters()[enemy_location]->getLocation()) <= 1)
                    {
                        array[enemy_location]+=2;
                    }
                }
            }
            int closestEnemy = 0;
            for (size_t i = 0; i < fighters.size(); i++)
            {
                if (array[i] > array[closestEnemy])
                {
                    closestEnemy = i;
                }
            }
            delete[] array;
            if (ninjaNotFound)
            {
                return find_min_life_enemy(enemy);
            }
            else
            {
                return closestEnemy;
            }
        }
    }
    int SmartTeam::find_min_life_enemy(Team *enemy)
    {
        int min_life = __INT_MAX__;
        int location_min_life = 0;
        for (size_t i = 0; i < enemy->get_fighters().size(); i++)
        {
            if ((enemy->get_fighters()[i]->get_Hit_points() > 0)&&(enemy->get_fighters()[i]->get_Hit_points() < min_life))
            {
                min_life = enemy->get_fighters()[i]->get_Hit_points();
                location_min_life = i;
            }
        }
        return location_min_life;
    }
}