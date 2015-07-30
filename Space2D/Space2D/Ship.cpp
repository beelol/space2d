#include "Ship.h"


Ship::Ship(int team)
{
	if (team = 1) 
	{
		redTeam = true;
	}

	if (team = 2)
	{
		redTeam = true;
	}
}

sf::Sprite Ship::GetSprite() 
{
		return SpriteBShip;
}

void Ship::LoadShip(int shipTeam)
{
	//if blue team
	if (shipTeam == 1)
	{
		ShipBlueTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/BlueShip.png");
		ShipBlueTex.setSmooth(false);
		SpriteBShip.setTexture(ShipBlueTex);
		SpriteBShip.setPosition(300, 650);
	}

	//if red team
	if (shipTeam == 2)
	{
		ShipBlueTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/RedShip.png");
		ShipBlueTex.setSmooth(false);
		SpriteBShip.setTexture(ShipBlueTex);
		SpriteBShip.setPosition(300, 0);
	}
}

void Ship::RenderShip(sf::Sprite ShipSprite, sf::RenderWindow &window)
{
	window.draw(ShipSprite);
}