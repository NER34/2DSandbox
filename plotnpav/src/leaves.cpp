#include "leaves.h"

using namespace std;

//--------------------------------Leaves

Leaves::Leaves(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/Leaves.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = true;
	drop_id = 5;
}

Leaves::~Leaves()
{
	SDL_DestroyTexture(texture);
}

bool Leaves::Physics(shared_ptr<Map> & map, int x, int y)
{
	bool can = false;
	for (int j = -1; j <= 1; j++)
		if (x + j != 0 && x + j != x_size)
			for (int i = -1; i <= 1; i++)
				if (!(i == -1 && y == 0) && !(i == 1 && y == y_size))
					if (!(i == 0 && j == 0))
						if (map->map[y + i][x + j] == 4 || map->map[y + i][x + j] == 8) // if exist any leaves or wood block around this block
							can = true;
	if (!can) // if not exist any leaves or wood block around this block
		map->map[y][x] = 0;
	return true;
}

bool Leaves::DestroyIt(shared_ptr<Map> & map, Player * player, int x, int y)
{
	if (rand() % 4 == 0)
		player->GetInventory()->PasteToInventory(drop_id, 1);
	map->map[y][x] = 0;
	return true;
}
