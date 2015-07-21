#ifndef SETTINGS_H
#define SETTINGS_H

#include "StateManager.h"

class Settings : public StateManager
{
public:
	virtual int Run(sf::RenderWindow &window);
};

#endif