#include "stdafx.h"
#include "Engine.h"

void Engine::loadLevel()
{

	m_Playing = false;

	//delete the previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[]m_ArrayLevel[i];

	}
	delete[] m_ArrayLevel;

	//load the next 2dD array wwith the map the level
	//and repopulate the vertex areray as well
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

	//how long is thge new time linut
	m_TimeRemaining = m_LM.getTimeLimit();

	//spawn thomas and bob
	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);



}//end load level function