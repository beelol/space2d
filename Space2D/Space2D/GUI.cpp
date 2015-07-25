#include "GUI.h"
#include <iostream>

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

MenuGraphics::MenuGraphics()
{
	//load Start button sprite
	MStartTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/StartButton.png");
	MStartTex.setSmooth(false);
	StartSprite.setTexture(MStartTex);
	StartSprite.setPosition(300, 0);
	//Load Options Button sprite
	MOptionsTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/OptionsButton.png");
	MOptionsTex.setSmooth(false);
	OptionsSprite.setTexture(MOptionsTex);
	OptionsSprite.setPosition(300, 360);
	//Load Exit button sprite
	MExitTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/ExitButton.png");
	MExitTex.setSmooth(false);
	ExtSprite.setTexture(MExitTex);
	ExtSprite.setPosition(300, 600);
}

void MenuGraphics::Render(sf::RenderWindow &window)
{
	//button sprite draw calls
	window.draw(StartSprite);
	window.draw(OptionsSprite);
	window.draw(ExtSprite);
}

int MenuGraphics::CheckClick(int x, int y)
{
	//Check to see if start button is clicked
	if (x > StartSprite.getPosition().x &&
		y > StartSprite.getPosition().y &&
		x < StartSprite.getPosition().x + StartSprite.getLocalBounds().width &&
		y < StartSprite.getPosition().y + StartSprite.getLocalBounds().height)
	{
		std::cout << "start ";
		return 1;
	}

	//Check to see if Options button is clicked
	if (x > OptionsSprite.getPosition().x &&
		y > OptionsSprite.getPosition().y &&
		x < OptionsSprite.getPosition().x + OptionsSprite.getLocalBounds().width &&
		y < OptionsSprite.getPosition().y + OptionsSprite.getLocalBounds().height)
	{
		std::cout << "options ";
		return 2;
	}

	//Check to see if exit is clicked
	if (x > ExtSprite.getPosition().x &&
		y > ExtSprite.getPosition().y &&
		x < ExtSprite.getPosition().x + ExtSprite.getLocalBounds().width &&
		y < ExtSprite.getPosition().y + ExtSprite.getLocalBounds().height)
	{
		std::cout << "exit ";
		return -1;
	}
	return 0;

}