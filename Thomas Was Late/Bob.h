#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{

public:

	//constructor
	Bob();

	//this will imlement the pure virtual funciton from playable
	bool virtual handleInput();



};//end thomas class