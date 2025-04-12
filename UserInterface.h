#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <string>
#include "Common.h"

// User Interface class to separate UI logic
class UserInterface {
public:
    static void clearScreen();
    static void displayTitle();
    static void displayMenu(int selectedOption);
    static void displayAboutGame();
    static std::string getPlayerName();
    static void displayInstructions();
    static std::string getStartCommand();
    static void displayGameScreen(int score, const std::string& word);
    static void displayTypingSpeed(int timeTaken, int remainingTime);
};

#endif // USERINTERFACE_H