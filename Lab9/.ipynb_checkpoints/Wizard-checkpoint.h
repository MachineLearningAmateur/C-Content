#include <string>
#include <iostream>
#include "Character.h"

using namespace std;

#ifndef __WIZARD_H__
#define __WIZARD_H__

class Wizard : public Character {
  private:
    int rank;
  public:
      Wizard(const string& name, double health, double attackStrength, int rank);
      int getRank();
      void attack(Character& opponent) override; 
};

#endif