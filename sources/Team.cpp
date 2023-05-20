#include "Team.hpp"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

namespace ariel
{
    Team::Team(Character *leader)
    {
        if (leader->get_isInTeam() == 1)
        {
            throw std::runtime_error("Character is already in a team");
        }
        else
        {
            this->leader = leader;
            this->fighters.push_back(leader);
            leader->set_isInTeam(1);
        }
    }
    Team::~Team()
    {
        for (size_t i = 0; i < this->fighters.size(); i++)
        {
            this->fighters[i]->set_isInTeam(0);
            this->remove(this->fighters[i]);
        }
    }
    void Team::add(Character *fighter_to_add)
    {
        if (fighter_to_add->get_isInTeam() == 1)
        {
            throw std::runtime_error("Character is already in a team");
        }
        else
        {
            if (this->fighters.size() < 10)
            {
                this->fighters.push_back(fighter_to_add);
                fighter_to_add->set_isInTeam(1);
            }
            else
            {
                throw std::runtime_error("Team is full");
            }
        }
    }
    void Team::attack(Team *enemy)
    {
        if (enemy == nullptr)
        {
            throw std::invalid_argument("enemy is null");
        }
        else
        {
            if (this->get_leader()->get_Hit_points() <= 0)
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
            Character *pNearEnemy = enemy->fighters[(size_t)location_leader];

            for (size_t i = 0; i < this->fighters.size(); i++)//for all the cowboys
            {
                if (pNearEnemy->get_Hit_points() <= 0)
                {
                    location_leader = this->findClosestEnemy(this->leader, enemy);
                    if (location_leader == -1)
                    {
                        break;
                    }
                    pNearEnemy = enemy->fighters[(size_t)location_leader];
                }
                if (this->fighters[i]->get_Hit_points() > 0)
                {
                   if (this->fighters[i]->isNinja()==false)
                    {
                        Cowboy *pCowboyToAttack = dynamic_cast<Cowboy *>(this->fighters[i]);
                        pCowboyToAttack->shoot(pNearEnemy);
                    }
                }
            }
             for (size_t i = 0; i < this->fighters.size(); i++)//for all the ninjas
            {
                if (pNearEnemy->get_Hit_points() <= 0)
                {
                    location_leader = this->findClosestEnemy(this->leader, enemy);
                    if (location_leader == -1)
                    {
                        break;
                    }
                    pNearEnemy = enemy->fighters[(size_t)location_leader];
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
                }
            }
        }
        
    }
    void Team::print()
    {
        for (size_t i = 0; i < fighters.size(); i++)
        {
            if (fighters[i]->isNinja())
            {
                fighters[i]->print();
            }
        }
        for (size_t i = 0; i < fighters.size(); i++)
        {
            if (fighters[i]->isNinja() == false)
            {
                fighters[i]->print();
            }
        }

    }
    void Team::remove(Character *fighter_to_remove)
    {
        for (size_t i = 0; i < fighters.size(); i++)
        {
            if (fighters[i] == fighter_to_remove)
            {
                fighters.erase(fighters.begin() + (int)i);
            }
        }
    }
    Character *Team::get_leader()
    {
        return this->leader;
    }
    void Team::set_leader(Character *new_leader)
    {
         this->leader = new_leader;
    }
    vector<Character *> Team::get_fighters()
    {
        return this->fighters;
    }
    Character *Team::getByOrder()
    {
        return this->leader;
    }
    int Team::stillAlive()
    {
        int counter = 0;
        for (size_t i = 0; i < fighters.size(); i++)
        {
            if (fighters[i]->get_Hit_points() > 0)
            {
                counter++;
            }
        }
        return counter;
    }
    int Team::findClosestEnemy(Character *leader_my_team, Team *enemy_team)
    {
        int minimumDistance = __INT_MAX__;
        int location = -1;
        for (size_t i = 0; i < enemy_team->fighters.size(); i++)
        {
            if (enemy_team->fighters[i]->get_Hit_points() > 0)
            {
                double distance = leader_my_team->getLocation().distance(enemy_team->fighters[i]->getLocation());
                if (distance < minimumDistance)
                {
                    location = i;
                    minimumDistance = distance;
                }
            }
        }
        return location;
    }
}