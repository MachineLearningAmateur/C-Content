#include "Warrior.h"



Warrior::Warrior(const string& name, double health, double attackStrength, string allegiance) : Character(WARRIOR, name, health, attackStrength) {
    this->allegiance = allegiance;
}

string Warrior::getAllegiance() {
    return this->allegiance;
}


// Warrior Jane does not attack Warrior Arthur.
// They share an allegiance with King George.
    
void Warrior::attack(Character& opponent) {
    double damage = (this->health/MAX_HEALTH) * this->attackStrength;
    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (opp.getAllegiance() == this->allegiance) {
            cout << "Warrior " << this->name << " does not attack Warrior " << opp.getName() <<  "." << endl;
            cout << "They share an allegiance with " << this->allegiance << "." << endl;
            return;
        }
        opp.damage(damage);
        cout << "Warrior " << this->name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
        cout << opp.getName() << " takes " << damage << " damage." << endl;
    } else {
        opponent.damage(damage);
        cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
} 