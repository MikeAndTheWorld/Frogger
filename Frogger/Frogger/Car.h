#ifndef CAR_H
#define CAR_H

#include "Entity.h"

#include <SFML/Graphics.hpp>

using namespace std;

class Car : public Entity
{
private:
	sf::Texture CarsTex; // car texture
	sf::Sprite CarsSprite; // sprites for the car
	sf::Vector2f carSize; // a vector for the size of the sprite
	string m_texture; // texture that can be passed
	bool m_bIsLeft; // is the car moving left
	bool m_bIsOffScreen; // is the car off screen
	float m_Speed; //speed of the car
	float m_SpawnTime; // spawning time of the car
	sf::FloatRect CarBound; //bounding box for the car
	
public:
	Car(string texture, int scale, float x,float y,bool bIsLeft, float SpawnTime);
	void CarsDeployment(); // place the cars in
	void CarsMovement(float fXpos); // move the cars to the left and right
	void draw(sf::RenderWindow& window); // draw the car
	bool IsOffScreen(); // is it off screen
	void SetSpeed(float Speed); // how fast is the car going
	float GetSpeed(); //getting the speed
	float GetSpawnTime(); // getting the spawntime
	sf::FloatRect GetCarBound(); // getting the bounding box for the car
};

#endif