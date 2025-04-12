CC = g++
CFLAGS = -std=c++14 -Wall
OBJ = main.o WordList.o HighScoreManager.o GameEngine.o UserInterface.o Common.o
TARGET = TypeItPaster

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.cpp Common.h WordList.h HighScoreManager.h GameEngine.h UserInterface.h
	$(CC) $(CFLAGS) -c main.cpp

WordList.o: WordList.cpp WordList.h Common.h
	$(CC) $(CFLAGS) -c WordList.cpp

HighScoreManager.o: HighScoreManager.cpp HighScoreManager.h Common.h
	$(CC) $(CFLAGS) -c HighScoreManager.cpp

GameEngine.o: GameEngine.cpp GameEngine.h Common.h WordList.h HighScoreManager.h
	$(CC) $(CFLAGS) -c GameEngine.cpp

UserInterface.o: UserInterface.cpp UserInterface.h Common.h
	$(CC) $(CFLAGS) -c UserInterface.cpp

Common.o: Common.cpp Common.h
	$(CC) $(CFLAGS) -c Common.cpp

clean:
	del $(OBJ) $(TARGET).exe

run: $(TARGET)
	./$(TARGET)