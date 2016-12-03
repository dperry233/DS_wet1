//
// Created by Krumpet on 29-Nov-16.
//

#include "Zoologist.h"

SuperBeast::SuperBeast (int id, int level, SuperBeast * first, SuperBeast * second,
                        Zoologist * Owner) : Animal(id, level), beast1(first), beast2(second),
                                             Owner(Owner) {}

// SuperBeast::~SuperBeast () {};

SuperBeast::SuperBeast (const SuperBeast & original) : Animal(original), beast1(original.beast1),
                                                       beast2(original.beast2),
                                                       Owner(original.Owner) {}

SuperBeast::SuperBeast (const Animal & animal, Zoologist * owner, SuperBeast * first,
                        SuperBeast * second) : Animal(animal), beast1(first), beast2(second),
                                                         Owner(owner) {}

SuperBeast * SuperBeast::getBeast1 () const {
    return beast1;
}

void SuperBeast::setBeast1 (SuperBeast * beast) {
    beast1 = beast;
}

SuperBeast * SuperBeast::getBeast2 () const {
    return beast2;
}

void SuperBeast::setBeast2 (SuperBeast * beast) {
    beast2 = beast;
}

Zoologist * SuperBeast::getOwner () const {
    return Owner;
}

void SuperBeast::setOwner (Zoologist * owner) {
    Owner = owner;
}

Zoologist::Zoologist (const Zoologist & original) {
    mostDangerousID = original.mostDangerousID;
    tree = original.tree;
    MagiID = original.MagiID;
}

Zoologist::Zoologist (int MagiID) : MagiID(MagiID), mostDangerousID(0), tree() {
    if (MagiID <= 0) throw badInput();
}

int Zoologist::getMostDangerousID () const {
    return mostDangerousID;
}

void Zoologist::setMostDangerousID (int mostDangerousID) {
    if (mostDangerousID<=0) throw badInput();
    Zoologist::mostDangerousID = mostDangerousID;
}

int Zoologist::getMagiID () const {
    return MagiID;
}

void Zoologist::setMagiID (int MagiID) {
    if (MagiID<=0) throw badInput();
    Zoologist::MagiID = MagiID;
}

const AVLTree<Animal, SuperBeast> & Zoologist::getTree () const {
    return tree;
}

AVLTree<Animal, SuperBeast> & Zoologist::getTree () {
    return tree;
}

void Zoologist::setTree (const AVLTree<Animal, SuperBeast> & tree) {
    Zoologist::tree = tree;
}

/*void Zoologist::getMostDangerous (int * dangerousID) {
    if (!dangerousID) throw badInput();
    *dangerousID = getMostDangerousID();
}*/

/*ZooResult Zoologist::addCreature (int id, int level) {
    Animal key;
    try { Animal key = Animal(id, level); }
    catch (const badInput &) {
        return ZOO_INVALID_INPUT;
    }
    try { SuperBeast data (key,this) }
    TreeResult res = tree.insertData(key,);

}*/