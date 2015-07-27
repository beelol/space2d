#include "IOScreen.h"
#include <fstream>

bool IOScreen::getFullScreen()
{
	std::ifstream readInFile;
	readInFile.open("stuff//screenSettings.txt", std::ios::in);
	bool temp;
	readInFile >> temp;
	readInFile.close();
	return temp;
}
