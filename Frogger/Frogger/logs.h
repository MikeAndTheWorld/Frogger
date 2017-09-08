#ifndef logs_H
#define logs_H

#include "Entity.h"

#include <SFML/Graphics.hpp>

using namespace std;

class Logs : public Entity
{
private:
	sf::Texture logsTex; //log texture
	sf::Sprite logsSprite; //sprite for log
	sf::Vector2f logSize; // the size of the log
	//logs
	bool m_bIsLeft; // is the log moving left
	bool m_bIsOffScreen; // if the log off screen
	float m_Speed; // the speed of the log
	float m_SpawnTime; // spawning time of log
	string m_texture2; // texture
	sf::FloatRect logBound; // bounding box for the log
public:
	void logsDeployment(); // place the logs in
	void logsMovement(float fXpos); // move the logs to the left and right
	void draw(sf::RenderWindow& window); // drawing the logs
	bool IsOffScreen(); // is the logs off screen
	void SetSpeed(float Speed); // set the speed of the logs
	float GetSpeed(); // getting the speed of the logs
	float GetSpawnTime(); // getting the spawning time of the logs
	sf::FloatRect GetlogBound(); // bounding box for the log
	Logs(string m_texture, int scale, float x, float y,bool bIsLeft, float SpawnTime);
	bool getIsLeft(); // are the log moving left
};
#endif