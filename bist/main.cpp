
#include "utils.h"
#include <iostream>
#include <cstdlib> // For system() function

int main() {
    char choice;
    char wait;
    
    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        processChoice(choice);
        std::cout << "Press Enter to continue...";
        std::cin.ignore(); // Ignore any previous input
        std::cin.get(); // Wait for Enter key
        
        clearScreen();
    } while (choice != 'q');
    
    return 0;
}


