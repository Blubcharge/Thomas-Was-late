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
}//end level manager 