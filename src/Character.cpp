#include <iostream>
#include <string>
#include "Character.h"
#include "Weapon.h"

Character::Character()
    : m_name("Character"), m_hp(100), m_mana(100), m_weapon(nullptr)
{
  m_weapon = new Weapon();
}

Character::Character(Character const &source)
    : m_hp(source.m_hp), m_mana(source.m_mana), m_weapon(nullptr)
{
  m_weapon = new Weapon(*(source.m_weapon));
}

Character::Character(std::string name)
    : m_name(name), m_hp(100), m_mana(100), m_weapon(nullptr)
{
  m_weapon = new Weapon();
}

Character::Character(std::string name, std::string weapon, int damage)
    : m_name(name), m_hp(100), m_mana(100), m_weapon(nullptr)
{
  m_weapon = new Weapon(weapon, damage);
}

Character &Character::operator=(Character const &source)
{
  if (this != &source)
  {
    m_hp = source.m_hp;
    m_mana = source.m_mana;
    delete m_weapon;
    m_weapon = new Weapon(*(source.m_weapon));
  }

  return *this;
}

Character::~Character()
{
  delete m_weapon;
}

void Character::takeDamage(int amount)
{
  std::cout << m_name << " loses " << amount << " HP!" << std::endl;
  m_hp -= amount;

  if (m_hp < 0)
    m_hp = 0;
}

void Character::attack(Character &target)
{
  std::cout << m_name << " attacks " << target.m_name << "!" << std::endl;
  target.takeDamage(m_weapon->getDamage());
}

void Character::drinkHealthPotion(int amount)
{
  std::cout << m_name << " drinks a health potion, and heals for " << amount << " HP." << std::endl;
  m_hp += amount;

  if (m_hp > 100)
    m_hp = 100;
}

void Character::changeWeapon(std::string newWeapon, int newWeaponDamage)
{
  std::cout << m_name << " drops his " << m_weapon.getName() << " and draws a " << newWeapon << std::endl;
  m_weapon.change(newWeapon, newWeaponDamage);
}

void Character::printStatus() const
{
  std::cout << "********" << std::endl;
  std::cout << m_name << std::endl;
  std::cout << "********" << std::endl;
  std::cout << "HP: " << m_hp << std::endl;
  std::cout << "Mana: " << m_mana << std::endl;
  m_weapon.print();
  std::cout << std::endl;
}

bool Character::isAlive() const
{
  return m_hp > 0;
}