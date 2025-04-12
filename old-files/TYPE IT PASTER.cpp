// TYPE IT PASTER - A game where you type fast, that's it
// Coded by Dela Cruz, Charles Arvin P. - CPE11S1

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <windows.h>
#include <conio.h>

using namespace std;

// Function prototypes
string getRandomWord();
void clearScreen();
void displayMenu(int selectedOption);
void playGame();

int main() {
    int selectedOption = 1;

    while (true) {
        displayMenu(selectedOption);

        char key = _getch();  // Get a key press 

        if (key == 72) {  // Up arrow key
            selectedOption = (selectedOption > 1) ? selectedOption - 1 : 3;

        } else if (key == 80) {  // Down arrow key
            selectedOption = (selectedOption < 3) ? selectedOption + 1 : 1;

        } else if (key == 13) {  // Enter key
        
    		// Actions for each menu, basta eto yung menu di ko na maenglish naubusan nako
            if (selectedOption == 1) { // Start this madness
                playGame();

            } else if (selectedOption == 2) { // About this game
                clearScreen();
                cout << "\n	TYPE IT PASTER! A game where you type a word faster. Yes that's the game." << endl << endl << endl
                	 << "	Note to Sir Nava: " << endl
					 <<	"	Napansin ko po kasi na halos lahat ng gagawin ng iba is story-based RPG. And gusto ko" << endl
					 << " 	ko lang po maiba. Gusto ko po kase na may pagkareplayability yung magagawa kong laro, " << endl
					 << " 	so naisip ko po na itry yung mala-minigame na approach. At first po naisip ko na fighting" << endl
					 << "	word game yung gagawin ko, mostly inspired sa Bookworm Adventures kaso feeling ko limitado" << endl
					 << "	ako sa oras and sa current knowledge ko. So after ng ilang brainstorming ito po yung naisip" << endl
					 << "	kong gawin. I think nareach ko naman po yung 5 scenario minimum kase literal na infinite" << endl
					 << "	attempts tong nagawa ko." << endl << endl
					 << "	Wala ito sir shinare ko lang kung pano ko nacome-up tong laro HAHAHA, yun lang po and thank you!" << endl << endl << endl; 
                cout << "	Press ENTER to go back to the menu . . .";
                cin.get(); // Program waits for ENTER press

            } else if (selectedOption == 3) { // Exit
                cout << "\nExiting..." << endl;
                return 0;
            }
        }
    }

    return 0;
}

