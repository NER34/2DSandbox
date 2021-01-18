using namespace std;

#include "ifood.h"

//---------------------------------IFood
IFood::IFood(SDL_Renderer * ren, const char * str, int tmpnum)
{
	SDL_Surface * sur = SDL_LoadBMP(str);
	tex = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	num = tmpnum;
}

void IFood::Using(shared_ptr<Map> & map, Player * player, int x, int y, bool tang)
{
	player->TakeDamage(-num);
	player->GetInventory()->DelFromInventory(1);
}
