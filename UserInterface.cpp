#include "UserInterface.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void UserInterface::clearScreen() {
    system("cls");
}

void UserInterface::displayTitle() {
    cout << "                                                                                          \n"
            " _____  __ __  _____  _____    _____  _____    _____  _____  _____  _____  _____  _____ \n"
            "|_   _||  |  ||  _  ||   __|  |     ||_   _|  |  _  ||  _  ||   __||_   _||   __|| __  |\n"
            "  | |  |_   _||   __||   __|  |-   -|  | |    |   __||     ||__   |  | |  |   __||    -|\n"
            "  |_|    |_|  |__|   |_____|  |_____|  |_|    |__|   |__|__||_____|  |_|  |_____||__|__|\n\n";
}

void UserInterface::displayMenu(int selectedOption) {
    clearScreen();
    displayTitle();
    
    // Subtitle
    cout << "   \tA game where you type a word fast, do you have what it takes?" << endl;
    cout << "          \tCoded by Dela Cruz, Charles Arvin - CPE21S2" << endl << endl;
    cout << "            \tUse the arrow keys to navigate the menu" << endl << endl;
    
    // Menu options
    cout << (selectedOption == 1 ? "\t\t> " : "\t\t    ") << "Start this madness" << endl;
    cout << (selectedOption == 2 ? "\t\t> " : "\t\t    ") << "About this game" << endl;
    cout << (selectedOption == 3 ? "\t\t> " : "\t\t    ") << "High Scores" << endl;
    cout << (selectedOption == 4 ? "\t\t> " : "\t\t    ") << "Exit" << endl;
}

void UserInterface::displayAboutGame() {
    clearScreen();
    cout << "\n\tTYPE IT PASTER! A game where you type a word faster. Yes that's the game." << endl << endl;
    cout << "\tPress ENTER to go back to the menu . . .";
    cin.get();
}

string UserInterface::getPlayerName() {
    string name;
    cout << "\tType in your name: ";
    getline(cin, name);
    return name;
}

void UserInterface::displayInstructions() {
    cout << "\n\tType as many words as you can as fast as possible, your score is based on how fast you typed." << endl
         << "\tOnce 2 minutes is over, or you spelt the word incorrectly, its game over!" << endl
         << "\tGood luck! :)" << endl;
}

string UserInterface::getStartCommand() {
    string command;
    cout << "\n\tType 'start' to play the game or 'quit' to go back to the menu" << endl
         << " \t> ";
    cin >> command;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return command;
}

void UserInterface::displayGameScreen(int score, const string& word) {
    clearScreen();
    cout << "\n\tYour current score: " << score << endl;
    cout << "\n\tType the word: " << word << endl;
    cout << " \t> ";
}

void UserInterface::displayTypingSpeed(int timeTaken, int remainingTime) {
    clearScreen();
    cout << "\n\tTyping speed: " << timeTaken << " ms" << endl;
    cout << "\tTime left: " << remainingTime << " seconds" << endl;
}