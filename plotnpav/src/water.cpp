#include "water.h"

using namespace std;

//--------------------------------Water

Water::~Water() { SDL_DestroyTexture(texture); }

bool Water::Physics(shared_ptr<Map> & map, int x, int y)
{
	if (y != y_size - 1) { //if the block is not in the last row
		if (map->map[y + 1][x] == 0) // if there is nothing under this block
			map->map[y + 1][x] = 9; // create falling water
		else {
			if (x != 0) // if the block is not in the first column
				if (map->map[y][x - 1] == 0) // if there is nothing to the left of this block
					map->map[y][x - 1] = 11; // create run water (to the left)
			if (x != x_size - 1) // if the block is not in the last column
				if (map->map[y][x + 1] == 0) // if there is nothing to the right of this block
					map->map[y][x + 1] = 10;// create run water (to the right)
		}
	}
	return true;
}

Water::Water(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/WaterTexture.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = false;
	drop_id = 6;
}
