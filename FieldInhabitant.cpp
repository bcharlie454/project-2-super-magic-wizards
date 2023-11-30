/*
Author: James Lizotte
Date: 11/27/2023
Description: Funciton file for the FieldInhabitant superclass
*/

#include"FieldInhabitant.h"

// @brief FieldInhabitant Superclass Constructor
// @param symbol The symbol of the inhabitant
FieldInhabitant::FieldInhabitant(string symbol)
{
    this->symbol = symbol;
}

// @brief Getter function for the symbol of the inhabitant
// @return the symbol of the inhabitant
string FieldInhabitant::getSymbol()
{
    return symbol;
}

// @brief Setter funtion for the symbol of the inhabitant
// @param symbol The symbol of the inhabitant
void FieldInhabitant::setSymbol(string symbol)
{
    this->symbol = symbol;
}

// @brief Do nothing destructor to ensure that the subclass destructor gets called
FieldInhabitant::~FieldInhabitant()
{
}
