#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{

public: 
	
	//constructor
	Thomas();

	//this will imlement the pure virtual funciton from playable
	bool virtual handleInput();



};//end thomas class