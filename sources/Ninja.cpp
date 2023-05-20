#include "Ninja.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    Ninja::Ninja(string name, Point Current_location) : Character(Current_location, name), speed(2)
    {
    }

    Ninja::~Ninja()
    {
    }

    void Ninja::move(Character *enemy)
    {
        if (this->isAlive() && (enemy->get_Hit_points() > 0))
        {
            moveTowards(enemy->getLocation(), this->get_speed());
        }
    }

    void Ninja::slash(Character *enemy)
    {
        if (this == enemy)
        {
            throw std::runtime_error("cant slash yourself");
        }
        else
        {
            if (this->isAlive() && (enemy->get_Hit_points() > 0))
            {
                if (this->getLocation().distance(enemy->getLocation()) < 1)
                {
                    enemy->set_Hit_points(enemy->get_Hit_points() - 40);
                }
            }
            else
            {
                if (this->isAlive())
                {
                    throw std::runtime_error("cant slash when enemy dead");
                }
                else
                {
                    throw std::runtime_error("cant slash when you dead");
                }
            }
        }
    }
    int Ninja::get_speed()
    {
        return this->speed;
    }
    void Ninja::set_speed(int speed)
    {
        this->speed = speed;
    }
    bool ariel::Ninja::isAlive()
    {
        if (this->get_Hit_points() > 0)
        {
            return true;
        }
        return false;
    }

    bool Ninja::isNinja() const
    {
        return true;
    }
}