using namespace std;

#include "ifishing_row.h"

//---------------------------------IFishingRow
IFishingRow::IFishingRow(SDL_Renderer * ren, const char * str, int id)
{
	SDL_Surface * sur = SDL_LoadBMP(str);
	tex = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	num = id;
}

void IFishingRow::Using(shared_ptr<Map> & map, Player * player, int x, int y, bool tang)
{
	if (map->map[y][x] == num)
	{
		if ((rand() % 3) == 0)
		{
			player->GetInventory()->DelFromInventory(1);
			player->GetInventory()->PasteToInventory(3, 1);
		}
	}
}
