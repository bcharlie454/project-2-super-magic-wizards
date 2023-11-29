/*
Author: Rakesh Gummapu
Date: 11/29/2023
Description: Header file for the Rabbit subclass
*/

#ifndef RABBIT_H
#define RABBIT_H

#include "Creature.h"
#include <string>

class Rabbit : public Creature 
{
public:
    Rabbit(int x, int y);
    void moveRandomly(); 
};

#endif // RABBIT_H
