#include <vector>
#include <iostream>
#include  <SFML\Graphics.hpp>

#include "StateManager.h" 
#include "IOScreen.h" 
#include "Menu.h" 
#include "Game.h" 
#include "Lobby.h" 
#include "Settings.h" 

int main()
{
	//StateManager IDs
	std::vector<StateManager*> states;
	int screenState = 0;

	//create window
	IOScreen ioscreen;
	sf::RenderWindow window;

	if (!ioscreen.getFullScreen())
	{
		window.create(sf::VideoMode(1280, 720, 32), "Space2D", sf::Style::Fullscreen);
		window.setMouseCursorVisible(false);
	}
	else
	{
		window.create(sf::VideoMode(1280, 720, 32), "Space2D", sf::Style::Default);
	}

	//states
	Menu MenuS0;
	states.push_back(&MenuS0);
	Settings SettingsS1;
	states.push_back(&SettingsS1);
	Lobby LobbyS2;
	states.push_back(&LobbyS2);
	Game GameS3;
	states.push_back(&GameS3);
	//GraphicSet state4;
	//states.push_back(&state4);

	while (screenState >= 0)
	{
		//when screen changes
		//DO STUFF

		//main loop
		screenState = states[screenState]->Run(window);
	}
	return 0;
}