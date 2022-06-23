#pragma once
class Ability
{
protected:
    float _damage;
    int _element;
    int _status;

public:
    Ability();
    
    enum elements
    {
        neutral = 0,
        fire,
        water,
        air,
        earth,
        poison,
        burn
    };
    virtual ~Ability(){}
};