#ifndef LOBBY_H
#define LOBBY_H

#include "StateManager.h"

class Lobby : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);

private:
	//sf::Event event;
	//bool running;
};
#endif