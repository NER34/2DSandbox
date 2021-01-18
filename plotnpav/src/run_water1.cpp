#include "run_water1.h"

using namespace std;

//--------------------------------RunWater1 // (to the right)

RunWater1::RunWater1(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/Water3.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = false;
	drop_id = -1;
}

RunWater1::~RunWater1()
{
	SDL_DestroyTexture(texture);
}

bool RunWater1::Physics(shared_ptr<Map> & map, int x, int y)
{
	if (x != 0) { // if the block is not in the first column
		if (map->map[y][x - 1] != 5 && map->map[y][x - 1] != 9) // if there is no (falling) water block to the left of this block
			map->map[y][x] = 0; // destroy this run water block
	}
	else
		map->map[y][x] = 0; // destroy this run water block

	if (y != y_size - 1) // if the block is not in the last row
		if (map->map[y + 1][x] == 0 || map->map[y + 1][x] == 10 || map->map[y + 1][x] == 11) // if there are no blocks or there is run water block under this block 
			map->map[y + 1][x] = 9; // create falling water block
	return true;
}

bool RunWater1::DestroyIt(shared_ptr<Map> & map, Player * player, int x, int y)
{
	return false;
}
