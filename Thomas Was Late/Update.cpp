#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{

	if (m_NewLevelRequired)
	{
		loadLevel();
	}


	if (m_Playing)
	{

		//update thomas and bob
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);

		//detect colliosions sand see if the character have reachef th goal
		if (detectCollisions(m_Thomas)&& detectCollisions (m_Bob))
		{
			m_NewLevelRequired = true;

			//todo play sound for reaching goal


		}
		else
		{
			//run bob collision detection
			detectCollisions(m_Bob);

		}

		//let bob and thomas jump on cach others head
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		//let bob and thomas jump on cach others head
		if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}


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