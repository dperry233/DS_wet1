#ifndef ANIMAL_H
#define ANIMAL_H

#include <exception>

class Animal {
protected:
    int Level; // Danger level
    int ID;

public:
    // throw badInput if ID<=0
    explicit Animal (int id, int level = 0); // default c'tor
    Animal (const Animal & original); // copy c'tor

    virtual ~Animal ();

    int getLevel () const;

    int getID () const;

    // Throws badAnimalInput if delta <= 0
    void increaseLevel (int delta);

    void setID (int newID);

    bool operator== (const Animal & rhs);

    bool operator> (const Animal & rhs);
};

// this is smaller if it has lower level, or if equal levels, HIGHER ID
// non-member
bool operator< (const Animal & lhs, const Animal & rhs);

/*
 * Exceptions
 */

class badInput : public std::exception {
};

#endif