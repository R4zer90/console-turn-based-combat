#include "showIntro.h"
#include "typeText.h"
#include <iostream>

void showIntro() 
{
    // Game title
    std::cout << "Combat Text RPG Game" << std::endl;
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

}
