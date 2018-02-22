#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
}

void Engine::update(float dtAsSeconds)
{
}

void Engine::draw()
{
}

Engine::Engine()
{
	//get the screen resolution
	//and create an sfml window and view
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Thomas Was Late", Style::Fullscreen);

	//initalise the fullscreen view
	m_MainView.setSize(resolution);
	m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	//initalise split screen view
	m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_RightView.setViewport(FloatRect(0.5f, 0.001f, 0.498f, 0.998f));

	//split screen background
	m_BGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
	m_BGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.498f, 0.998f));

	//Get background texxture
	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");

	//associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);


}

void Engine::run()
{
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		//Update the total gametime
		m_GameTimeTotal += dt;

		//make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		//call each part of the game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}
}
