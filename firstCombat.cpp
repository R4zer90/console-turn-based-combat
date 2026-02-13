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
	// Initialize random seed
	std::srand(static_cast<unsigned int>(std::time(0)));

	// Randomly select an enemy from the array
	int enemyIndex = std::rand() % 3;

	// Select the enemy for the first combat
	currentEnemy = enemies[enemyIndex]; 
	currentEnemy.health = std::rand() % 51 + 150; // HP between 150 and 200
	int attackMin = 5; 
	int attackMax = 15;

	// Introduction to first combat 
	typeText("Despite all the warnings,");
	typeText(playerName + " steps into the forest.");
	typeText("The trees grow silent.");
	typeText("The air feels heavy.");
	typeText("Suddenly, a " + currentEnemy.name + " emerges from the shadows.");
	std::cin.get();
	system("cls");

	//Combat loop
	combat(attackMin, attackMax);


}