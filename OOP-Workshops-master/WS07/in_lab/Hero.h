//***********************************************************************
// OOP244 Workshop 7: Derived Classes
// Filename:          Hero.h
// Date:	            2018/07/13
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to code a simple hierarchy and define
// helper functions to support the base and derived classes.
//***********************************************************************

#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict {
  const int max_rounds = 100;
  const int max_name = 41;

  class Hero {
    // Private members
    //
    char hero_name[max_name];
    int hero_health;
    int hero_strength;
  public:
    // Public members
    //
    Hero();
    Hero(const char name[], int health, int strength);
    ~Hero();

    void operator-=(int attack);
    bool isAlive() const;
    int attackStrength() const;

    friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
  };

  const Hero& operator*(const Hero& first, const Hero& second);
}

#endif