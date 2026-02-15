// ====================
// INCLUDES
// ====================
#include "enemy.h"

// ====================
// GLOBAL ENEMY STATE
// ====================
Enemy currentEnemy;

// ====================
// ENEMY TEMPLATES
// ====================
Enemy enemies[3] = {
    {"Starving Orc", 100, "A starving orc bares its teeth, eyes locked on you like prey."},
    {"Orc Archer",   80,  "An orc archer emerges from the brush, arrow already nocked."},
    {"Orc Rider",    150, "An orc rider charges in, the ground trembling beneath its mount."}
};

// ====================
// ENEMY POOL (UNIQUE PER RUN)
// ====================
bool enemyUsed[3] = { false, false, false };
void resetEnemyPool()
{
    for (int i = 0; i < 3; i++)
    {
        enemyUsed[i] = false;
    }
}

// Returns a random enemy index that has not been used yet in this run
// Marks the chosen enemy as used
int getRandomUnusedEnemyIndex()
{
    while (true)
    {
        int index = std::rand() % 3;
        if (!enemyUsed[index])
        {
            enemyUsed[index] = true;
            return index;
        }
    }
}