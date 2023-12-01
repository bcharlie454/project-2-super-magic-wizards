/*
Author: James Lizotte
Date: 11/30/2023
Description: Main file for the entire project
*/

#include"GameEngine.h"

int main()
{
    GameEngine game; // Create game object

    game.initializeGame(); // Initialize the various objects in the game

    game.intro(); // Output introduction text

    int remainingVeggies = game.remainingVeggies(); // initialize initial veggies

    while (remainingVeggies > 0) // main game function
    {
        cout << game.remainingVeggies() << " veggies remaining. Current score: " << game.getScore() << endl; // print out current gamestate

        game.printField(); // print out current game board
        
        game.moveRabbits(); // Decide the rabbit's move for the next round

        game.moveCaptain(); // Determine the captain's move for the next round

        game.moveSnake(); // Decide on the snake's move for the next round

        remainingVeggies = game.remainingVeggies(); // Update veggie count. Commented out until things can move
    }
    
    game.gameOver();
}