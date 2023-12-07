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
    initCaptain();
    initRabbits();
    initSnake();

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
        cin >> fileName;
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

        string symbol = veggies[choice]->getSymbol();
        string name = veggies[choice]->getName();
        int points = veggies[choice]->getPointValue();

        field[y][x] = new Veggie(symbol,name,points);
    }
}

// @brief Initialization function for the Captain object in the game
void GameEngine::initCaptain()
{
    int x = rand() % width;
    int y = rand() % height;

    // might need to edit this using dynamic_cast in case this nullptr strategy doesn't work
    while(field[y][x] != nullptr) // pick a new random location if location is already occupied
    {
        x = rand() % width;
        y = rand() % height;
    }

    captainVeggie = new Captain(x,y); // instantiates the captain object
    field[y][x] = captainVeggie; // stores the captain pointer in the specific field location
}

// @brief Initilization function for the Rabbit objects in the game
void GameEngine::initRabbits()
{
     for (int i = 0; i < NUMBEROFRABBITS; ++i)
    {
        int x, y;

        do
        {
            x = rand() % width; // Random X-coordinate within field boundaries
            y = rand() % height; // Random Y-coordinate within field boundaries

        } while (field[y][x] != nullptr); // Ensure the chosen position is unoccupied

        Rabbit* newRabbit = new Rabbit(x, y); // Create a new Rabbit object
        rabbits.push_back(newRabbit); // Add the Rabbit to the vector of rabbits
        field[y][x] = newRabbit; // Place the Rabbit on the field
    }

}

// @brief Initilization function for the Snake object in the game
void GameEngine::initSnake()
{
    int x = rand() % width;
    int y = rand() % height;

    // Taken from The initialize Captian function. If that doesn't work, then this must change as well
    while(field[y][x] != nullptr) // pick a new random location if location is already occupied
    {
        x = rand() % width;
        y = rand() % height;
    }

    snake = new Snake(x,y); // Create snake object and assign it the corresponding location
    field[y][x] = snake;
}

// @brief Counts the field for how many veggies remain in the game
// @return The amount of veggies remaining in the game
int GameEngine::remainingVeggies()
{
    int count = 0; // Counter variable

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
    for (auto& rabbit : rabbits) // Loop through all rabbits
    {
        int dx = rand() % 3 - 1; // Generate a random movement delta for x (-1, 0, 1)
        int dy = rand() % 3 - 1; // Generate a random movement delta for y (-1, 0, 1)

        int newX = rabbit->getX() + dx;
        int newY = rabbit->getY() + dy;

        // Boundary check
        if (newX < 0 || newX >= width || newY < 0 || newY >= height)
        {
            continue; // Skip the rest of the loop if new position is outside boundaries
        }

        // Check if the new position is occupied by another rabbit or the captain
        if (dynamic_cast<Rabbit*>(field[newY][newX]) != nullptr || dynamic_cast<Captain*>(field[newY][newX]) != nullptr || dynamic_cast<Snake*>(field[newY][newX]) != nullptr)
        {
            continue; // Skip the rest of the loop if new position is occupied
        }

        // Check if the rabbit moves into a space with a vegetable
        if (Veggie* veggie = dynamic_cast<Veggie*>(field[newY][newX]))
        {
            // Consume the vegetable
            delete veggie; // Assume proper memory management is handled
        }

        // Move the rabbit
        field[rabbit->getY()][rabbit->getX()] = nullptr; // Set previous position to nullptr
        rabbit->setPosition(newX, newY); // Update rabbit's position
        field[newY][newX] = rabbit; // Place rabbit in new position on the field
    }

}

