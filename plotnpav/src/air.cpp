#include "air.h"

using namespace std;

//--------------------------------Air

Air::~Air()
{
	for (int i = 0; i < 4; i++)
		SDL_DestroyTexture(time[i]);
	delete[] time;
}

bool Air::Physics(shared_ptr<Map> & map, int x, int y)
{
	texture = time[map->time / 2500]; //texture depends on time
	return true;
}

Air::Air(SDL_Renderer * ren)
{
	SDL_Surface * sur;
	time = new SDL_Texture *[4];
	sur = SDL_LoadBMP("src/texture/backgrounds/Morning.bmp");
	time[0] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/backgrounds/Day.bmp");
	time[1] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/backgrounds/Evening.bmp");
	time[2] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/backgrounds/Night.bmp");
	time[3] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = false;
	drop_id = -1;
}

bool Air::DestroyIt(shared_ptr<Map> & map, Player * player, int x, int y) { return false; }

