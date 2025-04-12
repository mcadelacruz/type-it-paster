#include "Common.h"
#include <cmath>
#include <algorithm>

// Greedy Score Calculation Function
int calculateGreedyScore(const std::string& word, double timeTaken) {
    // Avoid dividing by zero (math teachers would cry)
    if (timeTaken <= 0) timeTaken = 0.1;

    int wordComplexity = word.length(); // Longer words are harder, so they score more
    double speedFactor = 1000.0 / timeTaken; // Faster typing means higher points

    // Exponential scoring makes it feel fancy
    int score = static_cast<int>(wordComplexity * speedFactor * log(wordComplexity + 1));

    return std::max(1, score); // At least give them 1 point (for effort)
}