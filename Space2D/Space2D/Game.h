#ifndef GAME_H
#define GAME_H

#include "StateManager.h"

class Game : public StateManager
{

public:
	virtual int Run(sf::RenderWindow &window);

private:
	sf::Event event;
	
	float ShipVertAccel;
	float ShipHorzAccel;
	float ShipDecelVert;
	float ShipDecelHorz;
	float ShipSpeedVert;
	float ShipSpeedHorz;

	bool running;
	bool WPressed;
	bool APressed;
	bool SPressed;
	bool DPressed;
	bool m_SpawnLaser;
};
#endif