/*
Author: James Lizotte
Date: 11/27/2023
Description: Header file for the FieldInhabitant superclass
*/

#ifndef FIELDINHABITANT_H
#define FIELDINHABITANT_H

#include<iostream>
using namespace std;

class FieldInhabitant //FieldInhabitant Superclass
{
private:
    string symbol;

public:
    FieldInhabitant(string); // Constructor function
    
    string getSymbol(); //Getter function for the symbol of the inhabitant
    void setSymbol(string); //Setter function for the symbol of the inhabitant
    
    virtual ~FieldInhabitant(); //Must be defined in the subclass
};

#endif
