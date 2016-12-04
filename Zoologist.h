//
// Created by Krumpet on 29-Nov-16.
//

#ifndef DS_WET1_ZOOLOGIST_H
#define DS_WET1_ZOOLOGIST_H

#include "Animal.h"
#include "avlTree.h"

typedef enum {
    ZOO_INVALID_INPUT,
    ZOO_SUCCESS, ZOO_ALLOCATION_ERROR, ZOO_NODE_ALREADY_EXISTS, ZOO_NODE_NOT_FOUND
} ZooResult;

class Zoologist; // forward-declaration to let SuperBeast know that zoologist exists

class SuperBeast : public Animal {
protected:


    SuperBeast * beast1;
    SuperBeast * beast2;
    Zoologist * Owner;

public:
    explicit SuperBeast (int id, int level = 0, SuperBeast * first = NULL, SuperBeast * second = NULL,
                         Zoologist * Owner = NULL);

    ~SuperBeast ();

    SuperBeast (const SuperBeast & original);

    // explicit conversion c'tor from base class
    explicit SuperBeast (const Animal & animal, Zoologist * owner = NULL, SuperBeast * first = NULL,
                         SuperBeast * second = NULL);

    SuperBeast * getBeast1 () const;

    void setBeast1 (SuperBeast * beast);

    SuperBeast * getBeast2 () const;

    void setBeast2 (SuperBeast * beast);

    Zoologist * getOwner () const;

    void setOwner (Zoologist * owner);


};

class Zoologist {
private:
    AVLTree<Animal, SuperBeast> tree;
    int mostDangerousID;
    int MagiID;

public:

    // throws badInput if MagiID <= 0
    Zoologist (int MagiID);

    // copy c'tor
    Zoologist (const Zoologist & original);

    int getMostDangerousID () const;

    // throws badInput if dangerousID is NULL
    void getMostDangerous (int * dangerousID);

    void setMostDangerousID (int mostDangerousID);

    int getMagiID () const;

    void setMagiID (int MagiID);

    const AVLTree<Animal, SuperBeast> & getTree () const;

    AVLTree<Animal, SuperBeast> & getTree ();

    void setTree (const AVLTree<Animal, SuperBeast> & tree);

};


#endif //DS_WET1_ZOOLOGIST_H
