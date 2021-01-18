#include "wood.h"

using namespace std;

//--------------------------------Wood

Wood::~Wood() { SDL_DestroyTexture(texture); }

Wood::Wood(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/WoodTexture.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = true;
	drop_id = 4;
}
