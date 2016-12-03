//
// Created by Krumpet on 03-Dec-16.
//

#include "tests.h"
//#include "magicManager.h"
#include "Animal.h"

using namespace std;
std::string location;

bool animalTest() {
    ASSERT_THROW(badInput, Animal(-1)); // id only
    ASSERT_THROW(badInput, Animal(0));
    ASSERT_THROW(badInput, Animal(0, -1)); // id and level
    ASSERT_THROW(badInput, Animal(0, 0));
    ASSERT_THROW(badInput, Animal(1, -1));
    ASSERT_THROW(badInput, Animal(-1, 3));

    ASSERT_NO_THROW(Animal(1, 1));
    ASSERT_NO_THROW(Animal(1, 0));

    Animal big = Animal(1, 5);
    Animal small(4, 1);
    Animal medium(3, 1);

    ASSERT_EQUALS(true, big > small);
    ASSERT_EQUALS(true, small < big);
    ASSERT_EQUALS(true, big > medium);
    ASSERT_EQUALS(false, big < medium);
    ASSERT_EQUALS(true, medium > small);
    ASSERT_EQUALS(false, medium < small);
    ASSERT_EQUALS(true, small < medium);
    ASSERT_EQUALS(false, small < small);
    ASSERT_EQUALS(false, medium < medium);

    ASSERT_EQUALS(5,big.getLevel());
    ASSERT_NOT_EQUALS(4,small.getLevel());
    ASSERT_EQUALS(4,small.getID());

    ASSERT_THROW(badInput,small.increaseLevel(0));
    ASSERT_THROW(badInput,medium.increaseLevel(-1));
    ASSERT_NO_THROW(big.increaseLevel(1));
    ASSERT_EQUALS(6,big.getLevel());

    ASSERT_NO_THROW((big.setID(6)));
    ASSERT_EQUALS(6,big.getID());
    ASSERT_NOT_EQUALS(5,big.getID());

    ASSERT_THROW(badInput,big.setID(-1));
    ASSERT_NOT_EQUALS(-1,big.getID());
    ASSERT_EQUALS(6,big.getID());

    return true;
}

int main () {
    RUN_TEST(animalTest);
    return 0;
}