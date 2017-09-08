#include "logs.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

Logs::Logs(string texture, int scale, float x, float y,bool bIsLeft, float SpawnTime)
{
	m_texture2 = texture; // log texture
	setScale(scale); // log scale
	logSize = sf::Vector2f(70, 20); // size of the log
	setXpos(x); //position of the log
	setYpos(y); //position of the log
	m_bIsLeft = bIsLeft; // is the log facing left
	m_bIsOffScreen = false; // is the log off screen
	m_SpawnTime = SpawnTime; // the time that the log spawn
}

void Logs::draw(sf::RenderWindow& window){ // draw out the logs
	ImgLoader(Logs::logsTex, Logs::logsSprite, Logs::m_texture2, Logs::logSize);  // the sprite details
	logsSprite.setPosition(getXpos(),getYpos());// setting the position of the logs
	logBound = logsSprite.getGlobalBounds(); // bounding box
	logsSprite.setScale(getScale(), getScale());// setting the scale of the logs
	window.draw(logsSprite); // drawing the sprite
}

void Logs::logsMovement(float fXpos)
{
	//moving the logs
	if(m_bIsLeft == true)
	{
		Entity::movement(-fXpos,0.0f);
	}
	else
	{
		Entity::movement(fXpos,0.0f);
	}
	//delete logs going off screen
	if(Logs::getXpos()+fXpos > 700.0f) // if log is out of the screen
	{
		m_bIsOffScreen = true; // the log is off screen
	}
	if(Logs::getXpos()+fXpos < -100.0f) // if log is out of the screen
	{
		m_bIsOffScreen = true; // the log is off screen
	}

}
void Logs::SetSpeed(float Speed)
{
	m_Speed = Speed; // set the speed of the logs
}

float Logs::GetSpeed()
{
	return m_Speed; // get the speed from set speed
}

float Logs::GetSpawnTime()
{
	return m_SpawnTime; // = time of the log spawn from the last one
}

bool Logs::IsOffScreen() // the log is off screen
{
	return m_bIsOffScreen; // return the m_bIsOffScreen
}

sf::FloatRect Logs::GetlogBound() // get the bounding box
{
	return logBound; // bounding box for the log
}

bool Logs::getIsLeft() // get bisleft
{
	return m_bIsLeft;
}