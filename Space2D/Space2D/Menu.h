#ifndef MENU_H
#define MENU_H

#include "StateManager.h"

class Menu : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);

private:
	sf::Event event;
	bool running;
	sf::Vector2i mPosition;
};

#endif