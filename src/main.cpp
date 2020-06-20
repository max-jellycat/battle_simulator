#include <iostream>
#include <string>
#include "Character.h"

int main()
{
  Character player("Player"), enemy("Orc", "Sharp sword", 20);
  enemy.attack(player);
  player.drinkHealthPotion(20);
  enemy.attack(player);
  player.attack(enemy);
  enemy.changeWeapon("Double edged axe of DOOM", 40);
  enemy.attack(player);

  player.printStatus();
  enemy.printStatus();
}