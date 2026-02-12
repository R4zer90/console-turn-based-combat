#include <iostream> // For standard input and output (e.g., std::cout, std::cin) 
#include "typeText.h" // For the typeText function to display text with delay
#include "globals.h" // Include the header file for global variables

void firstCombat()
{
	// Introduction to first combat
	typeText("Despite all the warnings,");
	typeText(playerName + " steps into the forest.");
	typeText("The trees grow silent.");
	typeText("The air feels heavy.");
	typeText("Suddenly, a starving orc emerges from the shadows.");
	typeText("Its eyes burn with hunger.");
	typeText("It's time to fight!");
	std::cin.get();
	system("cls");

}