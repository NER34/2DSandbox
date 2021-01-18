#ifndef MOUSE
#define MOUSE
#include <vector>
#include <SDL2/SDL.h>
#include <fstream>
/**
* Presen mouse on the screen.
*/
class Mouse
{
public:
	/**
	* Constructor initialize mouse class(coordinates and texture).
	*
	* @param[in] ren Renderer;
	*/
	Mouse(SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~Mouse();
	/**
	* @return Returns texture.
	*/
	SDL_Texture * GetTexture() const;
	/**
	* @return Returns coordinates.
	*/
	SDL_Rect * GetRect() const;
	int timer;
private:
	SDL_Texture * tex;
	SDL_Rect * coor;
};
#endif