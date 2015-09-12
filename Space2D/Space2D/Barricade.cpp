#include "Barricade.h"
#include <iostream>
Barricade::Barricade()
{
	LoadTexture();
}

Barricade::Barricade(float ShipX, float ShipY, float ShipAngle)
{
	m_Angle = ShipAngle;
	m_PosX = ShipX + 3;
	m_PosY = ShipY + 3;
	m_SpriteBar.setPosition(m_PosX, m_PosY);
}

void Barricade::LoadTexture()
{
	//Load texture and sprite for the real barricade
	m_BarTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/Textures/Barricade.png");
	m_BarTex.setSmooth(false);
	m_SpriteBar.setTexture(m_BarTex);
	m_SpriteBar.setOrigin(16, 11);

	//Load texture and sprite
	m_OutlineTex.loadFromFile("C:/Users/Liam/Documents/GitHub/space2d/Space2D/Space2D/Resources/Textures/Barricade.png");
	m_OutlineTex.setSmooth(false);
	m_SpiteOutline.setTexture(m_OutlineTex);
	m_SpiteOutline.setOrigin(16, 11); // Change to rotate around the origin of ship
}

void Barricade::RenderBarrOutline(float ShipX, float ShipY, float ShipAngle, sf::RenderWindow &window)
{
	m_Angle = ShipAngle;
	m_PosX = ShipX + 3;
	m_PosY = ShipY + 3;
	m_SpiteOutline.setPosition(m_PosX, m_PosY);
	window.draw(m_SpiteOutline);
	std::cout << "test";
}

void Barricade::RenderBarricade(sf::RenderWindow &window)
{

}