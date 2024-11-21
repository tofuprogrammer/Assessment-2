#pragma once // Prevents the code from being included more than once.

#include <iostream> // Adds the "system "function to the header file.

void clearTerminal() {
#ifdef _WIN32 // If this code is being compiled on Windows, use this code.
    system("cls");
    
#else
    system("clear"); // Otherwise, use this code
    
#endif
}

