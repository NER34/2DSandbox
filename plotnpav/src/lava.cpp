#include "lava.h"

using namespace std;

//--------------------------------Lava

Lava::~Lava() { SDL_DestroyTexture(texture); }

bool Lava::Physics(shared_ptr<Map> & map, int x, int y)
{
	if (y != y_size - 1) { // if the block is not in the last row
		if (map->map[y + 1][x] == 0) // if there is nothing under this block
			map->map[y + 1][x] = 12; // create falling lava
		else {
			if (x != 0) // if the block is not in the first column
				if (map->map[y][x - 1] == 0) // if there is nothing to the left of this block
					map->map[y][x - 1] = 14; // create run lava (to the left)
			if (x != x_size - 1) // if the block is not in the last column
				if (map->map[y][x + 1] == 0) // if there is nothing to the right of this block
					map->map[y][x + 1] = 13; // create run lava (to the right)
		}
	}
	return true;
}

Lava::Lava(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/LavaTexture.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = false;
	drop_id = 7;
}
