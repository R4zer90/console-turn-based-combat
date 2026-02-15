// ====================
// SECOND COMBAT ENCOUNTER
// ====================
#include <iostream>
#include <cstdlib>
#include "secondCombat.h"
#include "enemy.h"
#include "player.h"
#include "combat.h"
#include "typeText.h"
#include "consoleUtils.h"

bool secondCombat()
{
    // ====================
    // ENEMY SELECTION
    // ====================
    int enemyIndex = getRandomUnusedEnemyIndex();
    currentEnemy = enemies[enemyIndex];

    // ====================
    // ENCOUNTER DIFFICULTY
    // ====================
    currentEnemy.health = std::rand() % 51 + 150; 
    int attackMin = 15;
    int attackMax = 25;

    // ====================
    // INTRO TEXT
    // ====================
    typeText("Deeper in the forest, the path narrows.");
    typeText("The shadows feel closer now.");
    typeText("A second threat blocks your way...");
    typeText("It's a " + currentEnemy.name + ".");
    typeText(currentEnemy.introText);
    std::cin.get();
    clearScreen();

    // ====================
    // START COMBAT
    // ====================
    return combat(attackMin, attackMax);
}