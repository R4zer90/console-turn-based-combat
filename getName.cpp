#include <iostream> // For standard input and output (e.g., std::cout, std::cin)
#include "typeText.h" // For the typeText function to display text with delay

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



	
