#include "Ship.h"


Ship::Ship(int team)//1 for blue 2 for red
{
	if (team == 1) 
	{
		blueTeam = true;
		redTeam = false;
	}

	else
	{
		redTeam = true;
		blueTeam = false;
	}
}

sf::Sprite Ship::GetSprite() 
{
	if (blueTeam)
	{
		return SpriteBShip;
	}

	else
	{
		return SpriteRShip;
	}
}

int Ship::GetTeam()
{
	if (blueTeam)
	{
		return blueTeam;
	}
	else
	{
		return redTeam;
	}

}

void Ship::LoadShip(bool team)
{
	//if blue team
	if (blueTeam)
	{
		ShipBlueTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/BlueShip.png");
		ShipBlueTex.setSmooth(false);
		SpriteBShip.setTexture(ShipBlueTex);
		SpriteBShip.setPosition(300, 650);
	}

	else
	{
		ShipRedTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/RedShip.png");
		ShipRedTex.setSmooth(false);
		SpriteRShip.setTexture(ShipRedTex);
		SpriteRShip.setPosition(300, 200);
	}

}

void Ship::RenderShip(sf::Sprite ShipSprite, sf::RenderWindow &window)
{
	window.draw(ShipSprite);
}