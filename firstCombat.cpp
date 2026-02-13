#include <iostream>
#include <cstdlib>
#include <ctime>
#include "firstCombat.h"
#include "enemy.h"
#include "player.h"
#include "combat.h"
#include "typeText.h"

void firstCombat()
{
	// Randomly select an enemy from the array
	int enemyIndex = std::rand() % 3;

	// Select the enemy for the first combat
	currentEnemy = enemies[enemyIndex]; 
	currentEnemy.health = std::rand() % 51 + 150; // HP between 150 and 200
	int attackMin = 5; 
	int attackMax = 15;

	// Introduction to first combat 
	typeText("Despite every warning, you keep walking.");
	typeText(playerName + " disappears between the trees.");
	typeText("No birds. No wind.");
	typeText("Only your breath… and the crunch of leaves.");
	typeText("Suddenly, a " + currentEnemy.name + " emerges from the shadows.");
	typeText(currentEnemy.introText);
	std::cin.get();
	system("cls");

	//Combat loop
	combat(attackMin, attackMax);


}