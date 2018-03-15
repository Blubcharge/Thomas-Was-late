#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{

	if (m_NewLevelRequired)
	{
		// this will be move to loadLevel() later
		//spawn THomas and bob
		m_Thomas.spawn(Vector2f(0, 0), GRAVITY);
		m_Bob.spawn(Vector2f(100, 0), GRAVITY);


		//initialise time and level boolean
		m_TimeRemaining = 10;
		m_NewLevelRequired = false;
	}


	if (m_Playing)
	{

		//update thomas and bob
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);

		//count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		//have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;

		}




	}//end of if playing

	//set view around aproprate characters
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCentre());
		m_RightView.setCenter(m_Bob.getCentre());
	}
	else
	{
		if (m_Character1)//if we should focus on thomas
		{
			m_MainView.setCenter(m_Thomas.getCentre());
		}
		else
		{

			m_MainView.setCenter(m_Bob.getCentre());
		}
	}

}//end of Engine pdate