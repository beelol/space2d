#include <vector>
#include <iostream>
#include "StateManager.h"
#include  <SFML\Graphics.hpp>
#include "IOScreen.h"

int main()
{
	//StateManager IDs
	std::vector<StateManager*> states;
	int screenState = 0;

	//create window
	IOScreen ioscreen;
	sf::RenderWindow window;
	window.setFramerateLimit(60);

	if (ioscreen.getScreenSettings())
	{
		window.create(sf::VideoMode(800, 600, 32), "Space2D", sf::Style::Fullscreen);
		window.setMouseCursorVisible(false);
	}
	else
	{
		window.create(sf::VideoMode(800, 600, 32), "Space2D", sf::Style::Default);
	}