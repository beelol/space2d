#include "Game.h"
#include "Ship.h"

int Game::Run(sf::RenderWindow &window)
{
	bool running = true;
	Background bg(sf::String );
	Ship BlueShip(1);
	Ship RedShip(2);

	BlueShip.LoadShip(1);
	RedShip.LoadShip(2);

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
		BlueShip.RenderShip(BlueShip.GetSprite(), window);
		RedShip.RenderShip(RedShip.GetSprite(), window);
		window.display();

	}
	return (-1);
}