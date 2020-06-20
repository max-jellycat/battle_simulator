#pragma once

#include <string>
#include "Weapon.h"

class Character
{
private:
  std::string m_name;
  int m_hp;
  int m_mana;
  Weapon m_weapon;

public:
  Character();
  Character(std::string name);
  Character(std::string name, std::string weapon, int damage);
  ~Character();

  void takeDamage(int amount);

  void attack(Character &target);

  void drinkHealthPotion(int amount);

  void changeWeapon(std::string newWeapon, int newWeaponDamage);

  void printStatus() const;

  bool isAlive() const;
};