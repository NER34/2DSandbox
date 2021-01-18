#include "tree.h"

using namespace std;

//--------------------------------Tree

Tree::Tree(istream & out, SDL_Renderer * ren)
{
	time = new SDL_Texture *[4];
	SDL_Surface * sur = SDL_LoadBMP("src/texture/blocks/MorningTree.bmp");
	time[0] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/blocks/DayTree.bmp");
	time[1] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/blocks/EveningTree.bmp");
	time[2] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/blocks/NightTree.bmp");
	time[3] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	tang = true;
	drop_id = 5;

	int num;
	out >> num; // read characteristics from save file
	for (int i = 0; i < num; i++)
	{
		int x, y, t;
		out >> x >> y >> t;
		trees.insert(make_pair(make_pair(x, y), t));
	}
}

Tree::~Tree()
{
	for (int i = 0; i < 4; i++)
		SDL_DestroyTexture(time[i]);
	delete[] time;
}

bool Tree::Physics(shared_ptr<Map> & map, int x, int y)
{
	texture = time[map->time / 2500];
	auto it = trees.find(make_pair(x, y));
	if (it == trees.end()) // if the tree does not exist in this map
		trees.insert(make_pair(make_pair(x, y), 0));
	else
	{
		if (y != y_size - 1) { // if the block is not in the last row
			if (map->map[y + 1][x] != 1 && map->map[y + 1][x] != 2) { // if there is no dirt (grass) block under this block
				trees.erase(it);
				map->map[y][x] = 0;
			}
			else if (it->second == 1000) // if the tree has grown (4 - wood block, 8 - leaves block)
			{
				map->map[y][x] = 4;
				if (y > 0)
					map->map[y - 1][x] = 4;
				if (y - 1 > 0) {
					map->map[y - 2][x] = 4;
					map->map[y - 2][x - 1] = 8;
					map->map[y - 2][x + 1] = 8;
				}
				if (y - 2 > 0) {
					map->map[y - 3][x] = 4;
					if (x > 0)
						map->map[y - 3][x - 1] = 8;
					if (x < x_size - 1)
						map->map[y - 3][x + 1] = 8;
				}
				if (y - 3 > 0) {
					if (x > 0)
						map->map[y - 4][x - 1] = 8;
					if (x < x_size - 1)
						map->map[y - 4][x + 1] = 8;
					map->map[y - 4][x] = 8;
				}
				trees.erase(it);
			}
			else
				it->second += 1;
		}
	}
	return true;
}

void Tree::Save(ostream & out) // write trees characteristics to the save file
{
	out << trees.size() << endl;
	auto it = trees.begin();
	if (it != trees.end()) {
		out << it->first.first << " " << it->first.second << it->second;
		it++;
		for (; it != trees.end(); it++)
			out << " " << it->first.first << " " << it->first.second << it->second;
		out << endl;
		trees.clear();
	}

}
