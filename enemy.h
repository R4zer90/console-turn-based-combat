#pragma once
#include <string>

struct Enemy {
    std::string name;
    int health;
    std::string introText; 
};

// global enemy variables
extern Enemy currentEnemy;
extern Enemy enemies[3];