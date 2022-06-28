#pragma once
#ifndef ABILITY_H
#define ABILITY_H

#include "Dragon.h"

class Ability
{
protected:
    sf::Text _name;
    sf::Text _description;
    elements _element1;
    elements _element2;
    int _id;
    int _mpCost;

public:
    Ability();
    void setName(sf::String name) { _name.setString(name); }
    void setDescription(sf::String description) { _description.setString(description); }
    void setElements(elements element1, elements element2);
    void setID(int id) { _id = id; }
    virtual void setMagicDamage(int magicDamage) = 0;
    virtual void setMpCost(int mpCost) = 0;
    virtual void setDamageMultiplier(bool status) = 0;
    virtual void setVampireishon(bool status) = 0;
    virtual void setStun(bool status) = 0;
    virtual void setReducePD(bool status) = 0;
    virtual void setReduceMR(bool status) = 0;
    virtual void setReduceAtt(bool status) = 0;
    virtual void setBurns(bool status) = 0;
    virtual void setPoison(bool status) = 0;
    virtual void setTrueDamash(bool status) = 0;
    virtual float useAbility(Dragon& dragon) = 0;
    virtual ~Ability(){}
};

#endif