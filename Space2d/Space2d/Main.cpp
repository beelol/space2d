#include <vector>
#include <iostream>
#include  <SFML\Graphics.hpp>
#include "StateManager.h" //Custom
#include "IOScreen.h" //Custom
#include "Menu.h" //Custom
#include "Game.h" //Custom
#include "Lobby.h" //Custom
#include "Settings.h" //Custom

int main()
{
	//StateManager IDs
	std::vector<StateManager*> states;
	int screenState = 0;

	//create window
	IOScreen ioscreen;
	sf::RenderWindow window;
	window.setFramerateLimit(60);

	if (!ioscreen.getScreenSettings())
	{
		window.create(sf::VideoMode(1920, 1080, 32), "Space2D", sf::Style::Fullscreen);
		window.setMouseCursorVisible(false);
	}
	else
	{
		window.create(sf::VideoMode(1920, 1080, 32), "Space2D", sf::Style::Default);
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
	//	if ()
	//	{
	//	}

		//main loop
		screenState = states[screenState]->Run(window);
	}
	return 0;
}