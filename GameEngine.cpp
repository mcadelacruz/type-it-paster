#include "GameEngine.h"
#include <iostream>
#include <chrono>

using namespace std;

GameEngine::GameEngine(WordList& wl, HighScoreManager& hsm) 
    : wordList(wl), highScoreManager(hsm), 
      score(0), totalAttempts(0), totalSpeed(0.0) {}

void GameEngine::setPlayerName(const string& name) {
    playerName = name;
}

void GameEngine::resetGame() {
    score = 0;
    totalAttempts = 0;
    totalSpeed = 0.0;
    gameStartTime = chrono::steady_clock::now();
}

bool GameEngine::processWord(const string& givenWord, const string& userInput, int timeTaken) {
    if (userInput == givenWord) {
        // Word correct
        totalSpeed += timeTaken;
        totalAttempts++;
        score += calculateGreedyScore(givenWord, timeTaken);
        return true;
    }
    // Word incorrect
    endGame("You spelt it wrong!");
    return false;
}

bool GameEngine::checkTimeRemaining() {
    auto currentTime = chrono::steady_clock::now();
    auto elapsedGameTime = chrono::duration_cast<chrono::duration<double>>(currentTime - gameStartTime);
    
    if (elapsedGameTime.count() >= GAME_DURATION_SECONDS) {
        endGame("Time's up!");
        return false;
    }
    return true;
}

int GameEngine::getRemainingTime() {
    auto currentTime = chrono::steady_clock::now();
    auto elapsedGameTime = chrono::duration_cast<chrono::duration<double>>(currentTime - gameStartTime);
    return static_cast<int>((GAME_DURATION_SECONDS - elapsedGameTime.count()));
}

void GameEngine::endGame(const string& reason) {
    double averageSpeed = totalAttempts > 0 ? (totalSpeed / totalAttempts) : 0.0;
    
    cout << "\n\tGame over. " << reason << endl << endl;
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t|             Final Results             |" << endl;
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t Final score:              " << score << " points " << endl;
    cout << "\t Total words typed:        " << totalAttempts << " words " << endl;
    cout << "\t Average typing speed:     " << averageSpeed << " ms " << endl;
    cout << "\t+---------------------------------------+" << endl;
    
    // Add high score
    if (!playerName.empty()) {
        HighScore newScore(playerName, score, averageSpeed, totalAttempts);
        highScoreManager.addHighScore(newScore);
    }
}

int GameEngine::getScore() const {
    return score;
}

chrono::time_point<chrono::steady_clock> GameEngine::getGameStartTime() const {
    return gameStartTime;
}