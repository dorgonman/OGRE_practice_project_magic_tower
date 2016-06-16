#include "Stage.h"


bool Stage::exist(Ogre::Vector3 v, std::vector<Ogre::Vector3> vecArr){
	for(int i = 0; i < vecArr.size(); i++){
		Ogre::Vector3 p = vecArr[i];
		if(p.x == v.x && p.y == v.y && p.z == v.z){
			return true;
		}
	}
	return false;
}



void Stage::addTime(double deltaTimeStep){
	mTime += deltaTimeStep;
	//���p�ƫe3��A���M�B�I�Ʒ|�����쪺���D
	mTime = (double)((int)(mTime*1000)*0.001); 
}


