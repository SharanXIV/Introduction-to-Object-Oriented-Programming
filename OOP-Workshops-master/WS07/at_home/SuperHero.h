//***********************************************************************
// OOP244 Workshop 7: Derived Classes
// Filename:          SuperHero.h
// Date:	            2018/07/17
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to code a simple hierarchy and define
// helper functions to support the base and derived classes.
//***********************************************************************

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {
  class SuperHero : public Hero {
    // Private members
    //
    int bonusAtk;
    int bonusDef;
  public:
    // Public members
    //
    SuperHero();
    SuperHero(const char* name, int hp, int str, int b_atk, int b_def);
    int attackStrength() const;
    int defend() const;
  };

  const SuperHero& operator*(const SuperHero&, const SuperHero&);
}

#endif