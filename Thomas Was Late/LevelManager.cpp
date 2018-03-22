#include "stdafx.h"
#include "LevelManager.h"
#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextureHolder.h"
#include <sstream>
#include <fstream>


using namespace sf;
using namespace std;

int** LevelManager::nextLevel(VertexArray& rVaLevel)
{

	m_LevelSize.x = 0;
	m_LevelSize.y = 0;

	//get the nect level
	m_CurrentLevel++;
	if (m_CurrentLevel > NUM_LEVEL)
	{
		m_CurrentLevel = 1;
		m_TimeModifier -= 0.1f;
	}

	//load the appropriate level from a text file
	string levelToLoad;
	switch (m_CurrentLevel)
	{
	case 1:
		levelToLoad = "levels/level1.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 100;
		m_BaseTimeLimit = 30.0f;
		break;

	case 2:
		levelToLoad = "levels/level2.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 3600;
		m_BaseTimeLimit = 100.0f;
		break;

	case 3:
		levelToLoad = "levels/level3.txt";
		m_StartPosition.x = 1250;
		m_StartPosition.y = 0;
		m_BaseTimeLimit = 30.0f;
		break;

	case 4:
		levelToLoad = "levels/level4.txt";
		m_StartPosition.x = 50;
		m_StartPosition.y = 200;
		m_BaseTimeLimit = 50.0f;
		break;
	}//end switch

	ifstream inputFile(levelToLoad);
	string s;


	//count the number of rows in the file
	while (getline(inputFile, s))
	{
		++m_LevelSize.y;
	}

	//store the length of the rows (aka number of columns)
	m_LevelSize.x = s.length();

	//go back to the start of teh file 
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	//prepare the 2d array to hold the int values from the file
	int** arrayLevel = new int*[m_LevelSize.y];

	for (int i = 0; i < m_LevelSize.y; ++i)
	{
		arrayLevel[i] = new int[m_LevelSize.x];
	}

	//loop through file and store all the values in the 2d aray
	string row;
	int y = 0;
	while (inputFile >> row)
	{

		for (int x = 0; x < row.length(); x++)
		{
			const char val = row[x];
			arrayLevel[y][x] = atoi(&val);
		}

		y++;

	}
	//close file 
	inputFile.close();

	//what type of Primative are we using?
	rVaLevel.setPrimitiveType(Quads);

	//set size of vertex array
	rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD);

	//start at the beginning of the cartex array
	int currentVertex = 0;

	for (int x = 0; x < m_LevelSize.x; ++x)
	{
		for (int y = 0; y < m_LevelSize.y; y++)
		{

			rVaLevel[currentVertex + 0].position = Vector2f(
				x*TILE_SIZE, 
				y*TILE_SIZE);

			rVaLevel[currentVertex + 1].position = Vector2f(
				x*TILE_SIZE + TILE_SIZE,
				y*TILE_SIZE);

			rVaLevel[currentVertex + 2].position = Vector2f(
				x*TILE_SIZE + TILE_SIZE,
				y*TILE_SIZE + TILE_SIZE);

			rVaLevel[currentVertex + 3].position = Vector2f(
				x*TILE_SIZE,
				y*TILE_SIZE+ TILE_SIZE);




			//which tile from the sprite sheet shpuld we use
			int verticalOffset = arrayLevel[y][x] * TILE_SIZE;




			//set up texture coords
			rVaLevel[currentVertex + 0].texCoords = Vector2f(
				0,
				0 + verticalOffset);

			rVaLevel[currentVertex + 1].texCoords = Vector2f(
				TILE_SIZE,
				0 + verticalOffset);

			rVaLevel[currentVertex + 2].texCoords = Vector2f(
				TILE_SIZE,
				TILE_SIZE + verticalOffset);

			rVaLevel[currentVertex + 3].texCoords = Vector2f(
				0,
				TILE_SIZE + verticalOffset);

			//update our current vertex so we can draw the next quad
			currentVertex = currentVertex + VERTS_IN_QUAD;



		}//end of Y
	}//end of x

	return arrayLevel;

}//end level manager 


Vector2i LevelManager::getLevelSize()
{
	return m_LevelSize;
}

int LevelManager::getCurrenntLevel()
{
	return m_CurrentLevel;
}

float LevelManager::getTimeLimit()
{
	return m_BaseTimeLimit * m_TimeModifier;
}

Vector2f LevelManager::getStartPosition()
{
	return m_StartPosition;
}