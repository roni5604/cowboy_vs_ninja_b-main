#include "Cowboy.hpp"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    Cowboy::Cowboy(Point Current_location, string name) : Character(Current_location, name, 110), num_of_bullets(6)
    {
    }

    Cowboy::Cowboy(string name, Point Current_location) : Character(Current_location, name, 110), num_of_bullets(6)
    {
    }

    Cowboy::~Cowboy()
    {
    }

    void Cowboy::shoot(Character *enemy)
    {
        if (this == enemy)
        {
            throw std::runtime_error("cant shoot yourself");
        }
        else
        {
            if (this->isAlive() && (enemy->get_Hit_points() > 0))
            {
                if (num_of_bullets > 0)
                {
                    num_of_bullets--;
                    enemy->set_Hit_points(enemy->get_Hit_points() - 10);
                }
                else
                {
                    this->reload();
                }
            }
            else
            {
                if (this->isAlive())
                {
                    throw std::runtime_error("cant shoot when enemy dead");
                }
                else
                {
                    throw std::runtime_error("cant shoot when you dead");
                }
            }
        }
    }
    string Cowboy::print() const
    {
        return "C";
    }

    int Cowboy::get_num_of_bullets()
    {
        return num_of_bullets;
    }
    void Cowboy::reload()
    {
        if (this->isAlive())
        {
            num_of_bullets = 6;
        }
        else
        {
            throw std::runtime_error("cant reload when you dead");
        }
    }
    bool Cowboy::isAlive()
    {
        if (this->get_Hit_points() > 0)
        {
            return true;
        }
        return false;
    }
    bool Cowboy::hasboolets()
    {
        if (num_of_bullets > 0)
        {
            return true;
        }
        return false;
    }
    bool Cowboy::isNinja() const
    {
        return false;
    }
}