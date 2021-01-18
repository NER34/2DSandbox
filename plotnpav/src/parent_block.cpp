#include "parent_block.h"

using namespace std;

//--------------------------------Block

SDL_Texture * Block::GetTexture() const { return texture; }

bool Block::GetTangibility() const { return tang; }

int Block::GetDropID() const { return drop_id; }

bool Block::DestroyIt(shared_ptr<Map> & map, Player * player, int x, int y)
{
	if (player->GetInventory()->PasteToInventory(drop_id, 1))
		map->map[y][x] = 0;
	return true;
}

