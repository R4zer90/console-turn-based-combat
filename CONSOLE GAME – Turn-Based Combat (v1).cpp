// CONSOLE GAME – Turn-Based Combat (v1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> // For system("pause")
#include <string> // For string handling
#define NOMINMAX // To prevent Windows headers from defining min and max macros that can interfere with std::min and std::max
#include <windows.h> // For Sleep function
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::milliseconds
#include <conio.h> // For _getch()
#include <limits> // For std::numeric_limits


void typeText(const std::string& text, int delayMs = 60)
{
	bool skip = false;

	for (size_t i = 0; i < text.length(); ++i)
	{
		// Check if a key was pressed during the typing effect
		if (!skip && _kbhit())
		{
			int key = _getch(); // Consume the key (does not go to std::cin)

			// If Enter was pressed, skip the typing effect
			if (key == '\r')
			{
				skip = true;
			}
		}

		if (skip)
		{
			// Print the rest of the text instantly
			std::cout << text.substr(i);
			break;
		}
		else
		{
			// Print characters one by one with delay
			std::cout << text[i];
			std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
		}
	}

	std::cout << '\n';
}



int main()
{
	std::cout << "Combat Text RPG Game" << std::endl; // Game title
	std::cout << "Press Enter to continue...";
	std::cin.get();
	system("cls");

	// Introduction

	typeText("Welcome, brave knight.");

	typeText("You have entered a dark forest,");
	typeText("a place crawling with ruthless orcs.");

	typeText("Many have tried to pass through...");
	typeText("none have returned.");

	typeText("Tell me your name,");
	typeText("so I may remember who dares to become a legend.");
	std::cout << std::endl; // Add an extra line for spacing
	system("cls");

	// Get player's name
	std::string playerName;
	while(playerName.empty())
	{
		typeText("Enter your name: ");
		std::getline(std::cin, playerName);
		if (playerName.empty())
		{
			typeText("Name cannot be empty. Please try again.");
		}
		
	}
	
	// Introduction to combat
	typeText("Despite all the warnings,");
	typeText(playerName + " steps into the forest.");
	typeText("The trees grow silent.");
	typeText("The air feels heavy.");
	typeText("Suddenly, a starving orc emerges from the shadows.");
	typeText("Its eyes burn with hunger.");
	typeText("It's time to fight!");
	std::cin.get();
	system("cls");


	// Player stats
	int playerHealth = 100;
	int playerAttack = 20;
	int maxHP = 100;
	int healthAmount = 40;
	int DefenseValue = 0;

	// Enemy stats
	int enemyHealth = 200;
	int enemyAttack = 15;

	// Another variable
	int turnNumber = 1;
	
	

	// Combat loop
	while (playerHealth > 0 && enemyHealth > 0)
		{
		
		// Turnnumber display
				
		std::cout << "Turn:" << turnNumber << std::endl;

		// Stats display
		std::cout <<playerName<<" Health: " << playerHealth << std::endl;
		std::cout << "Orc HP: " << enemyHealth << std::endl;

		// Player Turn
		std::cout << "Choose action:" << std::endl << "[1] Attack - Deal 20 damage" << std::endl << "[2] Defend - Take no damage this turn" << std::endl << "[3] [3] Heal - Restore 40 HP" << std::endl;
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
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	return 0;
}


