#include "player.h"

std::string playerName = "";

int playerHealth = 200;
int playerAttack = 20;
int maxHP = 200;

void applyPostCombatUpgrade()
{
    playerAttack += 5;
    maxHP += 20;
    playerHealth = maxHP;
}