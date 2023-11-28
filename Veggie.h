/* Author: Charles Beall
Today's Date: 28 November 2023
Description: Header file for Veggie class,
which inherits from FieldInhabitant superclass
*/

#ifndef VEGGIE_H
#define VEGGIE_H

#include "FieldInhabitant.h"

class Veggie : public FieldInhabitant
{
    private:
        string name; // name of veggie
        int pointValue; // number of points the veggie is worth
    public:
        Veggie(string,string,int); // constructor
        string getName(); // getter for name
        int getPointValue(); // getter for pointValue
        void setName(string); // setter for name
        void setPointValue(int); // setter for PointValue
};

#endif