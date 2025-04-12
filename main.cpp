#include <iostream>
#include <conio.h>
#include <string>
#include "Common.h"
#include "WordList.h"
#include "HighScoreManager.h"
#include "GameEngine.h"
#include "UserInterface.h"

using namespace std;

// Global instances
WordList wordList;
HighScoreManager highScoreManager;

// Play game function
void playGame() {
    // Create instances (using externals for compatibility)
    WordList& wl = wordList;
    HighScoreManager& hsm = highScoreManager;
    GameEngine gameEngine(wl, hsm);
    
    UserInterface::clearScreen();
    UserInterface::displayTitle();
    
    // Get player name
    string playerName = UserInterface::getPlayerName();
    gameEngine.setPlayerName(playerName);
    
    // Show instructions
    UserInterface::displayInstructions();
    
    // Game loop
    while (true) {
        string command = UserInterface::getStartCommand();
        
        if (command == START_COMMAND) {
            gameEngine.resetGame();
            UserInterface::clearScreen();
            
            // Inner game loop for each word
            while (true) {
                // Get random word
                string givenWord = wl.getRandomWord();
                
                // Display game screen
                UserInterface::displayGameScreen(gameEngine.getScore(), givenWord);
                
                // Start timing
                auto start = chrono::steady_clock::now();
                
                // Get user input
                string userInput;
                getline(cin, userInput);
                
                // Calculate time taken
                auto end = chrono::steady_clock::now();
                auto elapsedTime = chrono::duration_cast<chrono::duration<double>>(end - start);
                int timeTaken = static_cast<int>(elapsedTime.count() * 1000);
                
                // Process word and check if game continues
                if (!gameEngine.processWord(givenWord, userInput, timeTaken)) {
                    break; // Word was incorrect
                }
                
                // Show typing speed and remaining time
                UserInterface::displayTypingSpeed(timeTaken, gameEngine.getRemainingTime());
                
                // Check if time is up
                if (!gameEngine.checkTimeRemaining()) {
                    break; // Time is up
                }
            }
        } else if (command == QUIT_COMMAND) {
            break; // Go back to main menu
        } else {
            cout << "\tWhat? I don't understand." << endl;
        }
    }
}

// Main function
int main() {
    int selectedOption = 1;

    while (true) {
        UserInterface::displayMenu(selectedOption);

        char key = _getch();  

        if (key == 72) {  // Up arrow key
            selectedOption = (selectedOption > 1) ? selectedOption - 1 : 4;
        } else if (key == 80) {  // Down arrow key
            selectedOption = (selectedOption < 4) ? selectedOption + 1 : 1;
        } else if (key == 13) {  // Enter key
            if (selectedOption == 1) {
                playGame();
            } else if (selectedOption == 2) {
                UserInterface::displayAboutGame();
            } else if (selectedOption == 3) {
                highScoreManager.displayHighScores();
            } else if (selectedOption == 4) {
                cout << "\nExiting..." << endl;
                return 0;
            }
        }
    }

    return 0;
}