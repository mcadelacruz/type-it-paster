#ifndef WORDLIST_H
#define WORDLIST_H

#include <string>
#include <memory>
#include <random>
#include "Common.h"

// Linked List Node for Words
struct WordNode {
    std::string word; // The word stored in this node
    std::unique_ptr<WordNode> next; // Changed to smart pointer

    WordNode(std::string w) : word(w), next(nullptr) {}
};

// Word List Class
class WordList {
private:
    std::unique_ptr<WordNode> head; // Changed to smart pointer
    std::mt19937 rng; // Better random number generator

public:
    WordList();
    void insertWord(const std::string& word);
    std::string getRandomWord();
    // No need for explicit destructor - smart pointers handle memory cleanup
};

#endif // WORDLIST_H