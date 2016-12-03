/*
 * magicManager.h
 *
 *  Created on: Nov 29, 2016
 *      Author: user
 */

#ifndef MAGICMANAGER_H_
#define MAGICMANAGER_H_

#include <stdlib.h>
#include "AVLTree.h"
#include "Zoologist.h"
#include "Animal.h"

//temp stubs

class Magi{



};

class LevelWrapper{

};

// end of temp stubs

typedef enum {
	MM_SUCCESS = 0,
	MM_FAILURE = -1,
	MM_ALLOCATION_ERROR = -2,
	MM_INVALID_INPUT = -3
} MMStatusType;

class MagicManager{
	AVLTree<int,SuperBeast>* IdTree;
	AVLTree<Animal,SuperBeast>* levelTree;
	AVLTree<int,Zoologist>* magiTree;
	Animal* mostDangerous;



public:
	MagicManager(){
		IdTree= new AVLTree<int,SuperBeast>;
		levelTree =new AVLTree<Animal,SuperBeast> ;
		magiTree = new AVLTree<int,Zoologist> ;
		mostDangerous=NULL;
	}
	~MagicManager(){
		delete IdTree;
		delete levelTree;
		delete magiTree;


	}
	MMStatusType AddMagiMM(int MagiID);
	MMStatusType AddCreatureMM( int creatureID, int magiID, int level);
	MMStatusType releaseCreatureMM( int creatureID);

	MMStatusType ReplaceMagi(int MagiID,int replacement);

	MMStatusType increaseLevelMM( int creatureID, int levelIncrease);
	MMStatusType GetmostDangerousMM( int MagiID, int *creatureID);
	MMStatusType GetAllCreaturesByLevelMM ( int MagiID,
			int **Creatures, int* numOfCreatures);



private:


	template<class T>
	void reverseArray(T* array,int length){
		T* newArray =(T*)malloc(sizeof(T)*length);
		for(int i=0;i<length;i++){
			newArray[length-i-1]=array[i];

		}
		for(int i=0;i<length;i++){
			array[i]=newArray[i];
		}
		free(newArray);
	}




	MMStatusType getCreaturesByLevel(int** creatures,int* numberOfCreatures){
		int* arr =(int*)malloc(sizeof(int)*this->IdTree->size);
		SuperBeast* arr2 =(SuperBeast*)malloc(sizeof(SuperBeast)*this->IdTree->size);

		int i=0;
		inOrderToArray(this->levelTree->rootNode,arr2,&i);
		for(int j=0;j<IdTree->size;j++){
			arr[j]= arr2[j].getID();
		}
		reverseArray(arr,i);
		free( arr2);
		*creatures=arr;
		*numberOfCreatures=i;
		return MM_SUCCESS;
	}





};



MMStatusType MagicManager::AddMagiMM(int MagiID){
	if(MagiID<=0){
		return MM_INVALID_INPUT;
	}

	 if(magiTree->findIfValueExists(MagiID)){
		 return MM_FAILURE;
	 }
	 Zoologist tmpMagi(MagiID);
	 if(AVLTREE_ALLOCATION_ERROR==magiTree->insertData(MagiID,tmpMagi)){
		 return MM_ALLOCATION_ERROR;
	 }
	 return MM_SUCCESS;
}






