#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
private:
    int Level; // Danger level
    int ID;
// comment to see if this works

public:
    Animal(int level, int id);
};

/*
 * Exceptions
 */

class badAnimalInput : public std::exception {
};

class Failure : public std::exception {
};

class Memory : public std::exception {
};

#endif