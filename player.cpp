// ====================
// INCLUDES
// ====================
#include "player.h"

// ====================
// GLOBAL PLAYER STATE
// ====================
std::string playerName = "";
int playerHealth = 200;
int playerAttack = 20;
int maxHP = 200;

// Increases player power after a victory (simple progression system)
void applyPostCombatUpgrade()
{
    playerAttack += 5;
    maxHP += 20;
    playerHealth = maxHP;
}