#include "run_lava2.h"

using namespace std;

//--------------------------------RunLava2

RunLava2::RunLava2(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/lava3.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = false;
	drop_id = -1;
}

RunLava2::~RunLava2()
{
	SDL_DestroyTexture(texture);
}

bool RunLava2::Physics(shared_ptr<Map> & map, int x, int y)
{
	if (x != x_size - 1) { // if the block is not in the last column
		if (map->map[y][x + 1] != 6 && map->map[y][x + 1] != 12) // if there is no (falling) lava block to the right of this block
			map->map[y][x] = 0; // destroy this block
	}
	else
		map->map[y][x] = 0; // destroy this block

	if (y != y_size - 1) // if the block is not in the last row
		if (map->map[y + 1][x] == 0) // if there is nothing under this block
			map->map[y + 1][x] = 12; // create falling lava block under this block
	return true;
}

bool RunLava2::DestroyIt(shared_ptr<Map> & map, Player * player, int x, int y) { return false; }
