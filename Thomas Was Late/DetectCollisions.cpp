#include "stdafx.h"
#include "Engine.h"

bool Engine::detectCollisions(PlayableCharacter& character)
{

	//initalise reached giak to dfalse by default
	bool reachGoal = false;

	//make a rectangle for th echaracters collision
	FloatRect detectionZone = character.getPosition();

	//make a floatrect to test each block
	FloatRect block;

	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	//build a zone around the chatacter to detect collision
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3; //thomas is quite tall

	//make sure we dont test positions lower than 0
	if (startX<0)
	{
		startX = 0;
	}
	if (startY<0)
	{
		startY = 0;
	}
	//make surewe dont test oisutuib grater than our level size
	if (endX > m_LM.getLevelSize().x)
		endX = m_LM.getLevelSize().x;

	if (endY > m_LM.getLevelSize().y)
		endY = m_LM.getLevelSize().y;

	//handle player falling out of the level
	FloatRect level(0, 0, m_LM.getLevelSize().x * TILE_SIZE, m_LM.getLevelSize().y*TILE_SIZE);

	if (!detectionZone.intersects(level))
	{
		//respawn the character
		character.spawn(m_LM.getStartPosition(), GRAVITY);

	}
	//loop all nearby blocks
	for (int x = startX; x < endX; ++x)
	{
		for (int y = startY; y < endY; ++y)
		{
			//set up our current block
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			//have we hjit lava or water
			//use the head collider on the character as this allows the character to sink a bit into the lava 
 			if (m_ArrayLevel[y][x] ==2||m_ArrayLevel[y][x] ==3)
			{
				if (character.getHead().intersects(block))
				{
					//they are in water / lava
					character.spawn(m_LM.getStartPosition(), GRAVITY);
					//play a sound on water or lava
					if (m_ArrayLevel[y][x]==2)//fire

					{
						m_SM.playFallInFire();
					}
					else //water
					{
						m_SM.playFallInWater();
					}

				}//end block collisiontest fire water
			}//end water lava test

			//is character colliding with a regular block?
			if (m_ArrayLevel[y][x] == 1)
			{
				if (character.getRight().intersects(block))
				{
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{

					character.stopLeft(block.left);
				}
				else if (character.getFeet().intersects(block))
				{
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					character.stopJump();
				}
			}

			//more colisions here once we have learned abput partoicle effects

			if (m_ArrayLevel[y][x] == 4)
			{
				//character has reached the goal
				reachGoal = true;
			}


		}//end y loop
	}//end x loop


	//return weather or not our character have completed this level
	return reachGoal;

}//end detect collisions