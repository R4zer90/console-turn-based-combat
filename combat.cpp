#include <iostream>   // For standard input and output (std::cout, std::cin)
#include <cstdlib>    // For functions like rand() and system("cls")
#include "combat.h"   // Include the header for the combat loop function declaration
#include "globals.h"   // Include global variables like player stats and currentEnemy
#include "typeText.h" // Include the function for displaying text with a typing effect

void combat(int attackMin, int attackMax)
{		
	int turnNumber = 1;

	while (playerHealth > 0 && currentEnemy.health > 0)
	{

		// Turnnumber display
		std::cout << "Turn:" << turnNumber << std::endl;

		// Stats display
		std::cout << playerName << " Health: " << playerHealth << std::endl;
		std::cout << currentEnemy.name << " HP: " << currentEnemy.health << std::endl;

		// Player Turn
		std::cout << "Choose action:" << std::endl << "[1] Attack - Deal 20 damage" << std::endl << "[2] Defend - Take no damage this turn" << std::endl << "[3] Heal - Restore 40 HP" << std::endl;
		std::cout << "Press 1,2 or 3: ";

		// Get player input
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1: // Attack
			currentEnemy.health -= playerAttack;
			std::cout << "You attack the enemy for " << playerAttack << " damage!" << std::endl;
			break;

		case 2: // Defend
			DefenseValue = 30;
			std::cout << "You defend against the enemy's attack!" << std::endl;
			break;

		case 3: // Heal		
			playerHealth += healthAmount;
			if (playerHealth > maxHP)
			{
				playerHealth = maxHP;
			}
			std::cout << "You heal yourself for " << healthAmount << " health!" << std::endl;
			break;

		default:
			std::cout << "Invalid choice! Please choose 1, 2, or 3." << std::endl;
			break;
		}

		// Enemy Turn
		if (currentEnemy.health > 0) // Check if enemy is still alive before it attacks
		{
			int enemyRoll = std::rand() % (attackMax - attackMin + 1) + attackMin;
			int damageDealt = enemyRoll - DefenseValue;

			// If player fully defended (damageDealt <= 0) show friendly message and do no damage
			if (damageDealt <= 0)
			{
				// Player took no damage because they defended
				std::cout << "Great! You defended the attack and took no damage!" << std::endl;
			}
			else
			{
				// Normal damage application
				playerHealth -= damageDealt;
				std::cout << "The orc attacks you for " << damageDealt << " damage!" << std::endl;
			}

			// Reset defense after enemy turn so it only lasts one enemy attack
			DefenseValue = 0;
			typeText("Press Enter to continue...");
			std::cin.get();
			system("cls");

		}
		system("cls");
		turnNumber++;
	}
	if (playerHealth <= 0)
	{
		typeText("Defeat...");
		typeText("The orc has crushed you. Better luck next time.");
	}
	else
	{
		typeText("Victory!");
		typeText("The starving orc collapses to the ground.");
		typeText("You have survived the forest... for now.");
	}
}