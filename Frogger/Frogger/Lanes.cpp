#include "Lanes.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

Lanes::Lanes()
{
	bool bSuccess = LanesTex.loadFromFile("../../assets/froggerbg2.png");// the background sprite which contains all the lanes
	if (bSuccess == false){exit(-1);}
	LanesSPS.setSize(sf::Vector2f(448, 512)); // size of the background
	LanesSPS.setScale(1,1); // scale of the background
	LanesSPS.setPosition(0,0); // the position from the top left
	LanesSPS.setTexture(&LanesTex); // texture of the background
	//water
}
void Lanes::lanesDraw(sf::RenderWindow& window)
{
	window.draw(LanesSPS); // draw lanes
}
