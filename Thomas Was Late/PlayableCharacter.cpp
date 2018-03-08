#include "stdafx.h"
#include "PlayableCharacter.h"

void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{
	//place the player at the starting point
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	//initialize the gravity
	m_Gravity = gravity;

	//mocve the sprtire to the postion
	m_Sprite.setPosition(m_Position);

}//end spawn()

void PlayableCharacter::update(float elapsedTime)
{
	//check if we shoulf be moving lefy ot right
	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}
	if (m_LeftPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
	}

	//handle jumping 
	if (m_IsJumping)
	{
		//update how long the jump has been going
		m_TimeThisJump += elapsedTime;

		//if we are still jumping upwards
		if (m_TimeThisJump<m_JumpDuration)
		{
			//move up at twice the speed of gravity
			m_Position.y -= m_Gravity * 2 * elapsedTime;
		}
		//if jump duraction has ended
		else
		{
			m_IsJumping = false;
			m_IsFalling = true;
		}
	}//end if (m_isjumping)

	if (m_IsFalling)
	{
		m_Position.y += m_Gravity * elapsedTime;
	}


	//update rect position for all body parts
	FloatRect r = getPosition();

	//Feet
	m_Feet.left = r.left + 3;
	m_Feet.top = r.top + r.height - 1;
	m_Feet.width = r.width - 6;
	m_Feet.height = 1;


	//Head
	m_Head.left = r.left;
	m_Head.top = r.top + (r.height * 0.3f);
	m_Head.width = r.width;
	m_Head.height = 1;


	//Right
	m_Right.left = r.left + r.width - 2;
	m_Right.top = r.top + r.height * 0.35f;
	m_Right.width = 1;
	m_Right.height = r.height * 0.3f;


	//Left
	m_Left.left = r.left;
	m_Left.top = r.top + r.height * 0.35f;
	m_Left.width = 1;
	m_Left.height = r.height * 0.3f;

	//move the sprite into position
	m_Sprite.setPosition(m_Position);


}//end Update()

FloatRect PlayableCharacter::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f PlayableCharacter::getCentre()
{
	return Vector2f(
		m_Position.x + m_Sprite.getGlobalBounds().width / 2,
		m_Position.y + m_Sprite.getGlobalBounds().height / 2 );


}

FloatRect PlayableCharacter::getFeet()
{
	return m_Feet;
}
FloatRect PlayableCharacter::getHead()
{
	return m_Head;
}
FloatRect PlayableCharacter::getLeft()
{
	return m_Left;
}
FloatRect PlayableCharacter::getRight()
{
	return m_Right;
}

Sprite PlayableCharacter::getSprite()
{
	return m_Sprite;
}

void PlayableCharacter::stopFalling(float postion)
{
	m_Position.y = postion - getPosition().height;
	m_Sprite.setPosition(m_Position);
	m_IsFalling = false;

}

void PlayableCharacter::stopRight(float position)
{
	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);

}

void PlayableCharacter::stopLeft(float position)
{
	m_Position.x = position + m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);

}

void PlayableCharacter::stopJump()
{
	m_IsJumping = false;
	m_IsFalling = true;
}