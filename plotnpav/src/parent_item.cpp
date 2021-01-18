using namespace std;

#include "parent_item.h"

//---------------------------------Item
Item::~Item()
{
	SDL_DestroyTexture(tex);
}

SDL_Texture * Item::GetTexture() const
{
	return tex;
}