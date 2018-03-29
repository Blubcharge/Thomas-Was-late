#include "stdafx.h"
#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::populateEmitter(vector<Vector2f>&vSoundEmitters, int** arrayLevel)
{
	//make sure the cector is empty
	vSoundEmitters.clear();

	//keep track of the previous emitter
	//so we dont make too many
	FloatRect previousEmitter;

	//search through the level for fire
	for (int x = 0; x < m_LM.getLevelSize().x; x++)
	{
		for (int y = 0; y < m_LM.getLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2)//2=fire
			{
				//skip over fire tiles too near the previous emitter
				FloatRect CurrentTIle = FloatRect(x * TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE);
				if (!CurrentTIle.intersects(previousEmitter))
				{
					//add the coordinates of this block
					vSoundEmitters.push_back(Vector2f(x*TILE_SIZE, y*TILE_SIZE));

					//make a rectangle 6 blocjs x 6 blocks so we dibt make more emitters to close to this one]
					previousEmitter.left = x*TILE_SIZE;
					previousEmitter.top = y*TILE_SIZE;
					previousEmitter.width = TILE_SIZE*6;
					previousEmitter.height= TILE_SIZE*6;


				}//end if not too close to other emitter
			}//end if fire
		}//end y loop

	}//end x loop


}//end populateEmitter