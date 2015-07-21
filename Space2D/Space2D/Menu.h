#ifndef MENU_H
#define MENU_H

#include "StateManager.h"

class Menu : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);
};
#endif