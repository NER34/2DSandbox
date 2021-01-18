#include <string>
#include <fstream>

using namespace std;

#include "game.h"

Game::Game(istream & in, SDL_Renderer * ren)
{
	// map initialisation
	int time;
	in >> time;
	initmap = make_shared<Map>(CreateMap(in), time, ren);

	// blocks initialisation
	blocks_type.push_back(make_shared<Air>(initmap->ren));// id = 0
	blocks_type.push_back(make_shared<Dirt>(initmap->ren));// id = 1
	blocks_type.push_back(make_shared<Grass>(initmap->ren));// id = 2
	blocks_type.push_back(make_shared<Stone>(initmap->ren));// id = 3
	blocks_type.push_back(make_shared<Wood>(initmap->ren));// id = 4
	blocks_type.push_back(make_shared<Water>(initmap->ren));// id = 5
	blocks_type.push_back(make_shared<Lava>(initmap->ren));// id = 6
	blocks_type.push_back(make_shared<Tree>(in, initmap->ren));// id = 7
	blocks_type.push_back(make_shared<Leaves>(initmap->ren));// id = 8
	blocks_type.push_back(make_shared<RunWater>(initmap->ren));// id = 9
	blocks_type.push_back(make_shared< RunWater1>(initmap->ren));// id = 10
	blocks_type.push_back(make_shared< RunWater2>(initmap->ren));// id = 11
	blocks_type.push_back(make_shared< RunLava>(initmap->ren));// id = 12
	blocks_type.push_back(make_shared< RunLava1>(initmap->ren));// id = 13
	blocks_type.push_back(make_shared< RunLava2>(initmap->ren));// id = 14

	// items initialisation
	items_type.push_back(make_shared<IBlock>(initmap->ren, "src/texture/blocks/DirtTexture.bmp", 1));// id = 0 dirt
	items_type.push_back(make_shared<IBlock>(initmap->ren, "src/texture/blocks/StoneTexture.bmp", 3));// id = 1 stone
	items_type.push_back(make_shared<IFishingRow>(initmap->ren, "src/texture/items/FishRod.bmp", 5));// id = 2 fishing row
	items_type.push_back(make_shared<IFood>(initmap->ren, "src/texture/items/Fish.bmp", 5));// id = 3 fish
	items_type.push_back(make_shared<IBlock>(initmap->ren, "src/texture/blocks/WoodTexture.bmp", 4));// id = 4 wood
	items_type.push_back(make_shared<ITree>(initmap->ren, "src/texture/items/Tree.bmp", 7));// id = 5 tree
	items_type.push_back(make_shared<IBlock>(initmap->ren, "src/texture/items/Water.bmp", 5));// id = 6 bucket of water
	items_type.push_back(make_shared<IBlock>(initmap->ren, "src/texture/items/Lava.bmp", 6));// id = 7 bucket of lava

	// player initialisation
	player = make_shared<Player>(in, initmap->ren);
	// enemies initialisation
	int num;
	in >> num;
	for (int i = 0; i < num; i++)
	{
		int x, y, hp;
		in >> x >> y >> hp;
		enemies.push_back(make_shared<Enemy>(initmap->ren, x, y, hp));
	}

	endGame = false;

	inv = true; // for showing/hiding of inventory and hp_bar
}

vector<vector<int> > Game::CreateMap(istream & in)
{
	vector<vector<int> > map;
	for (int j = 0; j < y_size; j++)
	{
		vector<int> tmp;
		for (int i = 0; i < x_size; i++)
		{
			int id;
			in >> id; // reading of map from save file to the array
			tmp.push_back(id);
		}
		map.push_back(tmp);
	}
	return map;
}

void Game::End(const string & name) // saving of all components
{
	ofstream out(name);

	out << 1 << endl; // valid number

	initmap->Save(out); // saving of the map

	for (auto it = blocks_type.begin(); it != blocks_type.end(); it++)
		(*it)->Save(out);

	player->Save(out); // saving of the player
	
	// saving of enemies
	out << enemies.size() << endl;

	auto it = enemies.begin();
	if (it != enemies.end()) {
		(*it)->Save(out);
		it++;
	}
	for (; it != enemies.end(); it++)
	{
		out << " ";
		(*it)->Save(out);
	}
	out << endl;

	out.close();
}

void Game::Draw()
{
	SDL_RenderClear(initmap->ren);
	DrawMap();
	DrawPerson(player);
	if (initmap->time > 7500)
		EnemySpown();
	for (auto it = enemies.begin(); it != enemies.end(); it++)
		DrawPerson(*it);
	DrawMouse();
	if (inv)
		DrawPlayerInfo();
	SDL_RenderPresent(initmap->ren);
}

void Game::Move()
{
	MovePlayer();
	MoveEnemies();
}

void Game::WClick() // Left button of mouse 
{
	Player * plr = ((Player *)player.get());
	int x = plr->GetMouse()->GetRect()->x / 40;
	int y = plr->GetMouse()->GetRect()->y / 40;
	int x1 = player->GetRect()->x / 40;
	int y1 = player->GetRect()->y / 40;
	int block_id = initmap->map[y][x];
	if ((x >= x1 - 2 && x <= x1 + 2) && (y >= y1 - 2 && y <= y1 + 3)) // if mouse is near the player
		if (!blocks_type[block_id]->DestroyIt(initmap, plr, x, y)) // if block can't be destroyed
			for (auto it = enemies.begin(); it != enemies.end(); it++)
			{
				x1 = (*it)->GetRect()->x / 40;
				y1 = (*it)->GetRect()->y / 40;
				if (x1 == x && (y1 == y || y1 + 1 == y))
					(*it)->TakeDamage(player->GetDamage());
			}

}

void Game::SClick() // Right button of mouse
{
	Player * plr = ((Player *)player.get());
	int x = plr->GetMouse()->GetRect()->x / 40;
	int y = plr->GetMouse()->GetRect()->y / 40;
	int x1 = plr->GetRect()->x / 40;
	int y1 = plr->GetRect()->y / 40;
	int block_id = initmap->map[y][x];
	int id = plr->GetInventory()->GetItemID(plr->GetInventory()->GetActiveSlot());
	if (x >= x1 - 2 && x <= x1 + 2 && y >= y1 - 2 && y <= y1 + 3 && !(x == x1 && (y == y1 || y == (y1 + 1)))) // if mouse is near the player but not inside
		if (!blocks_type[block_id]->Using(initmap, plr, x, y)) // if you can't use this block
			if (id > -1) // if there is something in active slot
				items_type[id]->Using(initmap, plr, x, y, blocks_type[block_id]->GetTangibility());
}

void Game::EnemySpown()
{
	if (enemies.size() < 4)
	{
		int x = rand() % x_size;
		int y = rand() % y_size;
		if (y <= 13)
			if (blocks_type[initmap->map[y + 2][x]]->GetTangibility())
				if (!blocks_type[initmap->map[y + 1][x]]->GetTangibility())
					if (!blocks_type[initmap->map[y][x]]->GetTangibility())
						if (!(rand() % 4))
							enemies.push_back(make_shared<Enemy>(initmap->ren, x, y, 100));
	}
}