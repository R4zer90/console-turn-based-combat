#pragma once

#include <string>
#include "enemy.h"  // Include the definition of the Enemy structure

// Global variables

// Player name and stats
extern std::string playerName;
extern int playerHealth;
extern int playerAttack;
extern int maxHP;
extern int healthAmount;
extern int DefenseValue;

// Enemy data
extern Enemy currentEnemy;
extern Enemy enemies[3];

