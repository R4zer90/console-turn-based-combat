// CONSOLE GAME – Turn-Based Combat (v1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // For standard input and output (e.g., std::cout, std::cin)
#include <cstdlib> // For system commands like system("pause") or system("cls")
#include "typeText.h" // For the typeText function to display text with delay
#include "showIntro.h" // For displaying the game introduction
#include "getName.h" // For getting the player's name
#include "firstCombat.h" // For displaying first combat introduction
#include "globals.h" // Include the header file for global variables
#include "enemy.h" // Include the header for the Enemy structure
#include "combat.h"

// Global variable

// Player name
std::string playerName; 

// Player stats
int playerHealth = 200;
int playerAttack = 20;
int maxHP = 200;
int healthAmount = 40;
int DefenseValue = 0;

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



	typeText("Press Enter to exit...");
	std::cin.get();
	return 0;
}


