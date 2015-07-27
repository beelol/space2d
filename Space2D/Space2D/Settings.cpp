#include "Settings.h"
#include <iostream>
int Settings::Run(sf::RenderWindow &window)
{
	bool running = true;
	Background bg("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/SettingsBackground.jpg");
	Button BtnResume(500, 100, "C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/ResumeButton.png");
	Button BtnFull(500, 300, "C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/FullScreenButton.png");
	Button BtnBack(500, 500, "C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/BackButton.png");
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
				bool check;
				mPosition = sf::Mouse::getPosition(window);
				check = BtnResume.CheckClick(mPosition.x, mPosition.y, BtnResume.getSprite());
				bool fullscreen = true;
				if (check)
				{
					std::cout << "Resume button pressed ";//GO BACK TO GAME
				}
				check = BtnFull.CheckClick(mPosition.x, mPosition.y, BtnFull.getSprite());
				if (check)
				{
					window.create(sf::VideoMode(1280, 720, 32), "Space2D", sf::Style::Fullscreen);
					//change texture of fullscreen button to windowed button. toggle back and forth when clicked multiple times.
				}
				check = BtnBack.CheckClick(mPosition.x, mPosition.y, BtnBack.getSprite());
				if (check)
				{
					return 0;
				}
			}

			window.clear();
			bg.Render(window);//Render background
			BtnResume.Render(window, BtnResume.getSprite());
			BtnFull.Render(window, BtnFull.getSprite());
			BtnBack.Render(window, BtnBack.getSprite());
			//Butttons.Render(window);//Render buttons to screen
			window.display();
		}
		
	}
	return (-1);
}