#pragma once
#ifndef ABILITY_H
#define ABILITY_H

class Ability
{
private:
    sf::Text _name;
    sf::Text _description;
    elements _element1;
    elements _element2;
    int _id;
    int _mpCost;

    //AbilitySupport
    bool negativeStates[6];
    bool positiveStates[10];



    //1    _increasePD,
    //2    _increaseMR,
    //3    _waterResist,
    //4    _fireResist,
    //5    _airResist,
    //6    _earthResist,
    //7    _increaseMD,
    //8    _heal,
    //9    _restore,
    //10    _doton;//CHEQUEAR

    //AbilityMagic
    int _magicDamage;
    bool _damageMultiplier,
        _vampireishon,
        _stun,
        _reducePD,
        _reduceMR,
        _reduceAtt,
        _burns,
        _poison,
        _truedamash;

public:
    Ability();
    void setName(sf::String name) { _name.setString(name); }
    void setDescription(sf::String description) { _description.setString(description); }
    void setElements(elements element1, elements element2);
    void setID(int id) { _id = id; }
    sf::String getName() { return _name.getString(); }
    virtual ~Ability() {}

    //AbilityMagic
    void setMagicDamage(int magicDamage) { _magicDamage = magicDamage; }
    void setMpCost(int mpCost) { _mpCost = mpCost; }
    void setDamageMultiplier(bool status) { _damageMultiplier = status; }
    void setVampireishon(bool status) { _vampireishon = status; }
    void setStun(bool status) { _stun = status; }
    void setReducePD(bool status) { _reducePD = status; }
    void setReduceMR(bool status) { _reduceMR = status; }
    void setReduceAtt(bool status) { _reduceAtt = status; }
    void setBurns(bool status) { _burns = status; }
    void setPoison(bool status) { _poison = status; }
    void setTrueDamash(bool status) { _truedamash = status; }
    

    //AbilitySupport
    void setIncreasePD(bool status) { _increasePD = status; }
    void setIncreaseMR(bool status) { _increaseMR = status; }
    void setWaterResist(bool status) { _waterResist = status; }
    void setFireResist(bool status) { _fireResist = status; }
    void setAirResist(bool status) { _airResist = status; }
    void setEarthResist(bool status) { _earthResist = status; }
    void setHeal(bool status) { _heal = status; }
    void setRestore(bool status) { _restore = status; }
    void setDoton(bool status) { _doton = status; }

    //Gets()
    bool getNegativeStates(int i) { return negativeStates[i]; }
    bool getPositiveStates(int i) { return positiveStates[i]; }
};

#endif