#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <vector>
#include "Common.h"

// High Score Manager Class
class HighScoreManager {
private:
    std::vector<HighScore> scores; // List of high scores

    void loadHighScores();
    void saveHighScores();

public:
    HighScoreManager();
    void addHighScore(const HighScore& score);
    void displayHighScores();
};

#endif // HIGHSCOREMANAGER_H