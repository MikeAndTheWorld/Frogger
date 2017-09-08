#ifndef OTHERS_H
#define OTHERS_H
#include <SFML/Graphics.hpp>
using namespace std;

class Others
{
private:
	sf::Texture GameOverTex; //gameover texture
	sf::RectangleShape GameOverSPS; // gameover sprite
	//life counter 3
	sf::Texture life3Tex;
	sf::RectangleShape life3SPS;
	//life counter 2
	sf::Texture life2Tex;
	sf::RectangleShape life2SPS;
	//life counter 1
	sf::Texture life1Tex;
	sf::RectangleShape life1SPS;

public:
	Others();
	void GameOverDraw(sf::RenderWindow& window);// draw gameover sprite
	void life3Draw(sf::RenderWindow& window); // draw life counter 3
	void life2Draw(sf::RenderWindow& window); // draw life counter 2
	void life1Draw(sf::RenderWindow& window); // draw life counter 1
};
#endif