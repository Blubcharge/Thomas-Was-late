#pragma once
#include <sfml/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "SoundManager.h"

using namespace sf;
//Note Dont use "using" in .h files!!!!!!!!!!!!!!!!!!!

class Engine
{
private:
	//the texture holder
	TextureHolder th;
	//Note: dont name things "th" (confusing latter)

	//OUR PLAYABLE CHARACTERS
	Thomas m_Thomas;
	Bob m_Bob;

	//a class to magane the levels
	LevelManager m_LM;

	//sound manager
	SoundManager m_SM;


	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	//a regular RenderWindow
	RenderWindow m_Window;

	//the main view
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	//three views for background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	//sprite and texture for background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	//is the game currently playing??
	bool m_Playing = false;

	//is character1 or 2 the current focus
	bool m_Character1 = true;
	//Note: use enum insted, name better

	//full or split screen
	bool m_SplitScreen = false;

	//time left in curent level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	//is it time for a new/first Level?
	bool m_NewLevelRequired = true;

	//the vertex array for the level tiles
	VertexArray m_VALevel;

	//the 2Darray with the map for the level (data) (0-3)
	//a pointer to a point (aka 2D array)

	int** m_ArrayLevel = NULL;

	//texture for the level files
	Texture m_TextureTiles;


	//privete functions for internal use

private:
	void input();
	void update(float dtAsSeconds);
	void draw();

	//load lnew level
	void loadLevel();

	//detect collision
	//polymorphism
	bool detectCollisions(PlayableCharacter& character);


	//make a vector of the best places to emit sounds from
	void populateEmitter(vector<Vector2f>&vSoundEmitters,int** arrayLevel);

	//a list(Vector) of vector2f to contain the fire emitter locations
	vector<Vector2f> m_FireEmitter;

public:
	//constructor
	Engine();
	//run will call all the private functions in a loop
	void run();



};