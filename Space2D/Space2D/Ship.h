#include <SFML\Graphics.hpp>

class Ship
{

public:

	Ship(int team);
	void LoadShip(bool team);
	void RenderShip(sf::Sprite ShipSprite, sf::RenderWindow &window);
	sf::Sprite GetSprite();
	int GetTeam();

private:
	bool redTeam;
	bool blueTeam;

	sf::Texture ShipBlueTex;
	sf::Texture ShipRedTex;

	sf::Sprite SpriteBShip;
	sf::Sprite SpriteRShip;
};