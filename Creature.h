/*
Author: Rakesh Gummapu
Date: 11/29/2023
Description: Header file for the Creature subclass of FieldInhabitant superclass
*/

#ifndef CREATURE_H
#define CREATURE_H

#include "FieldInhabitant.h"
#include <string>

class Creature : public FieldInhabitant //Creature subclass from the FeildInhabitat superclass
{
protected:
    int x, y;

public:
    Creature(std::string symbol, int x, int y);
    virtual void move(int dx, int dy);

    int getX() const;  
    int getY() const;
    void setPosition(int x, int y);
};

#endif // CREATURE_H
