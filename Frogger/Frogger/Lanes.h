#ifndef Lanes_H
#define Lanes_H
#include <SFML/Graphics.hpp>
using namespace std;

class Lanes
{
private:
	sf::Texture LanesTex; // texture for the background
	sf::RectangleShape LanesSPS; // background sprite
public:
	Lanes();
	void lanesDraw(sf::RenderWindow& window); // drawing the background

};
#endif