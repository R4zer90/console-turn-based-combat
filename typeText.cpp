#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <cstddef>
#include "typeText.h"

void typeText(const std::string& text, int delayMs)
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