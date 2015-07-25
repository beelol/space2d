#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
	
	//Background
	class Background
	{
	public:
		Background(std::string filepath);
		void Render(sf::RenderWindow &window);
	private:
		sf::Texture bgTex;
		sf::Sprite  bgSprite;
	};

	//menu graphics
	class MenuGraphics// : public Menu
	{
	public:

		MenuGraphics();
		void Render(sf::RenderWindow &window);
		int CheckClick(int x, int y);
	private:
		
		sf::Texture MStartTex;//start button tex
		sf::Texture MOptionsTex;//option button tex
		sf::Texture MExitTex;//exit button tex

		sf::Sprite StartSprite;//Button start sprite
		sf::Sprite OptionsSprite;//Button Options sprite
		sf::Sprite ExtSprite;//Button Exit sprite
	};
#endif