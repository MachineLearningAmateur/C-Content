#include "Character.h"
#include <iostream>


Character::Character(HeroType hero, const string& name, double health, double attackStrength) {
    this->type = hero;
    this->name = name;
    this->health = health;
    this->attackStrength = attackStrength;
}

// Character(HeroType type, const string &name, double health, double attackStrength);
//      HeroType getType() const;
//      const string & getName() const;
//      /* Returns the whole number of the health value (static_cast to int). */
//      int getHealth() const;
//      void setHealth(double h);
//      /* Reduces health value by amount passed in. */
//      void damage(double d);
//      /* Returns true if getHealth() returns an integer greater than 0, otherwise false */
//      bool isAlive() const;
//      virtual void attack(Character &) = 0;

HeroType Character::getType() const {
    return type;
}

const string& Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

void Character::setHealth(double h) {
    this->health = h;
}

void Character::damage(double d) {
    this->health = this->health - d;
}

bool Character::isAlive() const {
    if (health > 0)
        return true;
    else
        return false;
}
