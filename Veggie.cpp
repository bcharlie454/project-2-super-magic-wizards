/* Author: Charles Beall
Today's Date: 28 November 2023
Description: Function definitions for Veggie class
*/

#include "Veggie.h"

// @ brief constructor function for Veggie class
// @param symbol The Veggie's symbol: passed from FieldInhabitant constructor
// @param name Name of the Veggie
// @param pointValue How many points the Veggie is worth
Veggie::Veggie(string symbol, string name, int pointValue) : FieldInhabitant(symbol)
{
    this->name = name;
    this->pointValue = pointValue;
}

// @brief getter function for Veggie name
// @return the name of the Veggie
string Veggie::getName()
{
    return name;
}

// @brief getter function for Veggie point value
// @return the point value of the Veggie
int Veggie::getPointValue()
{
    return pointValue;
}

// @brief setter function for Veggie's name
// @param newName Name you want to set the Veggie object to
void Veggie::setName(string newName)
{
    this->name = newName;
}

// @brief setter function for Veggie's point value
// @param newPointValue Point value you want to set the Veggie object to
void Veggie::setPointValue(int newPointValue)
{
    this->pointValue = newPointValue;
}