/*
Author: Rakesh Gummapu
Date: 11/29/2023
Description: Function file for the Rabbit subclass
*/

#include "Rabbit.h"
#include <cstdlib>  // for random number generator 

// Constructor for the Rabbit class
// Initializes the Rabbit at a given position with a symbol 'R'
// @param x: Initial X-coordinate of the Rabbit
// @param y: Initial Y-coordinate of the Rabbit
Rabbit::Rabbit(int x, int y) : Creature("R", x, y) {}

// Moves the Rabbit randomly on the field
// The Rabbit can move up, down, left, right, diagonally, or stay in place
void Rabbit::moveRandomly() {
    // Calculate random movement in the X and Y directions
    int dx = rand() % 3 - 1; // Results in -1, 0, or 1
    int dy = rand() % 3 - 1; // Results in -1, 0, or 1

    // Move the Rabbit by the calculated deltas
    move(dx, dy);
}

