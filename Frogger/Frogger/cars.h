#ifndef cars_H
#define cars_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
using namespace std;
class Cars : Entity
{
private:
	sf::Texture CarsTex;
	sf::RectangleShape CarsSPS;

public:
	Cars(string texture);
	void CarsDeployment(); // place the cars in
	void CarsMovement(); // move the cars to the left and right
	void CarsDraw(sf::RenderWindow& window,sf::RectangleShape& car);
	sf::RectangleShape GetCars();
};

#endif