// The actual game function
void playGame() {
	
    int score = 0;
    int totalAttempts = 0;
    double totalSpeed = 0.0;
    
    string userInput;
    string initiation;

    clearScreen();

	// Title
	cout << "                                                                                          \n"
            " _____  __ __  _____  _____    _____  _____    _____  _____  _____  _____  _____  _____ \n"
            "|_   _||  |  ||  _  ||   __|  |     ||_   _|  |  _  ||  _  ||   __||_   _||   __|| __  |\n"
            "  | |  |_   _||   __||   __|  |-   -|  | |    |   __||     ||__   |  | |  |   __||    -|\n"
            "  |_|    |_|  |__|   |_____|  |_____|  |_|    |__|   |__|__||_____|  |_|  |_____||__|__|\n\n";

	// Subtitle
    cout << "   	A game where you type a word fast, do you have what it takes?" << endl;
    cout << "          	Coded by Dela Cruz, Charles Arvin - CPE11S1" << endl << endl;
    
    // Instructions
    cout << "\n	Type as many words as you can as fast as possible, your score is based on how fast you typed." << endl
     	 << "	Once 2 minutes is over, or you spelt the word incorrectly, its game over!" << endl
         << "	Good luck! :)" << endl;
	
	// Game initiation
    do {
        cout << "\n	Type 'start' to play the game or 'quit' to go back to the menu" << endl
             << " 	> ";
        cin >> initiation;

        if (initiation == "start") {
        	
        	// To reset scores, speed and attempts when the player restarts
        	score = 0;
        	totalAttempts = 0;
        	totalSpeed = 0.0;
        	
            clearScreen();
            
            // A game timer starts
            chrono::steady_clock::time_point gameStartTime = chrono::steady_clock::now();
            chrono::steady_clock::time_point currentTime;

            do {
            	
            	// To measure typing speed each word
                string givenWord = getRandomWord();
                chrono::steady_clock::time_point start, end;

                start = chrono::steady_clock::now();

                cout << "\n	Your current score: " << score << endl; // Shows the current score
                cout << "\n	Type the word: " << givenWord << endl // Shows the current word
                     << " 	> ";
                cin >> userInput;

                end = chrono::steady_clock::now();

                if (userInput == givenWord) { // Check if the user typed the correct word
                    clearScreen();

                    chrono::duration<double> elapsedTime = chrono::duration_cast<chrono::duration<double>>(end - start);
                    int timeTaken = static_cast<int>(elapsedTime.count() * 1000);
                    cout << "\n	Typing speed: " << timeTaken << " ms" << endl; // Shows the typing speed

                    currentTime = chrono::steady_clock::now();
                    chrono::duration<double> elapsedGameTime = chrono::duration_cast<chrono::duration<double>>(currentTime - gameStartTime);
                    int remainingTime = static_cast<int>((120 - elapsedGameTime.count()));
                    cout << "	Time left: " << remainingTime << " seconds" << endl;  // Shows the remaining time left
                    
                    totalSpeed += timeTaken; // For getting the average typing speed throughout the game
                    totalAttempts++; // For getting the total words the player typed throughout the game

                    score += (100 / elapsedTime.count()); // To measure the score based on how fast the player typed
				
				// Shows the game scoreboard after the game when the user typed the word incorrectly
                } else {
                	double averageSpeed = totalSpeed / totalAttempts;
                    cout << "\n	Game over. You spelt it wrong!" << endl << endl;
					cout << "	+---------------------------------------+" << endl;
					cout << "	|             Final Results             |" << endl;
					cout << "	+---------------------------------------+" << endl;
					cout << "	 Final score:              " << score << " points " << endl;
					cout << "	 Total words typed:        " << totalAttempts << " words " << endl;
					cout << "	 Average typing speed:     " << averageSpeed << " ms " << endl;
					cout << "	+---------------------------------------+" << endl;
                    break;
                }

                currentTime = chrono::steady_clock::now();
                chrono::duration<double> elapsedGameTime = chrono::duration_cast<chrono::duration<double>>(currentTime - gameStartTime);

                // Limits the game time for 120 seconds or 2 minutes, then shows the game scoreboard
                if (elapsedGameTime.count() >= 120) {
                	double averageSpeed = totalSpeed / totalAttempts;
                   	cout << "\n	Game over. Times up!." << endl << endl;
					cout << "	+---------------------------------------+" << endl;
					cout << "	|             Final Results             |" << endl;
					cout << "	+---------------------------------------+" << endl;
					cout << "	 Final score:              " << score << " points " << endl;
					cout << "	 Total words typed:        " << totalAttempts << " words " << endl;
					cout << "	 Average typing speed:     " << averageSpeed << " ms " << endl;
					cout << "	+---------------------------------------+" << endl;

                    break;
                }

            } while (true);

        } else if (initiation == "quit") {
            break;  // Go back to the main menu

		// When other input is used
        } else {
            cout << "	What? I don't understand." << endl;
        }

    } while (true);
}

// Random word generator for the game
// Note: I listed 299 words for the game, wala lang nakakatuwa lang HAHAHAHA
string getRandomWord() {
    vector<string> words = {
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

    srand(static_cast<unsigned int>(time(nullptr))); // Random number generator using time as seed
    int randomNum = rand() % words.size();
    return words[randomNum];
}

// Function to clear the screen
void clearScreen() {
    system("cls");
}

// Main Menu
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
    cout << "          	Coded by Dela Cruz, Charles Arvin - CPE11S1" << endl << endl;
    cout << "            	Use the arrow keys to navigate the menu" << endl << endl;
    
    // Menu options
    cout << (selectedOption == 1 ? "		> " : "		    ") << "Start this madness" << endl;
    cout << (selectedOption == 2 ? "		> " : "		    ") << "About this game" << endl;
    cout << (selectedOption == 3 ? "		> " : "		    ") << "Exit" << endl;
    
}