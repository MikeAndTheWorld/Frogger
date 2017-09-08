#ifndef FROGGER_H
#define FROGGER_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "logs.h"

enum FROGDIRECTIONS
{
	Left, // enum for left
	Right, // enum for right
	Up, // enum for up
	Down // enum for down
};

class Frogger : public Entity
{
private:
	sf::Texture FrogTex; //frog texture
	sf::RectangleShape frogSPS; // frog sprite
	sf::FloatRect FrogBound; // frog bounding box
	bool isdead; // is the frog dead
	bool IsOnLog; // is the frog on the log
	float fDeadTimer; // the timer between death and back to life again
	int iLifeCounter; // the life counter
	
public:
	Frogger();
	void frogDeployment(); // place the frog
	void frogMovement(FROGDIRECTIONS direction,sf::RenderWindow& window); // move the frog
	void moveOnLog(Logs log,sf::RenderWindow& window); // moving with the log
	bool getfrogDead(); // death of the frog
	void setFrogDead(bool isDead); // is the frog dead
	bool getOnLog(); // is the frog on log
	void setOnLog(bool IsOnLog); // is the frog on log
	void frogDraw(sf::RenderWindow& window); // draw the frog
	sf::FloatRect GetFrogBound(); //get the bounding box for frog
	void UpdateDeadTimer(float fTimePassed); // repawn timer
	float GetPosition(); // get the position of the frog
	int iGetLifeCounter(); // get the number of life the frog has
	void iSetLifeCounter(int iLife_Counter); // set the frog the frog has
};


#endif