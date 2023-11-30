/*
Author: James Lizotte
Date: 11/29/2023
Description: Function file for the GameEngine class
*/

#include"GameEngine.h"

// @brief Initialization function for the various objects in the game. Commented out means it isn't in the program
void GameEngine::initializeGame()
{
    initVeggies();  
    //initCaptain();
    //initRabbits();
    //initSnake();

    score = 0;
}

// @brief Reads in the veggie file and initalizes the entire field
void GameEngine::initVeggies()
{
    
    string fileName, line; // Name of file, input variable for file reading
    
    cout << "Please enter the name of the veggie file for this game: ";
    cin >> fileName;

    ifstream inStream;
    inStream.open(fileName);

    while (!inStream.is_open())  //Check if file exists and asks for new one if no
    {
        cout << "That file doesn't exist!\nPlease enter in a new file name: ";
        inStream >> fileName;
        inStream.open(fileName);
    }

    getline(inStream, line, ','); // skipping to the field size dimensions

    getline(inStream, line, ','); // get field height
    height = stoi(line);

    inStream >> line;    // get field width. cin because we moving to the end of the line
    width = stoi(line);

    while (!inStream.eof()) //Read the rest of the veggies
    {
        string name, symbol; // Temp values for each veggie parameter
        int points;

        getline(inStream, name, ','); //Get name
        getline(inStream, symbol, ','); //Get symbol
        inStream >> points; //Get point value and move to next line

        veggies.push_back(new Veggie(symbol, name, points)); //Add the new veggie to the end of the vecotr
    }

    inStream.close(); // Close file

    field = new FieldInhabitant**[height]; // Make field height

    for (int i = 0; i < height; i++)
    {
        field[i] = new FieldInhabitant*[width]; // Make field width

        for (int j = 0; j < width; j++)
        {
            field[i][j] = nullptr; // Initialize everything to a nullptr
        }
    }
    
    srand(time(0)); // Random seed for veggie location

    for (int i = 0; i < NUMBEROFVEGGIES; i++)
    {
        int x = 0, y = 0;
        
        while (Veggie* temp = dynamic_cast<Veggie*>(field[y][x])) //Test if the space already has a veggie
        {
        x = rand() % width; // randomly choose location
        y = rand() % height;
        }

        int choice = rand () % veggies.size(); // Randomly choose veggie

        field[y][x] = veggies[choice];
    }
}

// @brief Initialization function for the Captain object in the game
void GameEngine::initCaptain()
{

}

// @brief Initilization function for the Rabbit objects in the game
void GameEngine::initRabbits()
{

}

// @brief Initilization function for the Snake object in the game
void GameEngine::initSnake()
{

}

// @brief Counts the field for how many veggies remain in the game
// @return The amount of veggies remaining in the game
int GameEngine::remainingVeggies()
{
    int count; // Counter variable

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if(Veggie* temp = dynamic_cast<Veggie*>(field[i][j])) //Checks if the space is a veggie
            count++; // if it is, then increment the count
        }
    }

    return count; // output count
    
}

// @brief Introduction statement and other gameplay information
void GameEngine::intro()
{
    cout << "Welcome to Captian Veggie(TM)!" << endl; // Intro statement
    cout << "Rabbits have invaded your garden!" << endl;
    cout << "You must collect all of your vegtables before those" << endl;
    cout << "bouncy vermin eat them all (You can't harm the rabbits)." << endl;
    cout << "Beware of the snake who will follow you! If you meet" << endl;
    cout << "the snake, then poison will enter your boddy, reducing" << endl;
    cout << "your body to a lifeless husk, destined to be eaten" << endl;
    cout << "by the worms (with the only gameplay effect being" << endl;
    cout << "loosing the last 5 veggies you collected)" << endl;
    cout << "Each veggie is worth a different amount, so go for" << endl;
    cout << "the high score!" << endl << endl;

    cout << "The veggies are:" << endl;
    for (int i = 0; i < veggies.size(); i++) // Output the veggies currently in play
    {
        cout << veggies[i]->getName();
        cout << ": " << veggies[i]->getSymbol() << " "  << veggies[i]->getPointValue() << " points" << endl;
    }
    cout << endl;

    cout << "Captain Veggie is V. The rabbits are R's. The snake is S" << endl << endl;
    
    cout << "Good luck!" << endl;
    
}

// @brief Prints out the field in a grid format
void GameEngine::printField()
{
    for (int i = 0; i < width * 3 + 2; i++) // print out top border
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        cout << "#"; // print out left border
        
        for (int j = 0; j < width; j++)
        {
            if(field[i][j] == nullptr) // Print out space if nothing there
            cout << "   ";

            else
            cout <<" " << field[i][j]->getSymbol() << " "; // Print out appropriate symbol
        }
        
        cout << "#" << endl; // print out right border
    }
    
    for (int i = 0; i < width * 3 + 2; i++) // print out bottom border
    {
        cout << "#";
    }
    cout << endl;
    
}

// @brief Getter function for the current player score
// @return current player score
int GameEngine::getScore()
{
    return score;
}

// @brief Rabbit movement function
void GameEngine::moveRabbits()
{

}

// @brief Vertical movement function for the captian
// @param move User input value corresponding to up or down
void GameEngine::moveCptVertical(int move) //Can change the int variable name to something that makes more sense
{

}

// @brief Horizontal movement function for the captain
// @param move User input value corresponding to left or right
void GameEngine::moveCptHorizontal(int move)
{

}

// @brief Overall movement function for the captain
void GameEngine::moveCaptain()
{

}

// @brief Snake movement function
void GameEngine::moveSnake()
{

}

// @brief Tells the user game over. Also informs them of their score and position on the leaderboard
void GameEngine::gameOver()
{
    cout << "GAME OVER!" << endl;
    cout << "You got these vegtables:" << endl;
    
    cout << "TEMP VEGGIES. REAL VEGGIES WILL BE GIVEN SHORTLY" << endl; // replace with output loop of the captain's veggies

    cout << "Your score was: " << getScore() << endl; // output score

    cout << "Please enter your 3 initials for the score: ";
    string initials;
    cin >> initials;

    cout << "Name	Score" << endl;

    if(getScore() > 62)
        cout << initials << "		" << getScore() << endl;

    cout << "HGH		62" << endl;

    if(getScore() <= 62 && getScore() > 50)
        cout << initials << "		" << getScore() << endl;
    
    cout << "JEH		50" << endl;

    if(getScore() <= 50 && getScore() > 21)
        cout << initials << "		" << getScore() << endl;
    
    cout << "CCH		21" << endl;

    if(getScore() <= 21)
        cout << initials << "		" << getScore() << endl;
    
}