MMStatusType MagicManager::AddCreatureMM(int creatureID, int MagiID, int level){
	if(creatureID<=0||MagiID<=0||level<0){
		return MM_INVALID_INPUT;
	}

	if(!magiTree->findIfValueExists(MagiID)){
			 return MM_FAILURE;
		 }
	if(IdTree->findIfValueExists(creatureID)){
		return MM_FAILURE;

	}

	SuperBeast tmpSuperBeast(creatureID,level);


	TreeResult allFlag=this->IdTree->insertData(creatureID,tmpSuperBeast);
	if(allFlag==AVLTREE_ALLOCATION_ERROR){
		return MM_FAILURE;
	}
	allFlag=this->levelTree->insertData(tmpSuperBeast,tmpSuperBeast);
	if(allFlag==AVLTREE_ALLOCATION_ERROR){
		this->IdTree->removeValue(creatureID);
		return MM_ALLOCATION_ERROR;
	}


	TreeResult magiFlag=this->magiTree->getValue(MagiID)->tree.insertData(tmpSuperBeast,tmpSuperBeast);
	if(magiFlag==AVLTREE_ALLOCATION_ERROR){
		this->IdTree->removeValue(creatureID);
		this->levelTree->removeValue(tmpSuperBeast);
		return MM_ALLOCATION_ERROR;
	}
	if(allFlag==AVLTREE_NODE_ALREADY_EXISTS||magiFlag==AVLTREE_NODE_ALREADY_EXISTS){
		return MM_FAILURE;//should not get here as there is a check for it above
	}

	//set pointers here

	SuperBeast* idTreePtr=&(this->IdTree->getValue(creatureID));
	SuperBeast* levelTreePtr=&(levelTree->getValue(tmpSuperBeast)) ;
	Zoologist* ownerPtr=&(magiTree->getNodeByKey(MagiID)->value) ;

	//idTree pointers setting
	this->IdTree->getValue(creatureID)->setOwner(ownerPtr);
	this->IdTree->getValue(creatureID)->setBeast1(idTreePtr);
	this->IdTree->getValue(creatureID)->setBeast2(levelTreePtr);

	//levelTree pointers setting

	this->levelTree->getValue(tmpSuperBeast)->setOwner(ownerPtr);
	this->levelTree->getValue(tmpSuperBeast)->setBeast1(idTreePtr);
	this->levelTree->getValue(tmpSuperBeast)->setBeast2(levelTreePtr);

//in  magi tree ptr setting

	this->magiTree->getValue(MagiID)->getTree().getValue(tmpSuperBeast)->setOwner(ownerPtr);
	this->magiTree->getValue(MagiID)->getTree().getValue(tmpSuperBeast)->setBeast1(idTreePtr);
	this->magiTree->getValue(MagiID)->getTree().getValue(tmpSuperBeast)->setBeast2(levelTreePtr);

	mostDangerous= this->levelTree->findMax();


	//also set most dangerous for owner !!!!!!!!!!!!!!!!!!
	//would probably be best if zoologist took care of itself
	int tmpDangerous =this->magiTree->getValue(MagiID)->getTree().findMax()->getID();
	this->magiTree->getValue(MagiID)->setMostDangerousID(tmpDangerous);


	return MM_SUCCESS;
}

MMStatusType MagicManager::releaseCreatureMM( int creatureID){
	if(creatureID<=0){
		return MM_INVALID_INPUT;
	}
	if(!this->IdTree->findIfValueExists(creatureID)){
		return MM_FAILURE;
	}

	SuperBeast tmpCreature =this->IdTree->getValue(creatureID);
	tmpCreature.getOwner()->getTree().removeValue(tmpCreature);//should be replaced with addcreature
	//make sure to check mostDangerous change
	tmpCreature.getOwner()->setMostDangerousID(tmpCreature.getOwner()->getTree().findMax()->getID());



	//add checks for removal success
	this->levelTree->removeValue(tmpCreature);
	this->IdTree->removeValue(creatureID);
	mostDangerous=this->levelTree->findMax();


	return MM_SUCCESS;
}




MMStatusType MagicManager::ReplaceMagi(int magiID , int replacement){


}





MMStatusType MagicManager::increaseLevelMM( int creatureID, int levelIncrease){
	if(creatureID<=0||levelIncrease<=0){
		return MM_INVALID_INPUT;
	}
	if(!this->IdTree->findIfValueExists(creatureID)){
		return MM_FAILURE;
	}
	SuperBeast tmpBeast(*this->IdTree->getValue(creatureID));





	return MM_SUCCESS;
}

MMStatusType MagicManager::GetmostDangerousMM( int MagiID, int *creatureID){
	if(creatureID==NULL||MagiID==0){
		return MM_INVALID_INPUT;
	}

	if(MagiID<0){

		if(this->IdTree->size==0){
			*creatureID=-1;
			return MM_SUCCESS;
		}

		*creatureID= this->mostDangerous->getID();
		return MM_SUCCESS;
	}




	if(!this->magiTree->findIfValueExists(MagiID)){
		return MM_FAILURE;
	}
	if(magiTree->getValue(MagiID)->getTree().size==0){
		*creatureID=-1;
		return MM_SUCCESS;
	}
	*creatureID=magiTree->getValue(MagiID)->getMostDangerousID();

	return MM_SUCCESS;
}

MMStatusType MagicManager::GetAllCreaturesByLevelMM ( int MagiID,
		int **Creatures, int* numOfCreatures){
	if(numOfCreatures==NULL||Creatures==NULL||MagiID==0){
		return MM_INVALID_INPUT;
	}


	if(MagiID<0){
		if(this->IdTree->size==0){
			*numOfCreatures=0;
			*Creatures=NULL;
			return MM_SUCCESS;
		}


		MMStatusType flag=getCreaturesByLevel(Creatures,numOfCreatures);
		if(flag==MM_SUCCESS){
			return MM_SUCCESS;
		}
		return MM_FAILURE;
	}


	if(!this->magiTree->findIfValueExists(MagiID)){
		return MM_FAILURE;
	}
	if(this->magiTree->getValue(MagiID)->getTree().size==0){
		*numOfCreatures=0;
		*Creatures=NULL;
		return MM_SUCCESS;
	}
	MMStatusType magiFlag=this->magiTree->getValue(MagiID);//->getCreaturesByLevel;
	{
		return MM_SUCCESS;
	}

	return MM_FAILURE;
}










#endif /* MAGICMANAGER_H_ */