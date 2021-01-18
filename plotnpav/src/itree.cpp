using namespace std;

#include "itree.h"

//---------------------------------ITree
ITree::ITree(SDL_Renderer * ren, const char * str, int id)
{
	SDL_Surface * sur = SDL_LoadBMP(str);
	tex = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	num = id;
}

void ITree::Using(shared_ptr<Map> & map, Player * player, int x, int y, bool tang)
{
	if (map->map[y][x] == 0)
		if (y != y_size - 1)
			if (map->map[y + 1][x] == 1 || map->map[y + 1][x] == 2)
				if (player->GetInventory()->DelFromInventory(1))
					map->map[y][x] = num;
}
