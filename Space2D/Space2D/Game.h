#ifndef GAME_H
#define GAME_H

#include "StateManager.h"
//#include "Ship.h"
#include "Barricade.h" // incudes Ship.h
class Game : public StateManager
{

public:
	virtual int Run(sf::RenderWindow &window);

private:
	sf::Event event;
	
	float m_ShipPosX;
	float m_ShipPosY;
	float ShipVertAccel;//vert accel
	float ShipHorzAccel;//Horz accel
	float ShipDecelVert;//           Vert decel
	float ShipDecelHorz;//           Horz Decel
	float ShipSpeedVert;//speed vert
	float ShipSpeedHorz;//speed horz

	int m_PlayerID;
	int m_team;
	int m_ShipsInGame = 0;

	bool running;
	bool WPressed;//w
	bool APressed;//a
	bool SPressed;//s
	bool DPressed;//d
	bool CPressed;//c
	bool m_SpawnLaser;

	std::vector<Ship*> Ships;
	std::vector<Ship*> Lasers;
};
#endif