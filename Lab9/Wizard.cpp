#include "Wizard.h"

// Character(HeroType hero, const string& name, double health, double attackStrength)
    
Wizard::Wizard(const string& name, double health, double attackStrength, int rank) : Character(WIZARD, name, health, attackStrength) {
    this->rank = rank;
}

// When a wizard attacks another wizard, the damage done is the wizard's attack strength multiplied by the ratio of the attacking wizard's rank over the defending wizard's rank.
// The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.

int Wizard::getRank() {
    return rank;
}

void Wizard::attack(Character& opponent) {
    double damage; //might need to move into if statement
    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        damage = (static_cast<double>(this->rank)/opp.getRank()) * this->attackStrength;
        opp.damage(damage);
    } else {
        damage = this->attackStrength;
        opponent.damage(damage);
    }
    cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    cout << opponent.getName() << " takes " << damage << " damage." << endl;
        
}

