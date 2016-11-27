//
// Created by Krumpet on 27-Nov-16.
//

#include "Animal.h"

/*
 * Class constructor
 */

Animal::Animal(int level, int id)  : Level(level), ID(id) {
    if (level<0 || id<=0) throw badAnimalInput;
}

