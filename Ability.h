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
    bool _increasePD,
        _increaseMR,
        _waterResist,
        _fireResist,
        _airResist,
        _earthResist,
        _increaseMD,
        _heal,
        _restore,
        _doton;//CHEQUEAR

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
    sf::String getName() { return _name.getString(); };
    
    virtual ~Ability() {}


    //AbilityMagic
    void setMagicDamage(int magicDamage) { _magicDamage = magicDamage; }
    void setDamageMultiplier(bool status) { _damageMultiplier = status; }
    void setMpCost(int mpCost) { _mpCost = mpCost; }
    void setVampireishon(bool status) { _vampireishon = status; }
    void setStun(bool status) { _stun = status; }
    void setReducePD(bool status) { _reducePD = status; }
    void setReduceMR(bool status) { _reduceMR = status; }
    void setReduceAtt(bool status) { _reduceAtt = status; }
    void setBurns(bool status) { _burns = status; }
    void setPoison(bool status) { _poison = status; }
    void setTrueDamash(bool status) { _truedamash = status; }
    float useAbilityMagic(Dragon& dragon);
    

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
    float useAbilitySupport(Dragon& dragon);

};

#endif