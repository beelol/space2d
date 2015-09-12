#include "Game.h"
#include <iostream>;

//std::cout << " " << " " << " "; 

int Game::Run(sf::RenderWindow &window)
{
	int ShipNumber = 0;
	bool running = true;
	Background bg(sf::String);
	Game Player;
	Barricade BaricadeOutline;
	//Ships.push_back(new Ship(2));
	//Ships[ShipNumber]->LoadShip();
	//Ship B1(1);
	Ship R1(2);
	//bullets.push_back(new Bullet(shipSpr.GetPosition().x, shipSpr.GetPosition().y, 0.3, shipSpr.GetRotation(), bulletImg));

	//B1.LoadShip();
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
				//Pull up the overlay ui

			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (!Ships.empty())//Makes sure there is a ship that the laser can shoot from
				{
					//Lasers.push_back(new Ship(3));
					Ships[ShipNumber]->LoadLaser(deltaTime);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))//join Blue
			{
				Player.m_team = 1;
				Ships.push_back(new Ship(1));
				Ships.back()->LoadShip();
				m_ShipsInGame++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))//Join Red
			{
				Player.m_team = 2;
				Ships.push_back(new Ship(2));
				Ships.back()->LoadShip();
				m_ShipsInGame++;
			}
		}
		///////////////////End of Event loop

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))//used for rendering the barricade outline
		{
			CPressed = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			CPressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Up
		{
			WPressed = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))//Not up
		{
			WPressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))//Down
		{
			SPressed = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S))//Not down
		{
			SPressed = false;
		}
		/////////////////////////////HORZ
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))//Left
		{
			APressed = true;
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))//Not left
		{
			APressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))//Right
		{
			DPressed = true;
			//std::cout << " d ";
		}
		else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))//Not right
		{
			DPressed = false;
			//std::cout << " !d ";
		}

		//If buttons are pressed
		if (WPressed)
		{
			ShipVertAccel = -70;
		}
		if (APressed)
		{
			ShipHorzAccel = 70;
		}
		if (SPressed)
		{
			ShipVertAccel = 70;
		}
		if (DPressed)
		{
			//std::cout << " d ";
			ShipHorzAccel = -70;
		}

		if (m_ShipsInGame != 0)
		{
			ShipSpeedVert = Ships[ShipNumber]->GetSpeedVert();
			ShipSpeedHorz = Ships[ShipNumber]->GetSpeedHorz();
		}

		//std::cout << " " <<ShipSpeedVert << " " ;
		if (WPressed == false && SPressed == false)
		{
				if (ShipSpeedVert > 0)
				{
					ShipVertAccel = -20; // Decel the ship
				}
				else if (ShipSpeedVert < 0)
				{
					ShipVertAccel = 20; //Decel the ship
				}
		}

		if (APressed == false && DPressed == false)
		{
			if (ShipSpeedHorz > 0)
			{
				//std::cout << " a ";
				ShipHorzAccel = -20;
			}
			else if (ShipSpeedHorz < 0)
			{
				//std::cout << " b ";
				ShipHorzAccel = 20;
			}
		}

		//Render Barricade outline
		if (CPressed)
		{   
			//std::cout << "test";
			if (m_ShipsInGame != 0)
			{
				//std::cout << "test";
				//Ship x, ship y, ship angle, window
				BaricadeOutline.RenderBarrOutline(m_ShipPosX, m_ShipPosY, Ships[ShipNumber]->GetAngle(), window);
			}
		}
		else if(!CPressed)
		{}

			if (m_ShipsInGame != 0)
			{
				sf::Sprite temp = Ships[ShipNumber]->GetSprite();
				m_ShipPosX = temp.getGlobalBounds().height;
				m_ShipPosY = temp.getGlobalBounds().left;
				Ships[ShipNumber]->TrackMouse(Ships[ShipNumber]->GetSprite(), window); //Updates the sprite to follow the mouse
				Ships[ShipNumber]->MoveShip(ShipVertAccel, ShipHorzAccel, deltaTime);
			}
			window.clear();
			if (m_ShipsInGame != 0){
				Ships[ShipNumber]->RenderShip(Ships[ShipNumber]->GetSprite(), window);//Render BlueShip to the screen
				R1.RenderShip(R1.GetSprite(), window);
				Ships[ShipNumber]->ShootLaser(window);
				//Temp.RenderShip(R1.GetSprite(), window);
				Ships[ShipNumber]->ShootLaser(window);
			}
			window.display();
			//std::cout << "run";

		}
		//return (-1);
	}

//bullets.push_back(new Bullet(shipSpr.GetPosition().x, shipSpr.GetPosition().y, 0.3, shipSpr.GetRotation(), bulletImg));