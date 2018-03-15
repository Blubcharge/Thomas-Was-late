#include "stdafx.h"
#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
	//associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/bob.png"));

	m_JumpDuration = 0.25f;

}//end function Bob


 //==========================================

bool Bob::handleInput()
{
	//always start asuming not jumping
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
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
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	//check right
	if (Keyboard::isKeyPressed(Keyboard::Right))
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