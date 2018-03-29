#include "stdafx.h"
#include "SoundManager.h"
#include <SFML/Audio.hpp>

using namespace sf;

SoundManager::SoundManager()
{

	//load the sound in to buffer from file
	m_FireBuffer.loadFromFile("sound/fire1.wav");
	m_FallInFireBuffer.loadFromFile("sound/fallinfire.wav");
	m_FallInWaterBuffer.loadFromFile("sound/fallinwater.wav");
	m_JumpBuffer.loadFromFile("sound/jump.wav");
	m_ReachGoalBuffer.loadFromFile("sound/reachgoal.wav");

	//associate the sounds with the buffers
	m_Fire1Sound.setBuffer(m_FireBuffer);
	m_Fire2Sound.setBuffer(m_FireBuffer);
	m_Fire3Sound.setBuffer(m_FireBuffer);
	m_FallInFireSound.setBuffer(m_FallInFireBuffer);
	m_FallInWaterSound.setBuffer(m_FallInWaterBuffer);
	m_JumpSound.setBuffer(m_JumpBuffer);
	m_ReachGoalSound.setBuffer(m_ReachGoalBuffer);

	//when the player is 50 pixels away or closer, the sound is at full volume
	float minDistance = 150;

	//the sound reduces steadilt as teh player moves further away
	float attenuation = 15;

	//set attenuation levels for sounds
	m_Fire1Sound.setAttenuation(attenuation);
	m_Fire2Sound.setAttenuation(attenuation);
	m_Fire3Sound.setAttenuation(attenuation);


	//set min distance for sounds
	m_Fire1Sound.setMinDistance(minDistance);
	m_Fire2Sound.setMinDistance(minDistance);
	m_Fire3Sound.setMinDistance(minDistance);


	//loop all fire sounds when played
	m_Fire1Sound.setLoop(true);
	m_Fire2Sound.setLoop(true);
	m_Fire3Sound.setLoop(true);



}//end soundManager() constructor



void SoundManager::playFire(Vector2f emitterLocation, Vector2f listenerLocation)
{

	//set listener postion
	Listener::setPosition(listenerLocation.x, listenerLocation.y,0.0f);

	switch (m_NextSound)
	{

	case 1:
		//locvate/move the source of the sound
		m_Fire1Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

		if (m_Fire1Sound.getStatus() == Sound::Status::Stopped)
		{
			//play the sound if it is not already playing
			m_Fire1Sound.play();
		}
		break;

	case 2:
		//locvate/move the source of the sound
		m_Fire2Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

		if (m_Fire2Sound.getStatus() == Sound::Status::Stopped)
		{
			//play the sound if it is not already playing
			m_Fire2Sound.play();
		}
		break;

	case 3:
		//locvate/move the source of the sound
		m_Fire3Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

		if (m_Fire3Sound.getStatus() == Sound::Status::Stopped)
		{
			//play the sound if it is not already playing
			m_Fire3Sound.play();
		}
		break;
	}//end switch(m_NextSound)

	//increment to the nextfire sound
	m_NextSound++;

	//goback to 1 when teh thirs sound has been started
	if (m_NextSound > 3)
	{
		m_NextSound = 1;
	}



}//end playFire

void SoundManager::playFallInFire()
{
	m_FallInFireSound.setRelativeToListener(true);
	m_FallInFireSound.play();
}
void SoundManager::playFallInWater()
{
	m_FallInWaterSound.setRelativeToListener(true);
	m_FallInWaterSound.play();
}
void SoundManager::playJump()
{
	m_JumpSound.setRelativeToListener(true);
	m_JumpSound.play();
}
void SoundManager::playReachGoal()
{
	m_ReachGoalSound.setRelativeToListener(true);
	m_ReachGoalSound.play();
}