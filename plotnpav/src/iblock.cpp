using namespace std;

#include "iblock.h"

//---------------------------------IBlock
IBlock::IBlock(SDL_Renderer * ren, const char * str, int id)
{
	SDL_Surface * sur = SDL_LoadBMP(str);
	tex = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	num = id;
}

void IBlock::Using(shared_ptr<Map> & map, Player * player, int x, int y, bool tang)
{
	if (!tang)
		if (player->GetInventory()->DelFromInventory(1))
			map->map[y][x] = num;
}
