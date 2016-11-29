//
// Created by Krumpet on 29-Nov-16.
//

#ifndef DS_WET1_ZOOLOGIST_H
#define DS_WET1_ZOOLOGIST_H

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
};

#endif //DS_WET1_ZOOLOGIST_H
