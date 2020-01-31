//***********************************************************************
// OOP244 Workshop 7: Derived Classes
// Filename:          Hero.cpp
// Date:	            2018/07/13
// Author:	          Sharan Shanmugaratnam
// Description:
// Demonstrating our ability to code a simple hierarchy and define
// helper functions to support the base and derived classes.
//***********************************************************************

#include <iostream>
#include <cstring>
#include "Hero.h"
using namespace std;

namespace sict {
  // Default constructor.
  //
  Hero::Hero() {
    // Set empty state for default constructor.
    //
    hero_name[0] = '\0';
    hero_health = 0;
    hero_strength = 0;
  }

  //Constructor with 3 parameters.
  //
  Hero::Hero(const char name[], int health, int strength) {
    if (!(name == NULL || name[0] == '\0' || strcmp(name, "") == 0 || health < 0 || strength < 0)) {
      strncpy(hero_name, name, max_name);
      hero_name[max_name - 1] = '\0';
      hero_health = health;
      hero_strength = strength;
    }
    else {
      // Set empty state.
      //
      hero_name[0] = '\0';
      hero_health = 0;
      hero_strength = 0;
    }
  }

  // Destructor.
  //
  Hero::~Hero() {
  }

  // Overloaded -= operator.
  void Hero::operator-=(int attack) {
    if (attack >= 0) {
      if (hero_health > attack) {
        hero_health -= attack;
      }
      else {
        hero_health = 0;
      }
    }
  }

  bool Hero::isAlive() const {
    return (hero_health > 0);
  }

  int Hero::attackStrength() const {
    if (hero_strength > 0) {
      return hero_strength;
    }
    else {
      return 0;
    }
  }

  // Overloaded << operator function.
  std::ostream& operator<<(std::ostream& os, const Hero& hero) {
    if (!(hero.hero_name == NULL || hero.hero_name[0] == '\0' || strcmp(hero.hero_name, "") == 0 || hero.hero_health < 0 || hero.hero_strength < 0)) {
      os << hero.hero_name;
    }
    else {
      os << "No hero";
    }
    return os;
  }

  // Overloaded * operator function.
  const Hero& operator*(const Hero& first, const Hero& second) {
    Hero left = first;
    Hero right = second;
    int rounds = 0;

    for (int i = 0; (i < max_rounds) && left.isAlive() && right.isAlive(); i++) {
      left -= (right.attackStrength());
      right -= (left.attackStrength());
      rounds++;
    }

    cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";

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