#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include <chrono>
#include "Common.h"
#include "WordList.h"
#include "HighScoreManager.h"

// Enhanced game engine class to separate game logic
class GameEngine {
private:
    WordList& wordList;
    HighScoreManager& highScoreManager;
    std::string playerName;
    int score;
    int totalAttempts;
    double totalSpeed;
    std::chrono::time_point<std::chrono::steady_clock> gameStartTime;

public:
    GameEngine(WordList& wl, HighScoreManager& hsm);
    void setPlayerName(const std::string& name);
    void resetGame();
    bool processWord(const std::string& givenWord, const std::string& userInput, int timeTaken);
    bool checkTimeRemaining();
    int getRemainingTime();
    void endGame(const std::string& reason);

    // Getters
    int getScore() const;
    std::chrono::time_point<std::chrono::steady_clock> getGameStartTime() const;
};

#endif // GAMEENGINE_H