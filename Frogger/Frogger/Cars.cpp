#include "cars.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

Cars::Cars(string texture)
{
	bool bSuccess = CarsTex.loadFromFile("../../assets/" + texture);
	if (bSuccess == false){exit(-1);}
	CarsSPS.setSize(sf::Vector2f(16, 14));
	CarsSPS.setScale(4,4);
	CarsSPS.setPosition(0,835);
	CarsSPS.setTexture(&CarsTex);
}


void Cars::CarsDraw(sf::RenderWindow& window,sf::RectangleShape& car)
{
	window.draw(car);
}
sf::RectangleShape Cars::GetCars()
{
	return CarsSPS;
}