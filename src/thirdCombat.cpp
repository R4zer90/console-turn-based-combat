// ====================
// THIRD COMBAT ENCOUNTER
// ====================
#include <iostream>
#include <cstdlib>
#include "thirdCombat.h"
#include "enemy.h"
#include "player.h"
#include "combat.h"
#include "typeText.h"
#include "consoleUtils.h"

bool thirdCombat()
{   
    // ====================
    // ENEMY SELECTION
    // ====================
    int enemyIndex = getRandomUnusedEnemyIndex();
    currentEnemy = enemies[enemyIndex];

    // ====================
    // ENCOUNTER DIFFICULTY
    // ====================
    currentEnemy.health = std::rand() % 51 + 200; // 200-250
    int attackMin = 25;
    int attackMax = 40;

    // ====================
    // INTRO TEXT
    // ====================
    typeText("The forest grows darker with every step.");
    typeText("You feel the air turning cold.");
    typeText("Something is watching you...");
    typeText("It's a " + currentEnemy.name + ".");
    typeText(currentEnemy.introText);
    std::cin.get();
    clearScreen();

    // ====================
    // START COMBAT
    // ====================
    return combat(attackMin, attackMax);
}