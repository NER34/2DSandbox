#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>

using namespace std;

#include "map.h"

Map::Map(std::vector<std::vector<int> > tmp, int t, SDL_Renderer * tmpren)
{
	ren = tmpren;
	if (ren != NULL)
		cout << "Renderer was loaded" << endl;
	map = tmp;

	time = t;
}

void Map::Save(ostream & out)
{
	out << time << endl;
	for (unsigned i = 0; i < map.size(); i++) {
		out << map[i][0];
		for (unsigned j = 1; j < map[i].size(); j++)
			out << " " << map[i][j];
		out << endl;
	}
}