// @brief Vertical movement function for the captian
// @param move User input value corresponding to up or down
void GameEngine::moveCptVertical(int move) //Can change the int variable name to something that makes more sense
{
    // the convention will be to set +1 to move DOWN, and -1 to move UP (due to how the field locations are indexed)
    int x_cur = captainVeggie->getX();
    int y_cur = captainVeggie->getY();    
    if(field[y_cur+move][x_cur] == nullptr)
    {
        captainVeggie->setPosition(x_cur,y_cur+move);
        field[y_cur+move][x_cur] = captainVeggie;
        field[y_cur][x_cur] = nullptr;
    }

    else if(Veggie* temp = dynamic_cast<Veggie*>(field[y_cur+move][x_cur]))
    {
        captainVeggie->setPosition(x_cur,y_cur+move);
        cout << "You've collected a delicious " << temp->getName() << "!" << endl;
        captainVeggie->collectVeggie(temp);
        score += temp->getPointValue();
        field[y_cur+move][x_cur] = captainVeggie;
        field[y_cur][x_cur] = nullptr;
    }

    else if(dynamic_cast<Rabbit*>(field[y_cur+move][x_cur]) != nullptr)
    {
        cout << "You should not step on the rabbits!" << endl;
    }
    else
    {
        cout << "That's a snake!" << endl;
    }
}

// @brief Horizontal movement function for the captain
// @param move User input value corresponding to left or right
void GameEngine::moveCptHorizontal(int move)
{
    // convention will be to set +1 to RIGHT, and -1 to LEFT
    int x_cur = captainVeggie->getX();
    int y_cur = captainVeggie->getY();    
    
    if(field[y_cur][x_cur+move] == nullptr)
    {
        captainVeggie->setPosition(x_cur+move,y_cur);
        field[y_cur][x_cur+move] = captainVeggie; 
        field[y_cur][x_cur] = nullptr;
    }

    else if(Veggie* temp = dynamic_cast<Veggie*>(field[y_cur][x_cur+move]))
    {
        captainVeggie->setPosition(x_cur+move,y_cur);
        cout << "You've collected a delicious " << temp->getName() << "!" << endl;
        captainVeggie->collectVeggie(temp);
        score += temp->getPointValue();
        field[y_cur][x_cur+move] = captainVeggie;
        field[y_cur][x_cur] = nullptr;
    }

    else if(dynamic_cast<Rabbit*>(field[y_cur][x_cur+move]) != nullptr)
    {
        cout << "You should not step on the rabbits!" << endl;
    }
    else
    {
        cout << "That's a snake!" << endl;
    }
}

// @brief Overall movement function for the captain
void GameEngine::moveCaptain()
{
    char direction;
    int x_cur = captainVeggie->getX();
    cout << x_cur;
    int y_cur = captainVeggie->getY();
    cout << y_cur << endl;
    cout << "Which direction would you like to move in: ";
    cin >> direction;
    direction = toupper(direction);
    switch (direction)
    {
    case 'w':
    case 'W':
        if(y_cur == 0)
            cout << "You cannot move outside the garden!" << endl;
        else
            moveCptVertical(-1);
        break;
    case 'a':
    case 'A':
        if(x_cur == 0)
            cout << "You cannot move outside the garden!" << endl;
        else
            moveCptHorizontal(-1);
        break;    
    case 's':
    case 'S':
        if(y_cur+1 == height)
            cout << "You cannot move outside the garden!" << endl;
        else
            moveCptVertical(1);
        break;
    case 'd':
    case 'D':
        if(x_cur+1 == width)
            cout << "You cannot move outside the garden!" << endl;
        else
            moveCptHorizontal(1);  
        break;

    default:
        cout << "That is not a valid direction!" << endl;
        break;
    }
}

