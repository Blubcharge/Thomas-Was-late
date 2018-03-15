#include "stdafx.h"
#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	//associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));

	m_JumpDuration = 0.45f;

}//end function Thomas


//==========================================

bool Thomas::handleInput()
{
	//always start asuming not jumping
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		//start a jump if not already jumping but only if standing on block(not falling)
		if (!m_IsJumping && !m_IsFalling)
		{
			//perform jump
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}//end if not jumping

	}//end wif keyboard pressed w
	else
	{
		//stop jump early if W not held down
		m_IsJumping = false;
		m_IsFalling = true;

	}

	//check left
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	//check right
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}

	//return wether we just jumped  or not
	return m_JustJumped;

}//end function handle input()