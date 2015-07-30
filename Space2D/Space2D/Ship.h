#include <SFML\Graphics.hpp>

class Ship
{

public:

	Ship(int team);
	sf::Sprite GetSprite();
	void LoadShip(int shipTeam);
	void RenderShip(sf::Sprite ShipSprite, sf::RenderWindow &window);

private:
	bool redTeam;
	bool blueTeam;

	sf::Texture ShipBlueTex;
	sf::Texture ShipRedTex;

	sf::Sprite SpriteBShip;
	sf::Sprite SpriteRShip;
};