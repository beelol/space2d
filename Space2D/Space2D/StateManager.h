#include <SFML\Graphics.hpp>

class StateManager
{
public:
	virtual int Run(sf::RenderWindow &window) = 0;
};

