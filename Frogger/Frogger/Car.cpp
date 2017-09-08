#include "Car.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

Car::Car(string texture, int scale, float x, float y,bool bIsLeft, float SpawnTime)
{
	m_texture = texture; // car texture
	setScale(scale); // car scale
	carSize = sf::Vector2f(16, 14); //size of the car image
	setXpos(x); //position of the car
	setYpos(y); //position of the car
	m_bIsLeft = bIsLeft; // is the car facing left
	m_bIsOffScreen = false; // is the car off screen
	m_SpawnTime = SpawnTime; // the time that the car spawn
}

void Car::draw(sf::RenderWindow& window)
{ 
	// draw out the cars
	ImgLoader(Car::CarsTex, Car::CarsSprite, Car::m_texture, Car::carSize);  // the sprite details
	CarsSprite.setPosition(getXpos(),getYpos());// setting the position of the cars
	CarBound = CarsSprite.getGlobalBounds(); // bounding box
	CarsSprite.setScale(getScale(), getScale());// setting the scale of the cars
	window.draw(CarsSprite); // drawing the sprite
}

void Car::CarsMovement(float fXpos)
{
	//moving the car
	if(m_bIsLeft == true) //if moving left
	{
		Entity::movement(-fXpos,0.0f); //move left
	}
	else
	{
		Entity::movement(fXpos,0.0f); //move right
	}
	//delete car going off screen
	if(Car::getXpos()+fXpos > 600.0f) // if car is out of the screen
	{
		m_bIsOffScreen = true; // the car is off screen
	}
	if(Car::getXpos()+fXpos < -50.0f) // if car is out of the screen
	{
		m_bIsOffScreen = true; // the car is off screen
	}
}
void Car::SetSpeed(float Speed)
{
	m_Speed = Speed; // set the speed of the car
}

float Car::GetSpeed()
{
	return m_Speed; // get the speed from set speed
}

float Car::GetSpawnTime()
{
	return m_SpawnTime; // = time of the car spawn from the last one
}

bool Car::IsOffScreen() // the car is off screen
{
	return m_bIsOffScreen; // return the m_bIsOffScreen
}

sf::FloatRect Car::GetCarBound() // get the bounding box
{
	return CarBound; // bounding box for the car
}