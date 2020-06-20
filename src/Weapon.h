#pragma once
#include <string>

class Weapon
{
private:
  std::string m_name;
  int m_damage;

public:
  Weapon();
  Weapon(std::string name, int damage);

  ~Weapon();

  void change(std::string name, int damage);
  void print() const;
  std::string getName() const;
  int getDamage() const;
};