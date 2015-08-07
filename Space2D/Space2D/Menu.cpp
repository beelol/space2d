#include "Menu.h"
#include <iostream>

int Menu::Run(sf::RenderWindow &window)
{
	bool running = true;
	Background bg("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/Textures/MenuBackground.jpg");
	MenuGraphics Butttons;
	window.setFramerateLimit(60);

	//loop
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
				return (-1);
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				int check = -2;
				mPosition = sf::Mouse::getPosition(window);
				check = Butttons.CheckClick(mPosition.x, mPosition.y);
				if (check == 1 || check == 2 || check == (-1) || check == (3))
				{
					return check;
				}
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
		window.clear();
		bg.Render(window);//Render background
		Butttons.Render(window);//Render buttons to screen
		window.display();
			
	}

	return (-1);
}