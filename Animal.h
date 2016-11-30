#ifndef ANIMAL_H
#define ANIMAL_H

#include <exception>

class Animal {
protected:
    int Level; // Danger level
    int ID;

public:
    explicit Animal (int id, int level = 0); // default c'tor
    Animal::Animal (const Animal & original); // copy c'tor

    virtual ~Animal ();

    int getLevel () const;

    int getID () const;

    // Throws badAnimalInput if delta <= 0
    void increaseLevel (int delta);

    void setID (int newID);

    Animal & Animal::operator= (const Animal & rhs) = default;

    bool Animal::operator== (const Animal & rhs);

// this is smaller if it has lower level, or if equal levels, HIGHER ID
    bool operator< (const Animal & lhs, const Animal & rhs);

    bool Animal::operator> (const Animal & rhs);
};

/*
 * Exceptions
 */

class badInput : public std::exception {
};

/*class Failure : public std::exception {
};

class Memory : public std::exception {
};
*/
#endif