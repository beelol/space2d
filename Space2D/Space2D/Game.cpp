#include "Game.h"
#include "Ship.h"
#include <iostream>;
int Game::Run(sf::RenderWindow &window)
{
	bool running = true;
	Background bg(sf::String );
	Ship B1(1);
	Ship R1(2);
	//Ship Laser();

	B1.LoadShip();
	R1.LoadShip();

	sf::Clock GameClock;
	//Main loop
	while (running)
	{
		float deltaTime = GameClock.restart().asSeconds();
		ShipVertAccel = 0;
		ShipHorzAccel = 0;
		WPressed = false;
		APressed = false;
		SPressed = false;
		DPressed = false;
		m_SpawnLaser = false;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)//Closes program
			{
				return (-1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				//Overlay ui
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				B1.LoadLaser(deltaTime);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Up
		{
			WPressed = true;
			//	ShipVertAccel = -50;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			WPressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			SPressed = true;
			//	ShipVertAccel = 50;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			SPressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))//Left
		{
			APressed = true;
			//ShipHorzAccel = -50;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			APressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			DPressed = true;
			//ShipHorzAccel = 50;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			DPressed = false;
		}

		//If buttons are pressed
		if (WPressed)
		{ShipVertAccel = -70;}
		if (APressed)
		{ShipHorzAccel = 70;}
		if (SPressed)
		{ShipVertAccel = 70;}
		if (DPressed)
		{ShipHorzAccel = -70;}

		ShipSpeedVert = B1.GetSpeedVert();
		ShipSpeedHorz = B1.GetSpeedHorz();
		if (WPressed == false && SPressed == false)
		{
			if (ShipSpeedVert > 0)
			{
				//ShipDecelVert = -20;
				ShipVertAccel = -20;
			}
			else if (ShipSpeedVert < 0)
			{
				//ShipDecelVert = 20;
				ShipVertAccel = 20;
			}
		}

		if (APressed == false && DPressed == false)
		{
			if (ShipSpeedHorz > 0)
			{
				//ShipDecelVert = -20;
				ShipHorzAccel = -20;
			}
			else if (ShipSpeedHorz < 0)
			{
				//ShipDecelVert = 20;
				ShipHorzAccel = 20;
			}
		}
		B1.TrackMouse(B1.GetSprite(), window); //Updates the sprite to follow the mouse
		B1.MoveShip(ShipVertAccel, ShipHorzAccel , deltaTime);
		window.clear();
		B1.RenderShip(B1.GetSprite(), window);//Render BlueShip to the screen
		R1.RenderShip(R1.GetSprite(), window);
		B1.ShootLaser(window);
		window.display();

	}
	return (-1);
}