/*
 * library1.cpp
 *
 *  Created on: Apr 28, 2016
 *      Author: user
 */

#include "library1.h"
#include "magicManager.h"

void* Init(){
	MagicManager* tm;
	try
	{
		tm = new MagicManager();
	}
	catch (std::exception& e)
	{
		return NULL;
	}
	return tm;
}

void flagConverter(MMStatusType MMflag,StatusType* libFlag){
	if(MMflag==MM_SUCCESS){
		*libFlag=SUCCESS;
		return;
	}
	if(MMflag==MM_FAILURE){
		*libFlag=FAILURE;
		return;
	}
	if(MMflag==MM_INVALID_INPUT){
		*libFlag=INVALID_INPUT;
		return;
	}
	if(MMflag==MM_ALLOCATION_ERROR){
		*libFlag=ALLOCATION_ERROR;
		return;
	}
	return;
}



StatusType AddMagizoologist(void *DS, int magiID){
	if(!DS){
		return INVALID_INPUT;
	}
	MMStatusType MMflag=((MagicManager*)DS)->AddMagiMM(magiID);
	StatusType libFlag=SUCCESS;
	flagConverter(MMflag,&libFlag);


	return libFlag;
}


StatusType AddCreature(void *DS, int creatureID, int magiID, int level){
	if(!DS){
		return INVALID_INPUT;
	}
	MMStatusType MMflag=((MagicManager*)DS)->AddCreatureMM(creatureID,magiID,level);
	StatusType libFlag=SUCCESS;
	flagConverter(MMflag,&libFlag);


	return libFlag;
}


StatusType ReleaseCreature(void *DS, int creatureID){
	if(!DS){
		return INVALID_INPUT;
	}
	MMStatusType MMflag=((MagicManager*)DS)->releaseCreatureMM(creatureID);
	StatusType libFlag=SUCCESS;
	flagConverter(MMflag,&libFlag);


	return libFlag;
}


StatusType IncreaseLevel(void *DS, int creatureID, int levelIncrease){
	if(!DS){
		return INVALID_INPUT;
	}
	MMStatusType MMflag=((MagicManager*)DS)->increaseLevelMM(creatureID,levelIncrease);
	StatusType libFlag=SUCCESS;
	flagConverter(MMflag,&libFlag);


	return libFlag;
}


StatusType GetMostDangerous(void *DS, int magiID, int *creatureID){
	if(!DS){
		return INVALID_INPUT;
	}
	MMStatusType MMflag=((MagicManager*)DS)->GetmostDangerousMM(magiID,creatureID);
	StatusType libFlag=SUCCESS;
	flagConverter(MMflag,&libFlag);


	return libFlag;
}


StatusType GetAllCreaturesByLevel(void *DS, int magiID, int **creatures, int *numOfCreatures){
	if(!DS){
		return INVALID_INPUT;
	}
	MMStatusType MMflag=((MagicManager*)DS)->GetAllCreaturesByLevelMM(magiID,creatures,numOfCreatures);
	StatusType libFlag=SUCCESS;
	flagConverter(MMflag,&libFlag);


	return libFlag;
}


StatusType ReplaceMagizoologist(void *DS, int MagiID, int ReplacementID){
	if(!DS){
		return INVALID_INPUT;
	}
	MMStatusType MMflag=((MagicManager*)DS)->ReplaceMagi(MagiID,ReplacementID);
	StatusType libFlag=SUCCESS;
	flagConverter(MMflag,&libFlag);


	return libFlag;
}



void Quit(void** DS){
	if (DS == NULL){
		return;
	}
	if (*DS == NULL){
		return;
	}
	MagicManager* tm = (MagicManager*)*DS;
	delete tm;
	*DS = NULL;
}
