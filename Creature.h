/*
Author: Rakesh Gummapu
Date: 11/29/2023
Description: Header file for the Captain subclass from Creature super calss
*/

#ifndef CAPTAIN_H
#define CAPTAIN_H

#include "Creature.h"
#include "Veggie.h"
#include <vector>
#include <string>

class Captain : public Creature 
{
    std::vector<Veggie*> collectedVeggies;

public:
    Captain(int x, int y);

    void collectVeggie(Veggie* veggie);
    const std::vector<Veggie*>& getCollectedVeggies() const;
};

#endif // CAPTAIN_H
