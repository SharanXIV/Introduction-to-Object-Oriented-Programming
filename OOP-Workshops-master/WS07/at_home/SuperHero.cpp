//***********************************************************************
// OOP244 Workshop 7: Derived Classes
// Filename:          SuperHero.cpp
// Date:	            2018/07/17
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to code a simple hierarchy and define
// helper functions to support the base and derived classes.
//***********************************************************************

#include <iostream>
#include <cstring>
#include "SuperHero.h"
using namespace std;

namespace sict {
  // Default constructor.
  //
  SuperHero::SuperHero() {
    // Set empty state for default constructor.
    //
    bonusAtk = 0;
    bonusDef = 0;
  }

  //Constructor with 3 parameters.
  //
  SuperHero::SuperHero(const char* name, int hp, int str, int b_atk, int b_def) {
    if (!(name == NULL || name[0] == '\0' || strcmp(name, "") == 0 || hp < 0 || str < 0 || b_atk < 0 || b_def < 0)) {
      strncpy(SuperHero::hero_name, name, max_name);
      hero_name[max_name - 1] = '\0';
      hero_health = hp;
      hero_strength = str;
      bonusAtk = b_atk;
      bonusDef = b_def;
    }
    else {
      // Set empty state.
      //
      hero_name[0] = '\0';
      hero_health = 0;
      hero_strength = 0;
      bonusAtk = 0;
      bonusDef = 0;
    }
  }

  int SuperHero::attackStrength() const {
    if (Hero::attackStrength() != 0 && bonusAtk > 0) {
      return (Hero::attackStrength() + bonusAtk);
    }
    else {
      return 0;
    }
  }

  int SuperHero::defend() const {
    if (bonusDef != 0) {
      return bonusDef;
    }
    else {
      return 0;
    }
  }

  // Overloaded * operator function.
  //
  const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
    SuperHero left = first;
    SuperHero right = second;
    int rounds = 0;

    for (int i = 0; (i < max_rounds) && left.isAlive() && right.isAlive(); i++) {
      left -= (right.attackStrength() - left.defend());
      right -= (left.attackStrength() - right.defend());
      rounds++;
    }

    cout << "Super Fight! " << first << " vs " << second << " : Winner is ";

    if (left.isAlive()) {
      cout << first << " in " << rounds << " rounds." << endl;
      return first;
    }
    else if (right.isAlive()) {
      cout << second << " in " << rounds << " rounds." << endl;
      return second;
    }
    else if (left.isAlive() && right.isAlive()) {
      cout << first << " in " << rounds << " rounds." << endl;
      return first;
    }

    return first;
  }
}