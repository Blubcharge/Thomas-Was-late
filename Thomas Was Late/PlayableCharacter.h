#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{

	//these variables 
protected:
	Sprite m_Sprite;

	//How log does a jump last
	float m_JumpDuration;

	//is the character currently jumping or falling
	bool m_IsJumping;
	bool m_IsFalling;

	//which dorection is the character currently moving in
	bool m_LeftPressed;
	bool m_RightPressed;

	//how long has this jump lasted so far?
	float m_TimeThisJump;

	//Has the player just initiated a jump
	bool m_JustJumped = false;

	//these variable can only be edited and viewed by this class, not sub classes
private:
	//what is gravity
	float m_Gravity;

	//how fast is the character
	float m_Speed = 400;

	Vector2f m_Position;

	//where are the character various body part
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	Texture m_texture;

	//public funcltions
public:
	void spawn(Vector2f startPosition, float gravity);

	//this is a pure virtual function
	//this means this class becimes an abstract class
	//meaning we cannot creat an instance od this class, only sub classes
	//sub classes MUST implement this function in order to create instances

	bool virtual handleInput() = 0;

	//where is the player?
	FloatRect getPosition();

	// a rectangle representing rh position of different parts of the sprite
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	//get copy to the sprite
	Sprite getSprite();

	//make the chatacter stop moving
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();


	//where is the center of the character
	Vector2f getCentre();

	//we will call this function once every frame
	void update(float elapsedTime);


};//end of playable character class