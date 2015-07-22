#include "GUI.h"

//Background
Background::Background(std::string filepath)
{
	bgTex.loadFromFile(filepath);
	bgTex.setSmooth(false);
	bgSprite.setTexture(bgTex);
	bgSprite.setPosition(0, 0);
}

void Background::Render(sf::RenderWindow &window)
{
	window.draw(bgSprite);
}
