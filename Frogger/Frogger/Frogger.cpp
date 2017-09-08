#include "Frogger.h"
#include <Windows.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

Frogger::Frogger(){
	bool bSuccess = FrogTex.loadFromFile("../../assets/frog1.png"); // sprite of the frog
	if (bSuccess == false){exit(-1);} // exit if the sprite doesn't load
	frogSPS.setSize(sf::Vector2f(12, 13)); // size of frog
	frogSPS.setOrigin(6,6.5); // the origin of the frog
	frogSPS.setScale(2,2); // scale of the frog
	frogSPS.setPosition(224,464); // starting position of the frog
	setYpos(464.0f); // setting the y position for the frog
	frogSPS.setTexture(&FrogTex); // set the texture
	FrogBound = frogSPS.getGlobalBounds(); // bounding box for frog
	isdead = false; // the frog is not dead
	IsOnLog = false; // the frog is not on log
	fDeadTimer = 0; // death timer pause is 0
	iLifeCounter = 3; // 3 lives
}

void Frogger::frogMovement(FROGDIRECTIONS direction,sf::RenderWindow& window) // switch directions
{
	switch (direction)
	{
	case Right: // right movement amount
		if(frogSPS.getPosition().x >= window.getSize().x) // move off screen on right side
		{
			isdead = true; // dead
		}
		frogSPS.move(32.0f, 0.0f); // move right
		frogSPS.setRotation(90); // turn 90°
		break;

	case Down: // down movement amount
		frogSPS.move(0.0f, 32.0f); // move down
		frogSPS.setRotation(180); // turn 180°
		if(frogSPS.getPosition().y > 464) //move down from first lane
		{
			isdead = true; //dead
		}
		break;

	case Left: //left movement amount
		if(frogSPS.getPosition().x <= 0) // move off screen on the left side
		{
			isdead = true; //dead
		}
		frogSPS.move(-32.0f, 0.0f); //move left
		frogSPS.setRotation(270); //turn 270°
		break;

	case Up: //up movement amount
		frogSPS.move(0.0f, -32.0f); // move up
		frogSPS.setRotation(360); // full turn
		break;
	}
}
void Frogger::frogDeployment()
{
	isdead = false; // is the frog dead- true = dead - false = not dead
	fDeadTimer = 0; // timer for death pause
	frogSPS.setSize(sf::Vector2f(12, 13)); // size of frog
	frogSPS.setOrigin(6,6.5); // the origin of the frog
	frogSPS.setScale(2,2); // scale of the frog
	frogSPS.setPosition(224,464); // starting position of the frog
	frogSPS.setTexture(&FrogTex); // set the texture
}
bool Frogger::getfrogDead()
{
	return isdead; //return if the frog is dead or not
}
void Frogger::setFrogDead(bool isDead)
{
	isdead = isDead; // death
}
// on log
bool Frogger::getOnLog()
{
	return IsOnLog;
}
void Frogger::setOnLog(bool isOnLog)
{
	IsOnLog = isOnLog; // frog's on log
}

sf::FloatRect Frogger::GetFrogBound() // get the bounding box
{
	return FrogBound; // bounding box for the frog
}
void Frogger::UpdateDeadTimer(float fTimePassed) //update the timer of death
{
	fDeadTimer += fTimePassed; //the amount of time passed and that is to update the timer when the frog is dead
}
void Frogger::frogDraw(sf::RenderWindow& window)
{
	

	if(getfrogDead()){
		bool bSuccess = FrogTex.loadFromFile("../../assets/death.png"); // sprite of the frog
		if (bSuccess == false){exit(-1);} // exit if the sprite doesn't load
		frogSPS.setOrigin(6,6.5); // the origin of the frog
		frogSPS.setSize(sf::Vector2f(12, 13)); // the size of the frog
		if (fDeadTimer >= 0.5) // if dead for 1 secound or more
		{
			frogDeployment(); // reset the frog
			iLifeCounter --; // take one life off
		}
		
	}
	else{
		bool bSuccess = FrogTex.loadFromFile("../../assets/frog1.png"); // sprite of the frog
		if (bSuccess == false){exit(-1);} // exit if the sprite doesn't load
		frogSPS.setSize(sf::Vector2f(12, 13)); // size of frog
		frogSPS.setOrigin(6,6.5); // the origin of the frog
		frogSPS.setTexture(&FrogTex); // set the texture
	}
	FrogBound = frogSPS.getGlobalBounds(); //frog's bounding boxes
	window.draw(frogSPS); // draw frog
}
float Frogger::GetPosition()
{
	return frogSPS.getPosition().y; // get the position of the frog
}

void Frogger::moveOnLog(Logs log,sf::RenderWindow& window)
{
	if(log.getIsLeft()) // if the logs are moving left
	{
		frogSPS.setPosition(frogSPS.getPosition().x - log.GetSpeed(), frogSPS.getPosition().y); // move to the left with the logs
		if(frogSPS.getPosition().x <= 0) // if the frog is moved off screen
		{
		   isdead = true;// dead
		}
	}
	else // logs moving right
	{
		frogSPS.setPosition(frogSPS.getPosition().x + log.GetSpeed(), frogSPS.getPosition().y); // move to the right with the logs
		if(frogSPS.getPosition().x >= window.getSize().x) // if the frog is moved off screen
		{
			isdead = true; //dead
		}
	}
}

int Frogger::iGetLifeCounter()
{
	return iLifeCounter; // get life counter
}
void Frogger::iSetLifeCounter(int iLife_Counter)
{
	iLifeCounter = iLife_Counter; //setting the life counter
}