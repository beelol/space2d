#ifndef GAME_H
#define GAME_H

#include "StateManager.h"

class Game : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);

};
#endif