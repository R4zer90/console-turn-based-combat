// ====================
// INCLUDES
// ====================
#include <iostream>
#include <cstdlib>
#include <limits>
#include <string>

#include "combat.h"
#include "player.h"
#include "enemy.h"
#include "typeText.h"




bool combat(int attackMin, int attackMax)
{		
	// ====================
	// COMBAT SETUP
	// ====================
	int turnNumber = 1;
	int DefenseValue = 0;
	
	// ====================
	// COMBAT LOOP
	// ====================
	while (playerHealth > 0 && currentEnemy.health > 0)
	{
		
		// ====================
		// TURN INFO
		// ====================
		std::cout << "Turn: " << turnNumber << std::endl;
		std::cout << playerName << " Health: " << playerHealth << std::endl;
		std::cout << currentEnemy.name << " HP: " << currentEnemy.health << std::endl;

		// ====================
		// PLAYER TURN
		// ====================
		std::cout << "Choose action:" << std::endl
			<< "[1] Attack - Deal " << playerAttack << " damage" << std::endl
			<< "[2] Defend - Take no damage this turn" << std::endl
			<< "[3] Heal - Restore " << (maxHP / 4) << " HP" << std::endl;
		std::cout << "Press 1,2 or 3: ";
		int choice;
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (choice)
		{
		case 1: // Attack
			currentEnemy.health -= playerAttack;
			std::cout << "You attack the enemy for " << playerAttack << " damage!" << std::endl;
			break;

		case 2: // Defend
			DefenseValue = 9999;
			std::cout << "You defend against the enemy's attack!" << std::endl;
			break;

		case 3: // Heal
		{
			int healValue = maxHP / 4;
			playerHealth += healValue;

			if (playerHealth > maxHP)
			{
				playerHealth = maxHP;
			}

			std::cout << "You heal yourself for " << healValue << " health!" << std::endl;
			break;
		}

		default:
			std::cout << "Invalid choice! Please choose 1, 2, or 3." << std::endl;
			break;
		}

		// ====================
		// ENEMY TURN
		// ====================
		if (currentEnemy.health > 0) 
		{
			int enemyRoll = std::rand() % (attackMax - attackMin + 1) + attackMin; // Enemy attack roll
			int damageDealt = enemyRoll - DefenseValue;				
			if (damageDealt <= 0) // Defense check
			{
				std::cout << "Great! You defended the attack and took no damage!" << std::endl;
			}
			else
			{
				playerHealth -= damageDealt;
				std::cout << "The " << currentEnemy.name << " attacks you for " << damageDealt << " damage!" << std::endl;
			}

			DefenseValue = 0; // Reset defense (1 turn only)
			typeText("Press Enter to continue..."); // Pause before next turn
			std::cin.get();
			system("cls");

		}
		// Next turn
		system("cls");
		turnNumber++;
	}

	// ====================
	// END OF COMBAT
	// ====================
	if (playerHealth <= 0)
	{
		typeText("Defeat...");
		typeText("The " + currentEnemy.name + " has crushed you. Better luck next time.");
		return false;
	}
	else
	{
		typeText("Victory!");
		typeText("The " + currentEnemy.name + " collapses to the ground.");
		typeText("You have survived the forest... for now.");

		// Post-combat upgrade
		int oldAtk = playerAttack;
		int oldMaxHP = maxHP;

		applyPostCombatUpgrade();
		typeText("You feel stronger after the fight.");
		typeText("Attack: " + std::to_string(oldAtk) + " -> " + std::to_string(playerAttack));
		typeText("Max HP: " + std::to_string(oldMaxHP) + " -> " + std::to_string(maxHP));
		typeText("Press Enter to continue...");
		std::cin.get();
		system("cls");
		return true;
		
	}
}