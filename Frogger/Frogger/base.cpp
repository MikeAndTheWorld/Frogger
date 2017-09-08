#include "base.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

base::base(float xbase, float ybase)
{
	baseBound.left = xbase; // x position of the bounding box
	baseBound.top = ybase; // y position of the bounding box
	baseBound.width = 32; // size
	baseBound.height = 32; 
}

sf::FloatRect base::GetbaseBound() // get the bounding box
{
	return baseBound; // bounding box for the base
}