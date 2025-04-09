// Dela Cruz, Charles Arvin P. - CPE21S2
// TYPE IT PASTER v2: The High Score Update
// - Now the game records the scores of each game attempts and save it as a txt. file

// Note to sir: 
// Hello sir, this is a game recycled back in 1st Year nung pinagawa niyo po kami ng text game
// what i did nalang po is i made a high score system to implement a sorting algorithm and a greedy algorithm

// The data structure used is a Linked List

// The searching algorithm used is a custom comparator-based sorting algorithm. This is not one of the algorithm in the modules
// but this is the one I used as I find it much more practical in this game and I learned it in the internet.

// Greedy algorithm is used for the dynamic scoring system

// The only thing missing in this code is a searching algorithm system as I don't know how to use it in this game. 
// Antagal ko po pinagisaipan anong pwedeng gamit dito pero naubusan nalang ako ng time. I will just take deductions for it po.

// omaygad ayaw ko na magcode

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;

// Forward declarations to prevent sakit ng ulo na di kaya ng sensodyne
class WordList;
class HighScoreManager;

// High Score Structure
struct HighScore {
    string name; // The player's name (because bragging rights)
    int score; // Total points scored by the player
    double avgSpeed; // Average typing speed of the player
    int wordsTyped; // Total words typed by the player
    
    HighScore(string n = "", int s = 0, double speed = 0.0, int words = 0) 
        : name(n), score(s), avgSpeed(speed), wordsTyped(words) {}
    
    // Comparator to sort scores
    static bool compareScores(const HighScore& a, const HighScore& b) {
        return a.score > b.score;
    }
};

// Linked List Node for Words
struct WordNode {
    string word; // The word stored in this node
    WordNode* next; // Pointer to the next word in the list

    WordNode(string w) : word(w), next(nullptr) {}
};

