#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
private:
    int Level; // Danger level
    int ID;
// comment to see if this works

public:
    Animal(int level, int id); // default c'tor
    explicit Animal::Animal(int id); // default c'tor with default Level
    Animal::Animal(const Animal &original); // copy c'tor
    ~Animal();
    int getLevel();
    int getID();

    // Throws badAnimalInput if delta <= 0
    void increaseLevel(int delta);

    void setID(int newID);
};

/*
 * Exceptions
 */

class badAnimalInput : public std::exception {
};

/*class Failure : public std::exception {
};

class Memory : public std::exception {
};
*/
#endif