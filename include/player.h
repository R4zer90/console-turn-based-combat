#pragma once
#include <string>

// ====================
// PLAYER STATS
// ====================
extern std::string playerName;
extern int playerHealth;
extern int playerAttack;
extern int maxHP;

// ====================
// PLAYER PROGRESSION
// ====================
void applyPostCombatUpgrade();