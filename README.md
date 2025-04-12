# TYPE IT PASTER

A fast-paced typing game that challenges your speed and accuracy!

## About the Game

TYPE IT PASTER is a thrilling typing speed game where your reflexes and spelling abilities are put to the test. Type a series of increasingly difficult words as fast as you can before the timer runs out. Your score is calculated based on the word's complexity and how quickly you type it. One wrong letter and it's game over!

## Features

- **Dynamic Scoring System**: Score calculation based on word complexity and typing speed
- **Time Attack Mode**: Race against a 2-minute countdown
- **High Score System**: Local leaderboard to track and compare your performance
- **Word Library**: Contains over 250 words of varying difficulty
- **Word Complexity**: From simple fruit names to the longest English words!

## How to Play

1. Select "Start this madness" from the main menu
2. Enter your name to be recorded in the high scores
3. Type 'start' to begin the game
4. Type each displayed word correctly and as fast as possible
5. Your score increases with each correct word
6. The game ends when:
   - You misspell a word
   - The 2-minute timer expires

## Controls

- **Arrow Keys**: Navigate the menu
- **Enter**: Select menu option
- **Keyboard**: Type words during gameplay

## Technical Details

- Written in C++ (C++14 standard)
- Uses smart pointers for memory management
- Console-based user interface
- High scores saved in local file

## Installation

### Requirements
- C++ compiler (supporting C++14 or later)
- Windows operating system (uses Windows-specific console functions)
- Make utility (GNU Make or compatible)

### Building and Running the Game

The project includes a makefile for easy compilation. Follow these steps:

1. Clone this repository:
   ```
   git clone https://github.com/yourusername/type-it-paster.git
   ```

2. Navigate to the project directory:
   ```
   cd type-it-paster
   ```

3. Build the game using make:
   ```
   make
   ```
   This will compile all source files and create the executable `TypeItPaster`.

4. Run the game:
   ```
   make run
   ```
   Or run the executable directly:
   ```
   ./TypeItPaster
   ```

5. To clean up compiled objects and executable:
   ```
   make clean
   ```

### Manual Compilation (without Make)

If you don't have Make installed, you can compile the game manually:

```
g++ -std=c++14 -Wall -o TypeItPaster main.cpp WordList.cpp HighScoreManager.cpp GameEngine.cpp UserInterface.cpp Common.cpp
```

## Screenshots

![Main Menu](https://media.discordapp.net/attachments/1123274902800183299/1360604450724511855/1.webp?ex=67fbb923&is=67fa67a3&hm=1dcabd13ad0ac289dc54b6f9e1e2cd40b7d939ed6641a882800e55bdae2145dd&=&format=webp)

![Gameplay](https://media.discordapp.net/attachments/1123274902800183299/1360604450351485129/3.webp?ex=67fbb923&is=67fa67a3&hm=5330e8c7a9f0a0d46580e981b1dadcb85769fd674948b402289a9490d8a498e7&=&format=webp)


## Credits

Developed by: Charles Arvin Dela Cruz - BSCPE at Technological Institute of the Philippines - Manila
