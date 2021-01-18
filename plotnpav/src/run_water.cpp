#include "run_water.h"

using namespace std;

//--------------------------------RunWater

RunWater::RunWater(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/Water2.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = false;
	drop_id = -1;
}

RunWater::~RunWater()
{
	SDL_DestroyTexture(texture);
}

bool RunWater::Physics(shared_ptr<Map> & map, int x, int y)
{
	if (y != 0) { //if the block is not in the first row
		if (map->map[y - 1][x] != 5 && map->map[y - 1][x] != 9 && map->map[y - 1][x] != 10 && map->map[y - 1][x] != 11)  // if there is no water blocks above this block
			map->map[y][x] = 0; // destroy this water block
	}
	else
		map->map[y][x] = 0; // destroy this water block

	if (y != y_size - 1) //if the block is not in the last row
	{
		if (map->map[y + 1][x] == 0 || map->map[y + 1][x] == 10 || map->map[y + 1][x] == 11) // if there is nothing under this block or there is run water block (to the left or right)
			map->map[y + 1][x] = 9; // create falling water
		else if (map->map[y + 1][x] != 5 && map->map[y + 1][x] != 9) // if there is any block except air and water
		{
			if (x != x_size - 1) // if the block is not in the last column
				if (map->map[y][x + 1] == 0) // if there is nothing to the right of this block
					map->map[y][x + 1] = 10; // create run water (to the right)
			if (x != 0) // if the block is not in the first column
				if (map->map[y][x - 1] == 0) // if there is nothing to the left of this block
					map->map[y][x - 1] = 11; // create run water (to the left)
		}
	}
	return true;
}

bool RunWater::DestroyIt(shared_ptr<Map> & map, Player * player, int x, int y)
{
	return false;
}
