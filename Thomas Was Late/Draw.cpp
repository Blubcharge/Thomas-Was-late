#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{
	//erase the last frame
	m_Window.clear(Color::White);

	//single screen
	if (!m_SplitScreen)
	{
		//switch to background view
		m_Window.setView(m_BGMainView);

		//draw the background
		m_Window.draw(m_BackgroundSprite);
		
		//set main view
		m_Window.setView(m_MainView);
		//ToDo draw all the stuff


		//draw Thomas and bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());


	}//end single screen

	//splitscreen
	else
	{
		//draw thomas' sind of screen
		//switch to the background view
		m_Window.setView(m_BGLeftView);
		//drae background
		m_Window.draw(m_BackgroundSprite);
		//switch to the main view for left
		m_Window.setView(m_LeftView);
		//TOBO Draw all the stuff

		//draw Thomas and bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());


		//draw Bobs sind of screen
		//switch to the background view
		m_Window.setView(m_BGRightView);
		//drae background
		m_Window.draw(m_BackgroundSprite);
		//switch to the main view for left
		m_Window.setView(m_RightView);
		//TOBO Draw all the stuff

		//draw Thomas and bob
		m_Window.draw(m_Thomas.getSprite());
		m_Window.draw(m_Bob.getSprite());


	}//end split screen

	//draw HUD
	//switch to hud
	m_Window.setView(m_HudView);
	//to do Draw HUD

	//show everything we have just drawn
	m_Window.display();


}//end of draw function