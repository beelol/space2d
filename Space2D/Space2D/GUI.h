#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

	class Background
	{
	public:
		Background(std::string filepath);
		void Render(sf::RenderWindow &window);
	private:
		sf::Texture bgTex;
		sf::Sprite  bgSprite;
	};

#endif