using namespace std;

#include"mouse.h"

Mouse::Mouse(SDL_Renderer * ren)
{
	SDL_Surface * sur = SDL_LoadBMP("src/texture/items/Empty.bmp");
	tex = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	coor = new SDL_Rect;
	coor->x = 0;
	coor->y = 0;
	coor->h = 40;
	coor->w = 40;
	timer = 0;
}

Mouse::~Mouse()
{
	SDL_DestroyTexture(tex);
	delete coor;
}

SDL_Texture * Mouse::GetTexture() const
{
	return tex;
}

SDL_Rect * Mouse::GetRect() const
{
	return coor;
}