// @brief Snake movement function
void GameEngine::moveSnake()
{
    int xSnk = snake->getX();//Get snake position
    int ySnk = snake->getY();

    int xCap = captainVeggie->getX();//Get captain position
    int yCap = captainVeggie->getY();

    int dist = 0;
    double shortDist = 0; //The distance to the captain, and the current shortest distance

    char dir = 0; // Chosen direction of movement

    double distN = sqrt(pow(xCap - xSnk, 2) + pow(yCap - (ySnk-1), 2)); // find the vectors to the captain after moving in each direction
    double distS = sqrt(pow(xCap - xSnk, 2) + pow(yCap - (ySnk+1), 2));
    double distE = sqrt(pow(xCap - (xSnk+1), 2) + pow(yCap - ySnk, 2));
    double distW = sqrt(pow(xCap - (xSnk-1), 2) + pow(yCap - ySnk, 2));

    shortDist = min(distN, min(distS, min(distE, distW))); // find which one is shortest

    if(shortDist == distN) // decide which way to move based on minimum distance
    {
        cout << "Moveing North" << endl;
        if(xSnk == xCap && ySnk-1 == yCap) // check if captain is in the space being moved to
        {
            resetSnake(xSnk, ySnk);
        }
        else if (field[ySnk-1][xSnk] == nullptr) // check if the space is otherwise empty
        {
            snake->setPosition(xSnk, ySnk-1);
            field[ySnk-1][xSnk] = snake; 
            field[ySnk][xSnk] = nullptr;
        }
        else // don't move if there is anything in the way
        {
            cout << "Movement Failure" << endl;
        }      
    }
    else if(shortDist == distS)
    {
        cout << "Moving South" << endl;
        if(xSnk == xCap && ySnk+1 == yCap)
        {
            resetSnake(xSnk, ySnk);
        }
        else if (field[ySnk+1][xSnk] == nullptr)
        {
            snake->setPosition(xSnk, ySnk+1);
            field[ySnk+1][xSnk] = snake; 
            field[ySnk][xSnk] = nullptr;
        }
        else
        {
            cout << "Movement Failure" << endl;
        }
    }
    else if(shortDist == distE)
    {
        cout << "Moving East" << endl;
        if(xSnk+1 == xCap && ySnk == yCap)
        {
            resetSnake(xSnk, ySnk);
        }
        else if (field[ySnk][xSnk+1] == nullptr)
        {
            snake->setPosition(xSnk+1, ySnk);
            field[ySnk][xSnk+1] = snake; 
            field[ySnk][xSnk] = nullptr;
        }
        else
        {
            cout << "Movement Failure" << endl;
        }
    }
    else if(shortDist == distW)
    {
        cout << "Moving West" << endl;
        if(xSnk-1 == xCap && ySnk == yCap)
        {
            resetSnake(xSnk, ySnk);
        }
        else if (field[ySnk][xSnk-1] == nullptr)
        {
            snake->setPosition(xSnk-1, ySnk);
            field[ySnk][xSnk-1] = snake; 
            field[ySnk][xSnk] = nullptr;
        }
        else
        {
            cout << "Movement Failure" << endl;
        }
    }
    else
    {
        cout << "Direciton Failure" << endl;
    }
}

// @brief Tells the user game over. Also informs them of their score and position on the leaderboard
void GameEngine::gameOver()
{
    cout << "GAME OVER!" << endl;
    cout << "You got these vegtables:" << endl;
    
    cout << "TEMP VEGGIES. REAL VEGGIES WILL BE GIVEN SHORTLY" << endl; // replace with output loop of the captain's veggies

    cout << "Your score was: " << getScore() << endl; // output score
}

// @brief Takes vegtables from captain veggie and resets the snake position
void GameEngine::resetSnake(int xSnk, int ySnk)
{
    cout << "The snake has captured some of your veggies!" << endl;
    field[ySnk][xSnk] = nullptr;
    
    for (int i = 0; i < 5; i++) // delete last five veggies
    {
        int deleted = captainVeggie->deleteVeggie();
        score = score-deleted;
    }

    int x = rand() % width; // re-randomize snake location
    int y = rand() % height;

    // Taken from The initialize Captian function. If that doesn't work, then this must change as well
    while(field[y][x] != nullptr) // pick a new random location if location is already occupied
    {
        x = rand() % width;
        y = rand() % height;
    }

    snake->setPosition(x,y); // actually reset position
    field[y][x] = snake;

}
