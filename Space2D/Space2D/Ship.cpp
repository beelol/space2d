#include "Ship.h"
#include<iostream>
Ship::Ship(int team)//1 for blue 2 for red
{
	if (team == 1) 
	{
		m_BlueTeam = true;
		m_RedTeam = false;
	}

	else
	{
		m_RedTeam = true;
		m_BlueTeam = false;
	}
}

sf::Sprite Ship::GetSprite() 
{
		return m_SpriteShip;
}

int Ship::GetTeam()
{
	if (m_BlueTeam)
	{
		return m_BlueTeam;
	}
	else
	{
		return m_RedTeam;
	}

}

float Ship::GetSpeedVert()
{
	return m_ShipVelVert;
}

float Ship::GetSpeedHorz()
{
	return m_ShipVelHorz;
}


void Ship::LoadShip()
{
	//if blue team
	if (m_BlueTeam)
	{
		m_ShipTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/Textures/CoolShip.png");
		m_ShipTex.setSmooth(false);
		m_SpriteShip.setTexture(m_ShipTex);
		m_SpriteShip.setOrigin(10, 17);
		m_SpriteShip.setPosition(640, 310);
	}

	else// if not blue team then red team
	{
		m_ShipTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/Textures/RedShip.png");
		m_ShipTex.setSmooth(false);
		m_SpriteShip.setTexture(m_ShipTex);
		m_SpriteShip.setOrigin(10, 17);
		m_SpriteShip.setPosition(300, 200);
	}

}

void Ship::RenderShip(sf::Sprite ShipSprite, sf::RenderWindow &window)
{
	//ShipSprite.setRotation(m_ShipAngle);
	window.draw(ShipSprite);
}

void Ship::MoveShip(float ShipAccelVert, float ShipAccelHorz, float deltaTime)
{
	float movementYVert;
	float movementXVert;
	float movementYHorz;
	float movementXHorz;
	m_ShipVelVert += ShipAccelVert * deltaTime;

	if (m_ShipVelVert > m_ShipMaxVel)
	{
		m_ShipVelVert = m_ShipMaxVel;
	}
	else if (m_ShipVelVert < -m_ShipMaxVel)
	{
		m_ShipVelVert = -m_ShipMaxVel;
	}
	movementXVert = m_ShipVelVert * (cosf(m_ShipAngle * (PI / 180)));
	movementYVert = m_ShipVelVert * (sinf(m_ShipAngle * (PI / 180)));

	m_SpriteShip.move(movementXVert, movementYVert);//Moves towards and away from cursor

	m_ShipVelHorz += ShipAccelHorz * deltaTime;
	if (m_ShipVelHorz > m_ShipMaxVel)
	{
		m_ShipVelHorz = m_ShipMaxVel;
	}
	else if (m_ShipVelHorz < -m_ShipMaxVel)
	{
		m_ShipVelHorz = -m_ShipMaxVel;
	}
	movementXHorz = m_ShipVelHorz * (cosf((m_ShipAngle + 90) * (PI / 180)));
	movementYHorz = m_ShipVelHorz * (sinf((m_ShipAngle + 90) * (PI / 180)));

	m_SpriteShip.move(movementXHorz, movementYHorz);
}

void Ship::TrackMouse(sf::Sprite ShipSprite, sf::RenderWindow &window)// Makes the ship look at the cursor
{

	sf::Vector2f curPos = ShipSprite.getPosition();
	sf::Vector2i position = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(position);

	m_DX = curPos.x - worldPos.x;
	m_DY = curPos.y - worldPos.y;

	m_ShipAngle = (atan2(m_DY, m_DX)) * 180 / PI;
	m_SpriteShip.setRotation(m_ShipAngle);
}

void Ship::LoadLaser(float deltatime)
{

	m_LaserTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/Textures/Laser.png");
	m_LaserTex.setSmooth(false);
	m_SpriteLaser.setTexture(m_LaserTex);
	m_SpriteLaser.setPosition(m_SpriteShip.getPosition().x, m_SpriteShip.getPosition().y);
	m_SpriteLaser.rotate(m_ShipAngle);

	m_LaserMoveX = (cosf((m_ShipAngle)* (PI / 180)));
	m_LaserMoveY = (sinf((m_ShipAngle)* (PI / 180)));
	m_LaserMoveX += m_LaserSpeed * deltatime;
	m_LaserMoveY += m_LaserSpeed * deltatime;
}

void Ship::ShootLaser(sf::RenderWindow &window)
{
	m_SpriteLaser.move(m_LaserMoveX, m_LaserMoveY);
		window.draw(m_SpriteLaser);
}

//Rsin(Theta) = y
//Rcos(Theta) = x