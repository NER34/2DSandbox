#include <iostream>
#include <SDL2/SDL.h>
#include <fstream>

using namespace std;

#include "menu.h"



#undef main


int main(int argc, char * argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return 1; // Inicialization Failed
	
	Menu * menu = new Menu;
	menu->MainMenu();
	delete menu;
	return 0;
}
