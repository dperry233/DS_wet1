//
// Created by Krumpet on 27-Nov-16.
//

#include "Animal.h"

/*
 * Class constructor
 */

Animal::Animal(int level, int id) : Level(level), ID(id) {
    if (level < 0 || id <= 0) throw badAnimalInput;
}

// explicit c'tor for Animal with 0 danger level
explicit Animal::Animal(int id) : Level(0), ID(id) {}

// copy c'tor
Animal::Animal(const Animal &original) : Level(original.Level), ID(original.ID) {}

Animal::~Animal() {};

int Animal::getLevel() {
    return level;
}

int Animal::getID() {
    return ID;
}


// TODO: maybe change to regular changeLevel and throw error on delta<=0 only from zoologist
void Animal::increaseLevel(int delta) {
    if (delta <= 0) throw badAnimalInput;
    level += delta;
    return;
}

void Animal::setID(int newID) {
    if (newID <= 0) throw badAnimalInput;
    ID = newID;
}