// Word List Class
class WordList {
private:
    WordNode* head; // Start of the word list

public:
    WordList() : head(nullptr) {
        // hahaha ang haba ano
        const string originalWords[] = {
        "apple",
        "banana",
        "orange",
        "grapes",
        "cherry",
        "antidisestablishmentarianism",
        "pneumonoultramicroscopicsilicovolcanoconiosis",
        "hippopotomonstrosesquippedaliophobia",
        "supercalifragilisticexpialidocious",
        "incomprehensibilities",
        "parasternocleidomastoid",
        "psychoneuroendocrinological",
        "electroencephalographically",
        "gastrointestinal",
        "disproportionableness",
        "microspectrophotometrically",
        "ultramicroscopically",
        "quasiperiodically",
        "immunoelectrophoretically",
        "uncharacteristically",
        "micrometeorological",
        "unintelligibleness",
        "interconnectedness",
        "deinstitutionalization",
        "photophosphorylation",
        "counterdemonstration",
        "dihydroxyacetonephosphate",
        "palaeogeographically",
        "extemporaneousness",
        "overintellectualization",
        "indistinguishableness",
        "counterproliferation",
        "immunohematologically",
        "chromolithographically",
        "nondiscrimination",
        "thermoelectrically",
        "antirevolutionaries",
        "inconsequentialities",
        "mischaracterization",
        "electroretinographies",
        "psychopathologically",
        "microencapsulations",
        "immunoelectrophoresis",
        "counterintelligence",
        "incommensurabilities",
        "disproportionateness",
        "ultramicroscopical",
        "phenomenalistically",
        "immunocytochemistry",
        "irreconcilabilities",
        "unintelligibilities",
        "overenthusiastically",
        "pseudopseudohypoparathyroidism",
        "photointerpretation",
        "underrepresentation",
        "ultrasonographically",
        "neuroradiologically",
        "anthropomorphologically",
        "counterinflationary",
        "phosphatidylethanolamine",
        "immunoprecipitation",
        "overcommunication",
        "unintelligibility",
        "circumlocutionary",
        "electrooculographic",
        "anticonstitutional",
        "unconstitutionality",
        "neuropharmacological",
        "counterproductive",
        "irreproachableness",
        "spectrophotometries",
        "microphotometrically",
        "immunohistochemistry",
        "counterpropagations",
        "stereomicroscopical",
        "uncontrollableness",
        "photoreconnaissance",
        "incontrovertibility",
        "inconspicuousnesses",
        "immunopathological",
        "uncontroversially",
        "incomprehensibility",
        "immunomodulations",
        "suprasegmentalities",
        "contradistinctively",
        "antiestablishmentarian",
        "psychobiographical",
        "unconscionableness",
        "overproportionately",
        "microcalorimetrical",
        "unquestionableness",
        "ultracentrifugation",
        "counterinsurgencies",
        "neurotransmitter",
        "counterprogramming",
        "multidimensionality",
        "disestablishmentarian",
        "photogrammetries",
        "countercultural",
        "uncharacterized",
        "microelectronically",
        "noncontroversial",
        "uncharacteristic",
        "thermoluminescent",
        "inefficaciousnesses",
        "counterinstitutional",
        "electrocardiographic",
        "immunocompetent",
        "counterretaliation",
        "microcrystalline",
        "indistinguishability",
        "antireductionism",
        "immunogenetically",
        "thermoregulations",
        "photomicrography",
        "countercondensation",
        "psychopathological",
        "microcirculation",
        "counteraccusation",
        "hyperintellectual",
        "electroacoustic",
        "counterreformation",
        "noninterventional",
        "superinjunction",
        "neuropeptidases",
        "deoxyribonucleotide",
        "microlepidopterous",
        "ultrarevolutionary",
        "immunoperoxidase",
        "hyperaggressiveness",
        "supercontinental",
        "dehydrochlorinate",
        "unconventionality",
        "indistinctiveness",
        "counterdemonstrator",
        "extraterrestrial",
        "counterexplanation",
        "microinstruction",
        "thermoperiodicity",
        "overidentification",
        "photosynthetically",
        "psychophysiological",
        "immunocompromised",
        "indeterminateness",
        "nonreproducibility",
        "counterdisengagement",
        "microvasculature",
        "psychotomimetic",
        "deindustrialization",
        "underutilization",
        "counterguerilla",
        "counterdeployment",
        "antiparliamentarian",
        "ultraradicalism",
        "counterproliferative",
        "microevolutionary",
        "supererogatorily",
        "immunodiagnostic",
        "intercontinental",
        "photosensitization",
        "counterespionage",
        "deconstructionist",
        "psychophysicist",
        "microenvironmental",
        "ultrarevolutionaries",
        "counterdeployment",
        "immunosuppressive",
        "mispronunciation",
        "counterirritation",
        "noncomprehension",
        "antinationalistic",
        "photosensitivity",
        "counterinstitutional",
        "neurofibromatosis",
        "ultrasegregationist",
        "immunogenicity",
        "misinterpretation",
        "microsporogenesis",
        "counterprogramming",
        "decontamination",
        "photodissociation",
        "interdependence",
        "anticonventional",
        "counterprojection",
        "deindustrialization",
        "ultracrepidarianism",
        "immunotherapeutic",
        "intergovernmental",
        "counterreformation",
        "photosynthetize",
        "electrotherapeutic",
        "ultramicroanalysis",
        "counteraggression",
        "misidentification",
        "micropropagation",
        "counterproposition",
        "superregeneration",
        "indiscernibility",
        "counterrecruitment",
        "photosynthesizing",
        "hyperstimulation",
        "immunohematologist",
        "interrelationship",
        "microdissection",
        "psychotomimetically",
        "indigestibleness",
        "counterretaliate",
        "ultrafastidiousness",
        "counterrevelation",
        "photosynthetically",
        "immunoreactivity",
        "superparamagnetic",
        "indubitableness",
        "photoperiodically",
        "countersecessionist",
        "interconvertibility",
        "microfabrication",
        "counterreformationist",
        "antiparliamentarianism",
        "photosynthesizer",
        "psycholinguistically",
        "superregenerative",
        "ulrarevolutionary",
        "counterdeclaration",
        "immunohematological",
        "indemonstrability",
        "counterincitement",
        "photomechanically",
        "microaerophilic",
        "hyperimmunizations",
        "counterattraction",
        "immunomodulation",
        "antipersonnel",
        "photophosphorylating",
        "microcalorimetrically",
        "counterestablishment",
        "ultramicrotomist",
        "dehydrochlorinase",
        "counterespionages",
        "immunopathologically",
        "neurophysiological",
        "intercommunication",
        "psychogeriatrician",
        "microearthquake",
        "counterreformationary",
        "indistinctivenesses",
        "antiperspirant",
        "counteraggression",
        "dehydrochlorination",
        "ultrarightist",
        "immunodiagnoses",
        "psychopathological",
        "neurofibromatoses",
        "microphotographic",
        "counterirritations",
        "mispronunciations",
        "superintelligence",
        "immunocytochemical",
        "interprofessional",
        "photosynthetically",
        "counterrevelations",
        "ultrasegregationists",
        "counterreformations",
        "microspectrophotometer",
        "deindustrializations",
        "immunohematologists",
        "superindustrialization",
        "interdenominational",
        "counterconditioning",
        "psychobiographical",
        "neurophysiologically",
        "antiferromagnetic",
        "counterproliferations",
        "dehydrochlorinations",
        "immunoelectrophoresis",
        "indistinctiveness",
        "counterdemonstrations",
        "ultramicroscopical",
        "counterintuitive",
        "photosynthetically",
        "immunomodulatory",
        "hyperpigmentation",
        "superconglomerate",
        "counterconditioned",
        "microphotographers",
        "deindustrializing",
        "counterdeployment",
        "psychophysiological",
        "neuroendocrinologist",
        "immunomodulating",
        "ultrarevolutionary",
        "photosensitivities",
        "indeterminatenesses",
        "counterexplanation",
        "antiepileptically",
        "counterinfluences",
        "photosynthetically",
        "microcircuitry",
        "interconnectivity",
        "counterinhibition"
        };
        // Add all these words to our linked list
        for (const string& word : originalWords) {
            insertWord(word);
        }
    }
    
