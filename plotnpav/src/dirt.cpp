using namespace std;

#include "dirt.h"

//--------------------------------Dirt

Dirt::~Dirt() { SDL_DestroyTexture(texture); }

bool Dirt::Physics(shared_ptr<Map> & map, int x, int y)
{
	int j = -1;
	if (y != 0)
		if (map->map[y - 1][x] == 0) // if there is nothing above
		{
			if (x != 0)
				for (int i = -1; i <= 1; i++)
					if (map->map[y + i][x + j] == 2) // and there is grass nearly
						map->map[y][x] = 2; // will grow on this block
			j = 1;
			if (x != x_size - 1)
				for (int i = -1; i <= 1; i++)
					if (map->map[y + i][x + j] == 2)
						map->map[y][x] = 2;
		}
	return true;
}

Dirt::Dirt(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/DirtTexture.bmp");
	texture = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = true;
	drop_id = 0;
}
