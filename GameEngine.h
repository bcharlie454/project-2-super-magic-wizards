/*
Author: James Lizotte
Date: 11/29/2023
Description: Header file for the GameEngine class
*/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include"FieldInhabitant.h"
#include"Veggie.h"
#include"Creature.h"
#include"Captain.h"
#include"Rabbit.h"
#include<vector>
#include<cstdlib>
#include<fstream>
#include<time.h>
#include<cmath>

class GameEngine
{
private:
    FieldInhabitant*** field; // The 2d dynamic array of FieldInhabitant pointers that represent the game board
    int height; // Game board height
    int width; // Game board width
    int score; // Player score
    const int NUMBEROFVEGGIES = 30; // Constant value of number of starting veggies
    const int NUMBEROFRABBITS = 5; // Constant value of number of starting rabbits
    Captain* captainVeggie;  // Captain pointer to store captain object
    vector<Rabbit*> rabbits; // Vector of rabbit objects
    vector<Veggie*> veggies; // Vector of all the possible veggie objects
    //Snake* snake; // Snake pointer to store the snake

    void initVeggies(); // Initialization functions for each thing
    void initCaptain();
    void initRabbits();
    void initSnake();

    void moveCptVertical(int); // Player Movement Functions
    void moveCptHorizontal(int);

public:
    void initializeGame(); //Game Initalization
    void intro(); // Game Intro

    void printField(); // Print out the field

    void moveRabbits(); // NPC Movement Functions
    void moveCaptain();
    void moveSnake();

    void gameOver(); // Game Outro

    int getScore(); // Getter for Score

    int remainingVeggies(); // Outputs the amount of remaining Veggies

    void resetSnake(int, int);
    
};

#endif
