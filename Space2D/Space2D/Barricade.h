#include <SFML\Graphics.hpp>
#include "Ship.h"

class Barricade
{
public:
	Barricade();//For outline of ship
	Barricade(float ShipX, float ShipY, float ShipAngle);
	void LoadTexture();
	void RenderBarrOutline(float ShipX, float ShipY, float ShipAngle, sf::RenderWindow &window);
	void RenderBarricade(sf::RenderWindow &window);
private:
	float m_Angle;
	float m_PosX;
	float m_PosY;
	int m_Offset;

	sf::Texture m_BarTex;
	sf::Sprite m_SpriteBar;

	sf::Texture m_OutlineTex;
	sf::Sprite m_SpiteOutline;
};