    void insertWord(const string& word) {
        // Adds a new word to the end of the linked list
        WordNode* newNode = new WordNode(word);
        if (!head) {
            head = newNode; // First word gets to be the head
        } else {
            WordNode* current = head;
            while (current->next) {
                current = current->next; // Move to the end of the list
            }
            current->next = newNode; // Attach the new word
    	}
	}
    string getRandomWord() {
        if (!head) return ""; // Return empty string para pag nalimutan ko iadd yung word list
        
        // Count how many words
        int count = 0;
        WordNode* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        
		// Pick a random index
        srand(static_cast<unsigned int>(time(nullptr)));
        int randomIndex = rand() % count;

        // Find the word at that index
        current = head;
        for (int i = 0; i < randomIndex; i++) {
            current = current->next;
        }

        return current->word; // Return the chosen word
	}
	
    ~WordList() {
    	// Clean up all nodes (goodbye, words!)
        while (head) {
            WordNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// High Score Manager Class
class HighScoreManager {
private:
    vector<HighScore> scores; // List of high scores
    const string HIGHSCORE_FILE = "highscores.txt"; // File to save/load scores

public:
    HighScoreManager() {
        loadHighScores(); // Load scores when we start the game
    }

    void addHighScore(const HighScore& score) {
        scores.push_back(score); // Add the new score to the list
        sort(scores.begin(), scores.end(), HighScore::compareScores); // Sort scores (bragging rights are serious business)

        // Keep only the top 10 scores
        if (scores.size() > 10) {
            scores.resize(10);
        }

        saveHighScores(); // Save the updated scores to the file
    }
    void displayHighScores() {
        system("cls"); // Clear the screen
        cout << "\n\t========================== HIGH SCORES ==========================\n";
        cout << "\t" << left << setw(20) << "Name" 
             << setw(10) << "Score" 
             << setw(15) << "Avg Speed" 
             << "Words Typed\n";
        cout << "\t-----------------------------------------------------------------\n";
        
        for (size_t i = 0; i < scores.size(); ++i) {
            cout << "\t" << left << setw(20) << scores[i].name 
                 << setw(10) << scores[i].score 
                 << setw(15) << fixed << setprecision(2) << scores[i].avgSpeed
                 << scores[i].wordsTyped << endl;
        }
        
        cout << "\n\tPress any key to continue...";
        _getch(); // Wait for the user to press a key
    }

private:
    void loadHighScores() {
        ifstream file(HIGHSCORE_FILE); // Open the file
        if (!file) return; // No file? Skip loading.

        scores.clear(); // Clear any existing scores
        string name;
        int score, wordsTyped;
        double avgSpeed;

        while (file >> name >> score >> avgSpeed >> wordsTyped) {
            scores.push_back(HighScore(name, score, avgSpeed, wordsTyped));
        }
        
        file.close(); // Close the file
    }

    void saveHighScores() {
        ofstream file(HIGHSCORE_FILE); // Open the file for writing
        for (const auto& score : scores) {
            file << score.name << " " 
                 << score.score << " " 
                 << score.avgSpeed << " " 
                 << score.wordsTyped << endl;
        }
        file.close(); // Close the file
    }
};

// Global instances
WordList wordList;
HighScoreManager highScoreManager;

// Greedy Score Calculation Function
int calculateGreedyScore(const string& word, double timeTaken) {
    // Avoid dividing by zero (math teachers would cry)
    if (timeTaken <= 0) timeTaken = 0.1;

    int wordComplexity = word.length(); // Longer words are harder, so they score more
    double speedFactor = 1000.0 / timeTaken; // Faster typing means higher points

    // Exponential scoring makes it feel fancy
    int score = static_cast<int>(wordComplexity * speedFactor * log(wordComplexity + 1));

    return max(1, score); // At least give them 1 point (for effort)
}

// Function prototypes
void clearScreen();
void displayMenu(int selectedOption);
void playGame();

void clearScreen() {
    system("cls");
}

void playGame() {
    string playerName; // To remember who is playing
    int score = 0; // Player's score
    int totalAttempts = 0; // Total words typed
    double totalSpeed = 0.0; // Cumulative typing speed

    string userInput; // Stores what the player types
    string initiation; // Start or quit decision

    clearScreen(); // Clean up before we start

    // Title
    cout << "                                                                                          \n"
            " _____  __ __  _____  _____    _____  _____    _____  _____  _____  _____  _____  _____ \n"
            "|_   _||  |  ||  _  ||   __|  |     ||_   _|  |  _  ||  _  ||   __||_   _||   __|| __  |\n"
            "  | |  |_   _||   __||   __|  |-   -|  | |    |   __||     ||__   |  | |  |   __||    -|\n"
            "  |_|    |_|  |__|   |_____|  |_____|  |_|    |__|   |__|__||_____|  |_|  |_____||__|__|\n\n";

    // Prompt for name
    cout << "	Type in your name: ";
    getline(cin, playerName);

    // Game instructions
    cout << "\n	Type as many words as you can as fast as possible, your score is based on how fast you typed." << endl
         << "	Once 2 minutes is over, or you spelt the word incorrectly, its game over!" << endl
         << "	Good luck! :)" << endl;

    // Game initiation
    do {
        cout << "\n	Type 'start' to play the game or 'quit' to go back to the menu" << endl
             << " 	> ";
        cin >> initiation;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (initiation == "start") {
            // Reset game stats
            score = 0;
            totalAttempts = 0;
            totalSpeed = 0.0;
            
            clearScreen();
            
            // Game timer
            auto gameStartTime = chrono::steady_clock::now();
            
            do {
                // Get random word
                string givenWord = wordList.getRandomWord();
                auto start = chrono::steady_clock::now();

                cout << "\n	Your current score: " << score << endl;
                cout << "\n	Type the word: " << givenWord << endl;
                cout << " 	> ";
                getline(cin, userInput);

                auto end = chrono::steady_clock::now();

                // Calculate time taken
                auto elapsedTime = chrono::duration_cast<chrono::duration<double>>(end - start);
                int timeTaken = static_cast<int>(elapsedTime.count() * 1000);

                if (userInput == givenWord) {
                    clearScreen();

                    // Calculate and display typing speed
                    cout << "\n	Typing speed: " << timeTaken << " ms" << endl;

                    // Calculate remaining time
                    auto currentTime = chrono::steady_clock::now();
                    auto elapsedGameTime = chrono::duration_cast<chrono::duration<double>>(currentTime - gameStartTime);
                    int remainingTime = static_cast<int>((120 - elapsedGameTime.count()));
                    cout << "	Time left: " << remainingTime << " seconds" << endl;
                    
                    // Update game stats
                    totalSpeed += timeTaken;
                    totalAttempts++;

                    // Calculate score using greedy algorithm
                    score += calculateGreedyScore(givenWord, timeTaken);
                
                } else {
                    // Game over - incorrect word
                    double averageSpeed = totalAttempts > 0 ? (totalSpeed / totalAttempts) : 0.0;
                    cout << "\n	Game over. You spelt it wrong!" << endl << endl;
                    cout << "	+---------------------------------------+" << endl;
                    cout << "	|             Final Results             |" << endl;
                    cout << "	+---------------------------------------+" << endl;
                    cout << "	 Final score:              " << score << " points " << endl;
                    cout << "	 Total words typed:        " << totalAttempts << " words " << endl;
                    cout << "	 Average typing speed:     " << averageSpeed << " ms " << endl;
                    cout << "	+---------------------------------------+" << endl;
                    
                    // Add high score
                    if (!playerName.empty()) {
                        HighScore newScore(playerName, score, averageSpeed, totalAttempts);
                        highScoreManager.addHighScore(newScore);
                    }
                    
                    break;
                }

                // Check game time
                auto currentTime = chrono::steady_clock::now();
                auto elapsedGameTime = chrono::duration_cast<chrono::duration<double>>(currentTime - gameStartTime);

                if (elapsedGameTime.count() >= 120) {
                    // Time's up
                    double averageSpeed = totalAttempts > 0 ? (totalSpeed / totalAttempts) : 0.0;
                    cout << "\n	Game over. Time's up!" << endl << endl;
                    cout << "	+---------------------------------------+" << endl;
                    cout << "	|             Final Results             |" << endl;
                    cout << "	+---------------------------------------+" << endl;
                    cout << "	 Final score:              " << score << " points " << endl;
                    cout << "	 Total words typed:        " << totalAttempts << " words " << endl;
                    cout << "	 Average typing speed:     " << averageSpeed << " ms " << endl;
                    cout << "	+---------------------------------------+" << endl;
                    
                    // Add high score
                    if (!playerName.empty()) {
                        HighScore newScore(playerName, score, averageSpeed, totalAttempts);
                        highScoreManager.addHighScore(newScore);
                    }
                    
                    break;
                }

            } while (true);

        } else if (initiation == "quit") {
            break;  // Go back to main menu
        } else {
            cout << "	What? I don't understand." << endl;
        }

    } while (true);
}

int main() {
    int selectedOption = 1;

    while (true) {
        displayMenu(selectedOption);

        char key = _getch();  

        if (key == 72) {  // Up arrow key
            selectedOption = (selectedOption > 1) ? selectedOption - 1 : 4;
        } else if (key == 80) {  // Down arrow key
            selectedOption = (selectedOption < 4) ? selectedOption + 1 : 1;
        } else if (key == 13) {  // Enter key
            if (selectedOption == 1) {
                playGame();
            } else if (selectedOption == 2) {
                clearScreen();
                cout << "\n	TYPE IT PASTER! A game where you type a word faster. Yes that's the game." << endl << endl;
                cout << "	Press ENTER to go back to the menu . . .";
                cin.get();
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

void displayMenu(int selectedOption) {
    system("cls");

    // Title
    cout << "                                                                                          \n"
            " _____  __ __  _____  _____    _____  _____    _____  _____  _____  _____  _____  _____ \n"
            "|_   _||  |  ||  _  ||   __|  |     ||_   _|  |  _  ||  _  ||   __||_   _||   __|| __  |\n"
            "  | |  |_   _||   __||   __|  |-   -|  | |    |   __||     ||__   |  | |  |   __||    -|\n"
            "  |_|    |_|  |__|   |_____|  |_____|  |_|    |__|   |__|__||_____|  |_|  |_____||__|__|\n\n";

    // Subtitle
    cout << "   	A game where you type a word fast, do you have what it takes?" << endl;
    cout << "          	Coded by Dela Cruz, Charles Arvin - CPE21S2" << endl << endl;
    cout << "            	Use the arrow keys to navigate the menu" << endl << endl;
    
    // Menu options
    cout << (selectedOption == 1 ? "		> " : "		    ") << "Start this madness" << endl;
    cout << (selectedOption == 2 ? "		> " : "		    ") << "About this game" << endl;
    cout << (selectedOption == 3 ? "		> " : "		    ") << "High Scores" << endl;
    cout << (selectedOption == 4 ? "		> " : "		    ") << "Exit" << endl;
	}	