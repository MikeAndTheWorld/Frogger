#include "Others.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

Others::Others()
{
	//gameover
	bool bSuccess = GameOverTex.loadFromFile("../../assets/gameover2.png"); // the sprite which contains the gameover screen
	if (bSuccess == false){exit(-1);}
	GameOverSPS.setSize(sf::Vector2f(431, 49)); // size
	GameOverSPS.setScale(1,1); // scale
	GameOverSPS.setPosition(10, 256); // the position set to the middle
	GameOverSPS.setTexture(&GameOverTex); // setting the texture
	
	//life counters
	bSuccess = life1Tex.loadFromFile("../../assets/counter.png");// the sprite for life counter
	if (bSuccess == false){exit(-1);}
	life1SPS.setSize(sf::Vector2f(7,7)); // size
	life1SPS.setScale(2,2); // scale
	life1SPS.setPosition(10, 490); // the position is set at the bottom
	life1SPS.setTexture(&life1Tex); // texture of the life counter
	//life counter 2
	bSuccess = life2Tex.loadFromFile("../../assets/counter.png");// the sprite for life counter
	if (bSuccess == false){exit(-1);}
	life2SPS.setSize(sf::Vector2f(7,7)); // size
	life2SPS.setScale(2,2); // scale
	life2SPS.setPosition(30, 490); // the position is set at the bottom
	life2SPS.setTexture(&life2Tex); // texture of the life counter
	//life counter 3
	bSuccess = life3Tex.loadFromFile("../../assets/counter.png");// the sprite for life counter
	if (bSuccess == false){exit(-1);}
	life3SPS.setSize(sf::Vector2f(7,7)); // size
	life3SPS.setScale(2,2); // scale
	life3SPS.setPosition(50, 490); // the position is set at the bottom
	life3SPS.setTexture(&life3Tex); // texture of the life counter
}
void Others::GameOverDraw(sf::RenderWindow& window)
{
	window.draw(GameOverSPS); // draw gameover
}
void Others::life1Draw(sf::RenderWindow& window)
{
	window.draw(life1SPS); // draw life
}
void Others::life2Draw(sf::RenderWindow& window)
{
	window.draw(life2SPS); // draw life
}
void Others::life3Draw(sf::RenderWindow& window)
{
	window.draw(life3SPS); // draw life
}