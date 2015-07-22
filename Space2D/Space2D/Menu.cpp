#include "Menu.h"

int Menu::Run(sf::RenderWindow &window)
{
	bool running = true;
	//Background::Background("Resources/Lobby.png");
	
	//loop
	while (running)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}

			/*if (event.type == sf::Event::MouseButtonReleased)
			{
				mPosition = sf::Mouse::getPosition(window);
				if (mPosition.x < 192 && mPosition.x > 64)
				{

				}
			}

			if (event.type == sf::Event::MouseMoved)
			{
				if (mPosition.x < 192 && mPosition.x > 64)
				{
					if (mPosition.y > 192)
					{
						//Check to see if on the exact buttons
						if (mPosition.y > 32 && mPosition.y < 64)//Over the start button
							
						if (mPosition.y > 96 && mPosition.y < 128)//Over the Options buttons

						if (mPosition.y > 160 && mPosition.y < 192)//Over the Exit button

					}
				}
				*/
		}

			
	}

	return (-1);
}