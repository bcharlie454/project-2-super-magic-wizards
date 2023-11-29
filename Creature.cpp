/*
Author: Rakesh Gummapu
Date: 11/29/2023
Description: Function file for the Creature subclass
*/

#include "Creature.h"

// Constructor for the Creature class
// @param symbol: The Creature's symbol, passed to the FieldInhabitant constructor
// @param x: Initial X-coordinate of the Creature
// @param y: Initial Y-coordinate of the Creature
Creature::Creature(std::string symbol, int x, int y) : FieldInhabitant(symbol), x(x), y(y) {}

// Moves the Creature by a given delta in the x and y directions
// @param dx: Change in the X-coordinate
// @param dy: Change in the Y-coordinate
void Creature::move(int dx, int dy) {
    x += dx;
    y += dy;
}

// Getter function for the Creature's X-coordinate
// @return: The X-coordinate of the Creature
int Creature::getX() const { 
    return x; 
}

// Getter function for the Creature's Y-coordinate
// @return: The Y-coordinate of the Creature
int Creature::getY() const { 
    return y; 
}

// Sets the position of the Creature
// @param newX: New X-coordinate for the Creature
// @param newY: New Y-coordinate for the Creature
void Creature::setPosition(int newX, int newY) { 
    x = newX; 
    y = newY; 
}
