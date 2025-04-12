#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <vector>

// Game Constants
const int GAME_DURATION_SECONDS = 120;
const int MAX_HIGH_SCORES = 10;
const std::string HIGHSCORE_FILENAME = "highscores.txt";
const std::string START_COMMAND = "start";
const std::string QUIT_COMMAND = "quit";

// Forward declarations
class WordList;
class HighScoreManager;
class GameEngine;
class UserInterface;

// High Score Structure
struct HighScore {
    std::string name; // The player's name (because bragging rights)
    int score; // Total points scored by the player
    double avgSpeed; // Average typing speed of the player
    int wordsTyped; // Total words typed by the player
    
    HighScore(std::string n = "", int s = 0, double speed = 0.0, int words = 0) 
        : name(n), score(s), avgSpeed(speed), wordsTyped(words) {}
    
    // Comparator to sort scores
    static bool compareScores(const HighScore& a, const HighScore& b) {
        return a.score > b.score;
    }
};

// Greedy Score Calculation Function
int calculateGreedyScore(const std::string& word, double timeTaken);

#endif // COMMON_H
