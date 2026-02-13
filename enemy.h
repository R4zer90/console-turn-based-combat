// ====================
// ENEMY DATA TYPES
// ====================
#pragma once
#include <string>

// Represents an enemy template used for combat encounters
struct Enemy {
    std::string name;
    int health;
    std::string introText; 
};

// ====================
// GLOBAL ENEMY STATE
// ====================
extern Enemy currentEnemy;
extern Enemy enemies[3];
extern bool enemyUsed[3];
int getRandomUnusedEnemyIndex();
void resetEnemyPool();