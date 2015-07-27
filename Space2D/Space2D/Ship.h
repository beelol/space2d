#include <SFML\Graphics.hpp>

class Ship
{
public:
	Ship();
	void LoadShip(int shipTeam);
	void RenderShip(sf::Sprite ShipSprite, sf::RenderWindow &window);

private:
	sf::Texture ShipBlueTex;
	sf::Texture ShipRedTex;

	sf::Sprite SpriteBShip;
	sf::Sprite SpriteRShip;
};