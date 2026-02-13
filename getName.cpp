#include <iostream>
#include <string>
#include "getName.h"
#include "typeText.h"

std::string getName() 
{
    std::string playerName;
    while (playerName.empty()) {
        typeText("Enter your name: ");
        std::getline(std::cin, playerName);
        if (playerName.empty()) {
            typeText("Name cannot be empty. Please try again.");
        }
    }
    return playerName; // Return the name
}



	
