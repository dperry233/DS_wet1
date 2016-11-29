#include "Animal.h"

/*
 * Class constructor
 */

explicit Animal::Animal (int id, int level = 0) : Level(level), ID(id) {
    if (level < 0 || id <= 0) throw badAnimalInput;
}

// copy c'tor
Animal::Animal (const Animal &original) : Level(original.Level), ID(original.ID) {}

Animal::~Animal () {};

/*
 * Getters
 */

int Animal::getLevel () const {
    return level;
}

int Animal::getID () const {
    return ID;
}

/*
 * Setters
 */

// TODO: maybe change to regular changeLevel and throw error on delta<=0 only from zoologist
void Animal::increaseLevel (int delta) {
    if (delta <= 0) throw badAnimalInput;
    level += delta;
    return;
}

void Animal::setID (int newID) {
    if (newID <= 0) throw badAnimalInput;
    ID = newID;
}

/*
 * Operators
 */

bool Animal::operator== (const Animal &rhs) {
    return this.ID == rhs.ID;
}

// this is smaller if it has lower level, or if equal levels, HIGHER ID
bool Animal::operator< (const Animal &rhs) {
    if (this->Level < rhs.Level) return true;
    else return this->ID > rhs.ID;
}

bool Animal::operator> (const Animal &rhs) {
    return !(*this < rhs);
}