//
// Created by Krumpet on 29-Nov-16.
//

#ifndef DS_WET1_ZOOLOGIST_H
#define DS_WET1_ZOOLOGIST_H

#include "Animal.h"
#include "avlTree.h"

class SuperBeast : public Animal {
protected:
    SuperBeast *beast1;
    SuperBeast *beast2;
    Zoologist *Owner;

public:
    explicit SuperBeast (int id, int level = 0, SuperBeast *first = nullptr, SuperBeast *second = nullptr,
                         Zoologist *Owner = nullptr);

    ~SuperBeast ();

    SuperBeast (const SuperBeast &original);

    // explicit conversion c'tor from base class
    explicit SuperBeast (const Animal& animal, SuperBeast * first=nullptr, SuperBeast * second= nullptr, Zoologist * owner=nullptr);

    SuperBeast *getBeast1 () const;

    void setBeast1 (SuperBeast *beast);

    SuperBeast *getBeast2 () const;

    void setBeast2 (SuperBeast *beast);

    Zoologist *getOwner () const;

    void setOwner (Zoologist *owner);


};

class Zoologist {
private:
    AVLTree<Animal,SuperBeast> tree;
    int mostDangerous;
    int MagiID;
};



#endif //DS_WET1_ZOOLOGIST_H
