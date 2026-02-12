#include <iostream> // For standard input and output (e.g., std::cout, std::cin)
#include <thread>	// For std::this_thread::sleep_for
#include <chrono> // For std::chrono::milliseconds
#include <conio.h> // For _getch()
#include <cstddef> // For size_t type used in loops

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