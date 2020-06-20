#include <iostream>
#include <string>
#include "Weapon.h"

Weapon::Weapon()
    : m_name("Cypress Stick"), m_damage(10) {}
Weapon::Weapon(std::string name, int damage)
    : m_name(name), m_damage(damage) {}

Weapon::~Weapon() {}

void Weapon::change(std::string name, int damage)
{
  m_name = name;
  m_damage = damage;
}

void Weapon::print() const
{
  std::cout << "Weapon: " << m_name << " (Damage: " << m_damage << ")" << std::endl;
}

std::string Weapon::getName() const { return m_name; }
int Weapon::getDamage() const { return m_damage; }