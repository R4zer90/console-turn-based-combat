// CONSOLE GAME – Turn-Based Combat (v1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include "typeText.h"
#include "showIntro.h"
#include "getName.h"
#include "firstCombat.h"
#include "player.h"


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


