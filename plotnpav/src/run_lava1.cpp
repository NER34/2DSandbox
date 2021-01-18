#include "run_lava1.h"

using namespace std;

//--------------------------------RunLava1

RunLava1::RunLava1(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/Lava2.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = false;
	drop_id = -1;
}

RunLava1::~RunLava1()
{
	SDL_DestroyTexture(texture);
}

bool RunLava1::Physics(shared_ptr<Map> & map, int x, int y)
{
	if (x != 0) { // if the block is not in the first column
		if (map->map[y][x - 1] != 6 && map->map[y][x - 1] != 12) // if there is no (falling) lava blockto the left of this block
			map->map[y][x] = 0; // destroy this block
	}
	else
		map->map[y][x] = 0; // destroy this block

	if (y != y_size - 1) // if the block is not in the last row
		if (map->map[y + 1][x] == 0) // if there is nothing under this block
			map->map[y + 1][x] = 12; // create falling lava block under this block
	return true;
}

bool RunLava1::DestroyIt(shared_ptr<Map> & map, Player * player, int x, int y)
{
	return false;
}
