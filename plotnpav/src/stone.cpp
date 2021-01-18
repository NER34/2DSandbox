#include "stone.h"

using namespace std;

//--------------------------------Stone

Stone::~Stone() { SDL_DestroyTexture(texture); }

Stone::Stone(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/StoneTexture.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = true;
	drop_id = 1;
}
