#include "run_lava.h"

using namespace std;

//--------------------------------RunLava

RunLava::RunLava(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/Lava1.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = false;
	drop_id = -1;
}

RunLava::~RunLava()
{
	SDL_DestroyTexture(texture);
}

bool RunLava::Physics(shared_ptr<Map> & map, int x, int y)
{
	if (y != 0) { //if the block is not in the first row 
		if (map->map[y - 1][x] != 6 && map->map[y - 1][x] != 12 && map->map[y - 1][x] != 13 && map->map[y - 1][x] != 14) // if there are no lava blocks above this block
			map->map[y][x] = 0; // destroy this falling lava block
	}
	else
		map->map[y][x] = 0; // destroy this block

	if (y != y_size - 1) // if the block is not in the last row
	{
		if (map->map[y + 1][x] == 0 || map->map[y + 1][x] == 13 || map->map[y + 1][x] == 14) // if there is nothing under this block or there are run lava blocks 
			map->map[y + 1][x] = 12; // create falling lava block under this block
		else if (map->map[y + 1][x] != 6 && map->map[y + 1][x] != 12) // if there is something except lava blocks under this block
		{
			if (x != x_size - 1) // if the block is not in the last column
				if (map->map[y][x + 1] == 0) // if there is nothing to the right of this block
					map->map[y][x + 1] = 13; // create run(to the right) lava block to the right of this block
			if (x != 0) // if the block is not in the first column
				if (map->map[y][x - 1] == 0) // if there is nothing to the left of this block
					map->map[y][x - 1] = 14; // create run(to the left) lava block to the left of this block
		}
	}
	return true;
}

bool RunLava::DestroyIt(shared_ptr<Map> & map, Player * player, int x, int y)
{
	return false;
}
