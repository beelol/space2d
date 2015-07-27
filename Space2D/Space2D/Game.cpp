#include "Game.h"
#include "Ship.h"

int Game::Run(sf::RenderWindow &window)
{
	bool running = true;
	Background bg(sf::String );

	
	//Main loop
	while (running)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				//Overlay
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{

				
			}
		}
		window.clear();
		//draw
		window.display();

	}
	return (-1);
}