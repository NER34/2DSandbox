#include "grass.h"

using namespace std;

//--------------------------------Grass

Grass::~Grass() { SDL_DestroyTexture(texture); }

bool Grass::Physics(shared_ptr<Map> & map, int x, int y)
{
	if (y != 0) // if the block is not in the first row
		if (map->map[y - 1][x]) // if there is nothing above this block
			map->map[y][x] = 1; // change the block from the grass block to the dirt block
	return true;
}

Grass::Grass(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/GrassTexture.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = true;
	drop_id = 0;
}
