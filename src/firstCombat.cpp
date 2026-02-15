// ====================
// FIRST COMBAT ENCOUNTER
// ====================
#include <iostream>
#include <cstdlib>
#include "firstCombat.h"
#include "enemy.h"
#include "player.h"
#include "combat.h"
#include "typeText.h"

bool firstCombat()
{
	// ====================
	// ENEMY SELECTION
	// ====================
	int enemyIndex = getRandomUnusedEnemyIndex();
	currentEnemy = enemies[enemyIndex];

	// ====================
	// ENCOUNTER DIFFICULTY
	// ====================
	currentEnemy.health = std::rand() % 51 + 100; 
	int attackMin = 5; 
	int attackMax = 15;

	// ====================
	// INTRO TEXT
	// ====================
	typeText("Despite every warning, you keep walking.");
	typeText(playerName + " disappears between the trees.");
	typeText("No birds. No wind.");
	typeText("Only your breath… and the crunch of leaves.");
	typeText("Suddenly, a " + currentEnemy.name + " emerges from the shadows.");
	typeText(currentEnemy.introText);
	std::cin.get();
	system("cls");

	// ====================
	// START COMBAT
	// ====================
	return combat(attackMin, attackMax);


}