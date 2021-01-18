#ifndef MENU
#define MENU
#include <string>
#include <SDL2/SDL.h>

#include "game.h"

/**
* Presents games menu with all its functions.
*/
class Menu
{
public:
	/**
	* Constructor initialize menu(renderer, window and textures).
	*/
	Menu();
	/**
	* Destructor.
	*/
	~Menu();
	/**
	* This method draws main menu.
	*
	* @param[in] fun Presents selected function("New Game", "Continue" or "Exit");
	*/
	void DrawMainMenu(int fun);
	/**
	* This method presents main menu.
	*/
	void MainMenu();
	/**
	* This method draws saving menu.
	*
	* @param[in] fun Presents selected saving;
	*/
	void DrawSelectSaving(int fun);
	/**
	* This method presents saving menu.
	*
	* @return Returns number of selected saving.
	*/
	std::string SelectSaving();
private:
	enum { NEW_GAME, CONTINUE, EXIT, SAVING_1, SAVING_2, SAVING_3 };
	SDL_Texture ** textures;
	SDL_Renderer * ren;
	SDL_Window * win;
	Game * game;
};
#endif
