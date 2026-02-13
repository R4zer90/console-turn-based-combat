#include <iostream>
#include <cstdlib>
#include <ctime>
#include "secondCombat.h"
#include "enemy.h"
#include "player.h"
#include "combat.h"
#include "typeText.h"

void secondCombat()
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    int enemyIndex = std::rand() % 3;
    currentEnemy = enemies[enemyIndex];

    currentEnemy.health = std::rand() % 51 + 170; // trochê mocniej ni¿ 1. walka (170-220)
    int attackMin = 10;
    int attackMax = 20;

    typeText("Deeper in the forest, the path narrows.");
    typeText("The shadows feel closer now.");
    typeText("A second threat blocks your way...");
    typeText("It's a " + currentEnemy.name + ".");
    typeText(currentEnemy.introText);
    std::cin.get();
    system("cls");

    combat(attackMin, attackMax);
}