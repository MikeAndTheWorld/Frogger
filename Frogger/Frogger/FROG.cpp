#include "FROG.h"
#include <Windows.h>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

FROG::FROG(){
	bool bSuccess = FrogTex.loadFromFile("../../assets/frog1.png"); // sprite of the frog
	if (bSuccess == false){exit(-1);} // exit if the sprite doesn't load
	frogSPS.setSize(sf::Vector2f(12, 13)); // size of frog
	frogSPS.setOrigin(6,6.5); // the origin of the frog
	frogSPS.setScale(2,2); // scale of the frog
	frogSPS.setPosition(224,464); // starting position of the frog
	frogSPS.setTexture(&FrogTex); // set the texture
	FrogBound = frogSPS.getGlobalBounds();
	isdead = false;
	fDeadTimer = 0;
}

void FROG::frogMovement(FROGDIRECTIONS direction) // switch directions
{
	switch (direction)
	{
	case Right: // right movement amount
		frogSPS.move(32.0f, 0.0f);
		frogSPS.setRotation(90);
		break;

	case Down: // down movement amount
		frogSPS.move(0.0f, 32.0f);
		frogSPS.setRotation(180);
		break;

	case Left: //left movement amount
		frogSPS.move(-32.0f, 0.0f);
		frogSPS.setRotation(270);
		break;

	case Up: //up movement amount
		/*if((frogSPS.getPosition().y - frogSPS.getScale().y / 2.0f * frogSPS.getSize().y) <= 0.0f)
		{
			frogSPS.setPosition(frogSPS.getPosition().x, frogSPS.getSize().y * frogSPS.getScale().y / 2.0f);
			frogSPS.setRotation(360);
		}*/
			frogSPS.move(0.0f, -32.0f);
			frogSPS.setRotation(360);
		break;
	}
}
void FROG::frogDeployment()
{
	isdead = false; // is the frog dead- true = dead - false = not dead
	fDeadTimer = 0;
	frogSPS.setSize(sf::Vector2f(12, 13)); // size of frog
	frogSPS.setOrigin(6,6.5); // the origin of the frog
	frogSPS.setScale(2,2); // scale of the frog
	frogSPS.setPosition(224,464); // starting position of the frog
	frogSPS.setTexture(&FrogTex); // set the texture
}
bool FROG::getfrogDead()
{
	return isdead;
}
void FROG::setFrogDead(bool isDead)
{
	isdead = isDead;
}
sf::FloatRect FROG::GetFrogBound() // get the bounding box
{
	return FrogBound; // bounding box for the frog
}
void FROG::UpdateDeadTimer(float fTimePassed)
{
	fDeadTimer += fTimePassed;
}
void FROG::frogDraw(sf::RenderWindow& window)
{
	if(getfrogDead()){
		bool bSuccess = FrogTex.loadFromFile("../../assets/death.png"); // sprite of the frog
		if (bSuccess == false){exit(-1);} // exit if the sprite doesn't load
		
		frogSPS.setOrigin(6,6.5); // the origin of the frog
		frogSPS.setSize(sf::Vector2f(12, 13));
		if (fDeadTimer >= 1) // if dead for 1 secound or more
		{
			frogDeployment(); // reset the frog
		}
		
	}
	else{
		bool bSuccess = FrogTex.loadFromFile("../../assets/frog1.png"); // sprite of the frog
		if (bSuccess == false){exit(-1);} // exit if the sprite doesn't load
		frogSPS.setSize(sf::Vector2f(12, 13)); // size of frog
		frogSPS.setOrigin(6,6.5); // the origin of the frog
		frogSPS.setTexture(&FrogTex); // set the texture
	}
	FrogBound = frogSPS.getGlobalBounds();
	window.draw(frogSPS); // draw frog
}
