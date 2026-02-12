// CONSOLE GAME – Turn-Based Combat (v1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // For standard input and output (e.g., std::cout, std::cin)
#include <cstdlib> // For system commands like system("pause") or system("cls")
#include "typeText.h" // For the typeText function to display text with delay
#include "showIntro.h" // For displaying the game introduction
#include "getName.h" // For getting the player's name
#include "firstCombat.h" // For displaying first combat introduction
#include "globals.h" // Include the header file for global variables

// Global variable

// Player name
std::string playerName; 

// Player stats
int playerHealth = 0;
int playerAttack = 0;
int maxHP = 0;
int healthAmount = 0;
int DefenseValue = 0;

// Enemy stats
int enemyHealth = 0;
int enemyAttack = 0;

// Another variable
int turnNumber = 0;

int main()
{	
	// Show the game title and introduction
	showIntro(); 

	// Get the player's name
	playerName = getName();
	
	// Clear the screen before continuing
	system("cls"); 
	
	// Introduction to first combat
	firstCombat();
	
	// Combat loop
	while (playerHealth > 0 && enemyHealth > 0)
		{
		
		// Turnnumber display
				
		std::cout << "Turn:" << turnNumber << std::endl;

		// Stats display
		std::cout <<playerName<<" Health: " << playerHealth << std::endl;
		std::cout << "Orc HP: " << enemyHealth << std::endl;

		// Player Turn
		std::cout << "Choose action:" << std::endl << "[1] Attack - Deal 20 damage" << std::endl << "[2] Defend - Take no damage this turn" << std::endl << "[3] Heal - Restore 40 HP" << std::endl;
		std::cout << "Press 1,2 or 3: ";

		// Get player input
		int choice;
		std::cin >> choice;
		switch (choice)
		{
			case 1: // Attack
				enemyHealth -= playerAttack;
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
		if (enemyHealth > 0) // Check if enemy is still alive before it attacks
		{
			int damageDealt = enemyAttack - DefenseValue;

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

	typeText("Press Enter to exit...");
	std::cin.get();
	return 0;
}


