#ifndef BASE_H
#define BASE_H

#include <SFML/Graphics.hpp>

class base
{
private:
	sf::FloatRect baseBound; //bounding box for base

public:
	base(){};
	base(float xbase, float ybase); // the posistion of the base
	sf::FloatRect GetbaseBound(); //get the bounding box
};

#endif