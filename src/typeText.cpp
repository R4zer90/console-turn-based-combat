#include <iostream>
#include <thread>
#include <chrono>
#include <cstddef>

#ifdef _WIN32
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#endif

#include "typeText.h"

#ifndef _WIN32
// Returns true if a key is waiting on stdin (non-blocking)
static bool keyAvailable()
{
    timeval tv{};
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    return select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &tv) > 0;
}

// Reads one char from stdin (assumes keyAvailable() is true)
static int readChar()
{
    unsigned char c = 0;
    if (read(STDIN_FILENO, &c, 1) == 1) return c;
    return -1;
}
#endif

void typeText(const std::string& text, int delayMs)
{
    bool skip = false;

#ifndef _WIN32
    // Put terminal into raw-ish mode so we can read keys instantly
    termios oldt{};
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= static_cast<unsigned int>(~(ICANON | ECHO));
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif

    for (size_t i = 0; i < text.length(); ++i)
    {
        if (!skip)
        {
#ifdef _WIN32
            if (_kbhit())
            {
                int key = _getch();
                if (key == '\r') skip = true; // Enter
            }
#else
            if (keyAvailable())
            {
                int key = readChar();
                if (key == '\n' || key == '\r') skip = true; // Enter
            }
#endif
        }

        if (skip)
        {
            std::cout << text.substr(i);
            break;
        }

        std::cout << text[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }

#ifndef _WIN32
    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif

    std::cout << '\n';
}
