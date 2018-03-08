#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{

			//handle the player quitting
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();

			}

			//handle the player starting the game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}

			//switch between Thomas and Bob camera focus
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				m_Character1 = !m_Character1;;
			}

			//switch between full and split screen
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_SplitScreen = !m_SplitScreen;
			}
		}

	}// end while event polling

}//end void engine input