#ifndef FROG_H
#define FROG_H
#include <SFML/Graphics.hpp>
#include "Entity.h"

enum FROGDIRECTIONS
{
	Left,
	Right,
	Up,
	Down
};

class FROG : public Entity
{
private:
	sf::Texture FrogTex;
	sf::RectangleShape frogSPS;
	sf::FloatRect FrogBound;
	bool isdead;
	float fDeadTimer;
public:
	FROG();
	void frogDeployment(); // place the frog
	void frogMovement(FROGDIRECTIONS direction); // move the frog
	bool getfrogDead(); // death of the frog
	void setFrogDead(bool isDead);
	void frogDraw(sf::RenderWindow& window);
	sf::FloatRect GetFrogBound();
	void UpdateDeadTimer(float fTimePassed);
};


#endif