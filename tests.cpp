////
//// Created by Krumpet on 03-Dec-16.
////
//
//#include "tests.h"
//#include "library1.h"
//
//using namespace std;
//std::string location;
//
//bool animalTest () {
//    ASSERT_THROW(badInput, Animal(-1)); // id only
//    ASSERT_THROW(badInput, Animal(0));
//    ASSERT_THROW(badInput, Animal(0, -1)); // id and level
//    ASSERT_THROW(badInput, Animal(0, 0));
//    ASSERT_THROW(badInput, Animal(1, -1));
//    ASSERT_THROW(badInput, Animal(-1, 3));
//
//    ASSERT_NO_THROW(Animal(1, 1));
//    ASSERT_NO_THROW(Animal(1, 0));
//
//    Animal big = Animal(1, 5);
//    Animal small(4, 1);
//    Animal medium(3, 1);
//
//    ASSERT_EQUALS(true, big > small);
//    ASSERT_EQUALS(true, small < big);
//    ASSERT_EQUALS(true, big > medium);
//    ASSERT_EQUALS(false, big < medium);
//    ASSERT_EQUALS(true, medium > small);
//    ASSERT_EQUALS(false, medium < small);
//    ASSERT_EQUALS(true, small < medium);
//    ASSERT_EQUALS(false, small < small);
//    ASSERT_EQUALS(false, medium < medium);
//
//    ASSERT_EQUALS(5, big.getLevel());
//    ASSERT_NOT_EQUALS(4, small.getLevel());
//    ASSERT_EQUALS(4, small.getID());
//
//    ASSERT_THROW(badInput, small.increaseLevel(0));
//    ASSERT_THROW(badInput, medium.increaseLevel(-1));
//    ASSERT_NO_THROW(big.increaseLevel(1));
//    ASSERT_EQUALS(6, big.getLevel());
//
//    ASSERT_NO_THROW((big.setID(6)));
//    ASSERT_EQUALS(6, big.getID());
//    ASSERT_NOT_EQUALS(5, big.getID());
//
//    ASSERT_THROW(badInput, big.setID(-1));
//    ASSERT_NOT_EQUALS(-1, big.getID());
//    ASSERT_EQUALS(6, big.getID());
//
//    ASSERT_NO_THROW((small.setID(6)));
//    ASSERT_EQUALS(true, small == big); // equal IDs
//    ASSERT_NO_THROW((small.setID(3)));
//    ASSERT_EQUALS(true, small == medium); // equal IDs
//    ASSERT_EQUALS(false, small == big);
//
//    Animal copy(small); // copy c'tor
//    ASSERT_EQUALS(small, copy);
//    ASSERT_NO_THROW((copy.setID(1)));
//    ASSERT_NOT_EQUALS(copy, small);
//
//    return true;
//}
//
//bool beastTest () {
//    ASSERT_THROW(badInput, SuperBeast(-1));
//    ASSERT_THROW(badInput, SuperBeast(0));
//    ASSERT_THROW(badInput, SuperBeast(0, -1)); // id and level
//    ASSERT_THROW(badInput, SuperBeast(0, 0));
//    ASSERT_THROW(badInput, SuperBeast(1, -1));
//    ASSERT_THROW(badInput, SuperBeast(-1, 3));
//
//    SuperBeast super(1, 2);
//    SuperBeast danger(2, 10);
//    Animal regular(1);
//
//    ASSERT_EQUALS(super, regular);
//    ASSERT_NOT_EQUALS(super, danger);
//    ASSERT_NOT_EQUALS(regular, danger);
//
//    // copy c'tor and conversion from base class
//    SuperBeast copySuper(super);
//    SuperBeast copyRegular(regular);
//
//    ASSERT_EQUALS(1, copySuper.getID());
//    ASSERT_EQUALS(0, copyRegular.getLevel());
//    ASSERT_EQUALS(super, copySuper);
//
//    // Zoologist tests
//    ASSERT_THROW(badInput, Zoologist(-1));
//    ASSERT_THROW(badInput, Zoologist(0));
//    ASSERT_NO_THROW(Zoologist(1));
//
//    Zoologist Fred(1);
//
//    ASSERT_NO_THROW(super.setOwner(&Fred));
//    ASSERT_EQUALS(&Fred, super.getOwner());
//
//    ASSERT_NO_THROW(super.setBeast1(&danger));
//    ASSERT_EQUALS(&danger, super.getBeast1());
//    ASSERT_NO_THROW(super.getBeast1()->setBeast2(&super)); // set danger's beast2 to super
//    ASSERT_EQUALS(&super, danger.getBeast2());
//
//    // getters setters for zoologist
//    ASSERT_EQUALS(Fred.getMagiID(), 1);
//    ASSERT_NO_THROW(Fred.setMagiID(3));
//    ASSERT_EQUALS(3, Fred.getMagiID());
//    ASSERT_THROW(badInput, Fred.setMagiID(0));
//    ASSERT_THROW(badInput, Fred.setMagiID(-1));
//    ASSERT_THROW(badInput, Fred.setMostDangerousID(-1));
//    ASSERT_NO_THROW(Fred.setMostDangerousID(danger.getID()));
//    ASSERT_EQUALS(2, Fred.getMostDangerousID());
//
//    AVLTree<Animal, SuperBeast> testree;
//
//    // get set tree
//    ASSERT_NO_THROW(Fred.setTree(testree));
//    ASSERT_EQUALS(Fred.getTree(), testree);
//
//    return true;
//}
//
//bool managerTest () {
//
//    MagicManager db;
//    ASSERT_EQUALS(db.AddMagiMM(-1), MM_INVALID_INPUT);
//    ASSERT_EQUALS(db.AddMagiMM(0), MM_INVALID_INPUT);
//
//    // Add zoologist
//    ASSERT_EQUALS(db.AddMagiMM(1), MM_SUCCESS);
//    ASSERT_EQUALS(db.AddMagiMM(1), MM_FAILURE); // already exists
//    // add beast to zoologist
//    ASSERT_EQUALS(db.AddCreatureMM(-1, 1, 1), MM_INVALID_INPUT);
//    ASSERT_EQUALS(db.AddCreatureMM(0, 1, 1), MM_INVALID_INPUT);
//    ASSERT_EQUALS(db.AddCreatureMM(1, -1, 1), MM_INVALID_INPUT);
//    ASSERT_EQUALS(db.AddCreatureMM(1, 0, 1), MM_INVALID_INPUT);
//    ASSERT_EQUALS(db.AddCreatureMM(1, 1, -1), MM_INVALID_INPUT);
//
//    ASSERT_EQUALS(db.AddCreatureMM(1, 2, 1), MM_FAILURE);
//
//    ASSERT_EQUALS(db.AddCreatureMM(1, 1, 1), MM_SUCCESS);
//    // now 1->[(1,1)]
//
//    ASSERT_EQUALS(db.AddCreatureMM(1, 1, 2), MM_FAILURE); // beast already exists
//
//    int danger = 0; // will hold danger of animal we added
//    ASSERT_EQUALS(db.GetmostDangerousMM(1, &danger), MM_SUCCESS);
//    ASSERT_EQUALS(1, danger);
//
//    ASSERT_EQUALS(db.AddCreatureMM(2, 1, 5), MM_SUCCESS);
//    // now 1->[(1,1),(2,5)]
//
//    ASSERT_EQUALS(db.GetmostDangerousMM(1, &danger), MM_SUCCESS);
//    ASSERT_EQUALS(2, danger);
//
//    ASSERT_EQUALS(MM_INVALID_INPUT, db.releaseCreatureMM(-1));
//    ASSERT_EQUALS(MM_INVALID_INPUT, db.releaseCreatureMM(0));
//
//    ASSERT_EQUALS(MM_FAILURE, db.releaseCreatureMM(7));
//
//    ASSERT_EQUALS(MM_SUCCESS, db.releaseCreatureMM(2)); // release most dangerous
//    //ASSERT_EQUALS(MM_SUCCESS, db.releaseCreatureMM(1)); // last one - this is a problem
//    //cout << "now we don't reach here" << endl;
//
//    // check most dangerous is correct:
//    ASSERT_EQUALS(db.GetmostDangerousMM(1, &danger), MM_SUCCESS);
//    ASSERT_EQUALS(1, danger);
//
//    // Add new dangerous creature, remove weaker, check it doesn't matter
//    ASSERT_EQUALS(db.AddCreatureMM(4, 1, 5), MM_SUCCESS);
//    ASSERT_EQUALS(db.GetmostDangerousMM(1, &danger), MM_SUCCESS);
//    ASSERT_EQUALS(4, danger);
//    ASSERT_EQUALS(MM_SUCCESS, db.releaseCreatureMM(1));
//    ASSERT_EQUALS(db.GetmostDangerousMM(1, &danger), MM_SUCCESS);
//    ASSERT_EQUALS(4, danger);
//
//    ASSERT_EQUALS(db.AddMagiMM(2), MM_SUCCESS);
//    // now we have two zoologists, 1 and 2
//
//    ASSERT_EQUALS(db.AddCreatureMM(4, 2, 3), MM_FAILURE); // unique IDs across magi
//
//    ASSERT_EQUALS(db.AddCreatureMM(5, 2, 7), MM_SUCCESS);
//    // Now 1->[(4,5)] and 2->[(5,7)] (MagiID->[tree of (id,level)])
//
//
//    danger = 0;
//
//    // this should get global maximum
//    ASSERT_EQUALS(db.GetmostDangerousMM(-1, &danger), MM_SUCCESS);
//
//    // max from zoologist 2
//    int danger2 = 0;
//    ASSERT_EQUALS(db.GetmostDangerousMM(2, &danger2), MM_SUCCESS);
//
//    // global should be equal to max from zoologist 2
//    ASSERT_EQUALS(danger2, danger);
//
//    MMStatusType status = db.releaseCreatureMM(5);
//    ASSERT_EQUALS(status, MM_SUCCESS);
//    ASSERT_EQUALS(db.releaseCreatureMM(5), MM_FAILURE);
//    ASSERT_EQUALS(db.GetmostDangerousMM(-1, &danger), MM_SUCCESS);
//    // Now just 1->[(4,5)] 2->NULL
//    ASSERT_EQUALS(danger, 4);
//
//    ASSERT_EQUALS(db.increaseLevelMM(9, 2), MM_FAILURE);
//
//    ASSERT_EQUALS(db.increaseLevelMM(4, 0), MM_INVALID_INPUT);
//    ASSERT_EQUALS(db.increaseLevelMM(4, -1), MM_INVALID_INPUT);
//
//    ASSERT_EQUALS(db.increaseLevelMM(4, 1), MM_SUCCESS); // now is 4,6
//
//    danger = 0;
//    danger2 = 0;
//    ASSERT_EQUALS(db.GetmostDangerousMM(-1, &danger), MM_SUCCESS);
//    ASSERT_EQUALS(db.GetmostDangerousMM(1, &danger2), MM_SUCCESS);
//    ASSERT_EQUALS(danger, 4);
//    ASSERT_EQUALS(danger2, 4);
//    ASSERT_EQUALS(db.getIdTree()->findMax()->getLevel(), 6);
//
//    ASSERT_EQUALS(MM_SUCCESS, db.releaseCreatureMM(4));
//    ASSERT_EQUALS(db.GetmostDangerousMM(-1, &danger), MM_SUCCESS);
//    ASSERT_EQUALS(-1,danger);
//    ASSERT_EQUALS(db.GetmostDangerousMM(1, &danger2), MM_SUCCESS);
//    ASSERT_EQUALS(-1,danger2);
//
//    return true;
//}
//
//int main () {
//    RUN_TEST(animalTest);
//    RUN_TEST(beastTest);
//    RUN_TEST(managerTest);
//    return 0;
//}
