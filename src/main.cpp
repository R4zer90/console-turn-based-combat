// CONSOLE GAME – Turn-Based Combat (v1).cpp : This file contains the 'main' function. Program execution begins and ends there.
// ====================
// ENTRY POINT
// ====================

#include <iostream>
#include <cstdlib>
#include "typeText.h"
#include "showIntro.h"
#include "getName.h"
#include "firstCombat.h"
#include "player.h"
#include "secondCombat.h"
#include <ctime>
#include "thirdCombat.h"
#include "enemy.h"
#include "consoleUtils.h"


int main()
{	
	// ====================
	// RANDOM SEED
	// ====================
	std::srand(static_cast<unsigned int>(std::time(0)));
	resetEnemyPool();

	// ====================
	// INTRO + PLAYER SETUP
	// ====================
	showIntro(); 
	playerName = getName();
	clearScreen();
	
	// ====================
	// COMBAT SEQUENCE
	// ====================
	bool won = firstCombat() && secondCombat() && thirdCombat();

	// ====================
	// ENDING
	// ====================
	if (won)
	{
		typeText("=== DEMO COMPLETE ===");
		typeText("You made it through the forest... alive.");
		typeText("For now.");
		typeText("");
		typeText("Thank you for playing!");
		typeText("This small game was created as a C++ learning project.");
		typeText("I had a lot of fun building it — and I hope you enjoyed it too.");
		typeText("More adventures will come...");
	}
	else
	{
		typeText("Your journey ends here...");
		typeText("The forest claims another soul.");
		typeText("");
		typeText("Thank you for playing!");
		typeText("This demo was created as a C++ learning project.");
	}

	typeText("Press Enter to exit...");
	std::cin.get();
	return 0;
	
}


