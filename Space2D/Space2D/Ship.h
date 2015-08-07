#include <SFML\Graphics.hpp>
#include <math.h>

class Ship
{

public:
	Ship(int team);//Sets the team when the object is created
	void LoadShip();//Loads the texture and sprite for the object
	void LoadLaser(float deltatime);
	void RenderShip(sf::Sprite ShipSprite, sf::RenderWindow &window);//Renders the ship to the screen
	void TrackMouse(sf::Sprite ShipSprite, sf::RenderWindow &window);//Makes the ship look at mouse
	void MoveShip(float ShipAccelVert, float ShipAccelHorz, float deltaTime);// Moves the ship when buttons are clicked and decelerates ship.
	void ShipCheckCollision();
	void ShootLaser(sf::RenderWindow &window);//Shoots laser.....

	//Get functions:
	sf::Sprite GetSprite();
	int GetTeam();
	float GetSpeedVert();
	float GetSpeedHorz();

private:
	bool m_RedTeam;
	bool m_BlueTeam;
	bool m_LaserLive;

	const float PI = 3.14159265;
	float m_ShipY = 0;//Ship position y
	float m_ShipX = 0;//Ship postion x
	float m_ShipVelVert;//Velocity of the ship on the local vertical axis which is the vector from the sprites origin to the cursor.
	float m_ShipVelHorz;//Velocity of the ships local horizontal axis which is 90 Degrees from the vert axis.
	float m_ShipDecel = 1.5;//The rate at which the ship decelerates
	float m_ShipMaxVel = 6.3;// Max speed the ship can reach.
	float m_DX, m_DY; // Distance in x and in y from the sprite to the mouse. Calculated in TrackMouse function.
	float m_ShipAngle;//Angle that the ship is facing.
	float m_LaserSpeed = 1500;//Speed of laser
	float m_LaserMoveX;
	float m_LaserMoveY;

	sf::Texture m_ShipTex;//Ship texture
	sf::Sprite m_SpriteShip;//Ship sprite
	
	sf::Texture m_LaserTex;
	sf::Sprite m_SpriteLaser;
};