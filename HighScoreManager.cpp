#include "HighScoreManager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <conio.h>

using namespace std;

HighScoreManager::HighScoreManager() {
    loadHighScores(); // Load scores when we start the game
}

void HighScoreManager::addHighScore(const HighScore& score) {
    scores.push_back(score); // Add the new score to the list
    sort(scores.begin(), scores.end(), HighScore::compareScores); // Sort scores (bragging rights are serious business)

    // Keep only the top scores
    if (scores.size() > MAX_HIGH_SCORES) {
        scores.resize(MAX_HIGH_SCORES);
    }

    saveHighScores(); // Save the updated scores to the file
}

void HighScoreManager::displayHighScores() {
    system("cls"); // Clear the screen
    cout << "\n\t========================== HIGH SCORES ==========================\n";
    cout << "\t" << left << setw(20) << "Name" 
         << setw(10) << "Score" 
         << setw(15) << "Avg Speed" 
         << "Words Typed\n";
    cout << "\t-----------------------------------------------------------------\n";
    
    if (scores.empty()) {
        cout << "\t No high scores yet! Be the first to set a record!\n";
    } else {
        for (size_t i = 0; i < scores.size(); ++i) {
            cout << "\t" << left << setw(20) << scores[i].name 
                 << setw(10) << scores[i].score 
                 << setw(15) << fixed << setprecision(2) << scores[i].avgSpeed
                 << scores[i].wordsTyped << endl;
        }
    }
    
    cout << "\n\tPress any key to continue...";
    _getch(); // Wait for the user to press a key
}

void HighScoreManager::loadHighScores() {
    ifstream file(HIGHSCORE_FILENAME); // Open the file
    if (!file) return; // No file? Skip loading.

    scores.clear(); // Clear any existing scores
    string name;
    int score, wordsTyped;
    double avgSpeed;

    // Read scores until EOF
    while (file >> name >> score >> avgSpeed >> wordsTyped) {
        scores.push_back(HighScore(name, score, avgSpeed, wordsTyped));
    }
    
    file.close(); // Close the file
    
    // Sort scores after loading
    sort(scores.begin(), scores.end(), HighScore::compareScores);
}

void HighScoreManager::saveHighScores() {
    ofstream file(HIGHSCORE_FILENAME); // Open the file for writing
    if (!file) {
        cerr << "Error: Could not open file for saving high scores." << endl;
        return;
    }
    
    for (const auto& score : scores) {
        file << score.name << " " 
             << score.score << " " 
             << score.avgSpeed << " " 
             << score.wordsTyped << endl;
    }
    file.close(); // Close the file
}