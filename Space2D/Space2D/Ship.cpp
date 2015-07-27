#include "Ship.h"


Ship::Ship()
{
}

void LoadShip(int shipTeam)
{
	//if blue team
	if (shipTeam == 1)
	{

		ShipBlueTex.loadFromFile("");
		ShipBlueTex.setSmooth(false);
		SpriteBShip.setTexture(ShipBlueTex);
		SpriteBShip.setPosition(300, 0);
	}
	//if red team
	if (shipTeam == 2)
	{
		ShipBlueTex.loadFromFile("");
		ShipBlueTex.setSmooth(false);
		SpriteBShip.setTexture(ShipBlueTex);
		SpriteBShip.setPosition(300, 0);
	}
}

void RenderShip(sf::RenderWindow &window, sf::Sprite ShipSprite)
{
	window.draw(ShipSprite);
}