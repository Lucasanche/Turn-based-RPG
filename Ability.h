#pragma once
#ifndef ABILITY_H
#define ABILITY_H

#include "Dragon.h"

class Ability
{
protected:
    std::string _name;
    std::string _description;
    int _element1;
    int _element2;
    int _id;
    int _mpCost;

public:
    Ability();
    virtual void Mostrar() = 0;
    virtual ~Ability(){}
};

#endif