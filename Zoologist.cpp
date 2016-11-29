//
// Created by Krumpet on 29-Nov-16.
//

#include "Zoologist.h"
#include "Animal.h"
#include "avlTree.h"

explicit SuperBeast::SuperBeast (int id, int level = 0, SuperBeast *first = nullptr, SuperBeast *second = nullptr,
                                 Zoologist *Owner = nullptr) : Animal(id, level), beast1(first), beast2(second),
                                                               Owner(Owner) {}

~SuperBeast () {};

SuperBeast (const SuperBeast &original) : Animal(original), beast1(original.beast1), beast2(original.beast2),
                                          Owner(original.owner) {}

explicit SuperBeast (const Animal &animal, SuperBeast *first = nullptr, SuperBeast *second = nullptr,
                     Zoologist *owner = nullptr) : Animal(original), beast1(first), beast2(second), Owner(owner) {}