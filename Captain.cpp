/*
Author: Rakesh Gummapu
Date: 11/29/2023
Description: Header file for the Captain subclass
*/

#include "Captain.h"

// Constructor for the Captain class
// Initializes the Captain at a given position with a symbol 'V'
// @param x: Initial X-coordinate of the Captain
// @param y: Initial Y-coordinate of the Captain
Captain::Captain(int x, int y) : Creature("V", x, y) {}

// Adds a Veggie object to the Captain's collection
// @param veggie: Pointer to the Veggie object being collected
void Captain::collectVeggie(Veggie* veggie) 
{
    collectedVeggies.push_back(veggie);
}

// Getter function for the collection of veggies
// @return: Constant reference to the vector of collected Veggie pointers
const std::vector<Veggie*>& Captain::getCollectedVeggies() const 
{
    return collectedVeggies;
}

// @brief Deletes last veggie collected
// @return Point value of the deleted Veggie
int Captain::deleteVeggie()
{
    Veggie* last; // Create temp veggie variable

    if(collectedVeggies.size() == 0) // if there is no veggies, then do nothing
    return 0;

    last = collectedVeggies.back(); // Get last veggie
    int lastVeggie = last->getPointValue(); // Get last veggie point value
    collectedVeggies.pop_back(); // delete veggie
    return lastVeggie; // return veggie point value
}
