//
// Created by Krumpet on 29-Nov-16.
//

#include "Zoologist.h"
#include "Animal.h"
#include "avlTree.h"

explicit SuperBeast::SuperBeast (int id, int level = 0, SuperBeast *first = nullptr, SuperBeast *second = nullptr,
                        Zoologist *Owner = nullptr) : Animal(id, level), beast1(first), beast2(second), Owner(Owner) {}
