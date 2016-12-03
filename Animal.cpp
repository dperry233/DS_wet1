#include "Animal.h"

/*
 * Class constructor
 */

Animal::Animal (int id, int level) : Level(level), ID(id) {
    if (level < 0 || id <= 0) throw badInput();
}

// copy c'tor
Animal::Animal (const Animal &original) : Level(original.Level), ID(original.ID) {}

// Animal::~Animal () {};

/*
 * Getters
 */

int Animal::getLevel () const {
    return Level;
}

int Animal::getID () const {
    return ID;
}

/*
 * Setters
 */

// TODO: maybe change to regular changeLevel and throw error on delta<=0 only from zoologist
void Animal::increaseLevel (int delta) {
    if (delta <= 0) throw badInput();
    Level += delta;
    return;
}

void Animal::setID (int newID) {
    if (newID <= 0) throw badInput();
    ID = newID;
}

/*
 * Operators
 */

bool Animal::operator== (const Animal & rhs) {
    return ID == rhs.ID;
}

// this is smaller if it has lower level, or if equal levels and higher ID
bool operator< (const Animal& lhs, const Animal &rhs) {
    return lhs.getLevel() < rhs.getLevel() || (lhs.getLevel() == rhs.getLevel() && lhs.getID() > rhs.getID());
}

bool Animal::operator> (const Animal &rhs) {
    return !(*this < rhs);
}