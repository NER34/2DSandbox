#include<SDL2/SDL.h>
#include<iostream>
#include<memory>
#include<fstream>

using namespace std;

#include "game.h"


void Game::DrawMap()
{
	initmap->time++;
	if (initmap->time == 10000)
		initmap->time = 0;
	SDL_Rect RECT;
	RECT.h = 40;
	RECT.w = 40;
	for (int j = 0; j < y_size; j++)
	{
		RECT.y = (j * 40);
		for (int i = 0; i < x_size; i++)
		{
			int x = initmap->map[j][i];
			RECT.x = (i * 40);
			blocks_type[x]->Physics(initmap, i, j);
			//cout << blocks_type[x]->GetTexture() << endl;
			SDL_RenderCopy(initmap->ren, blocks_type[x]->GetTexture(), NULL, &RECT);
		}
	}
}

void Game::DrawPerson(shared_ptr<Person> & pers)
{
	int x = pers->GetRect()->x / 40;
	int y = pers->GetRect()->y / 40;
	if (y < y_size - 2)
		pers->Physics(initmap->map, blocks_type[initmap->map[y + 2][x]]->GetTangibility(), x, y, initmap->ren);
	else
		pers->TakeDamage(100);
	pers->Time(initmap->time / 2500);
	SDL_RenderCopy(initmap->ren, pers->GetTexture(), NULL, pers->GetRect());

}

void Game::DrawMouse()
{
	Player * plr = ((Player *)player.get());
	if (plr->GetMouse()->timer == -25)
	{
		plr->GetMouse()->timer = 25;
	}
	else
	{
		if (plr->GetMouse()->timer <= 0)
		{
			int x = plr->GetInventory()->GetItemID(plr->GetInventory()->GetActiveSlot());
			if (x >= 0)
				SDL_RenderCopy(initmap->ren, items_type[x]->GetTexture(), NULL, plr->GetMouse()->GetRect());
			else
				SDL_RenderCopy(initmap->ren, plr->GetMouse()->GetTexture(), NULL, plr->GetMouse()->GetRect());
			//cout << "Mouse was drawn" << endl;
		}
		plr->GetMouse()->timer--;
	}
}

void Game::DrawPlayerInfo()
{
	Player * plr = ((Player *)player.get());
	//-----------------------------------------Inventory
	plr->GetInventory()->DrawInventory(initmap->ren);
	for (int i = 0; i < plr->GetInventory()->GetInventorySize(); i++)
	{
		int x = plr->GetInventory()->GetItemID(i);
		if (x >= 0)
			plr->GetInventory()->DrawSlot(initmap->ren, i, items_type[x]->GetTexture());
	}
	//cout << "Inventory wa drawn" << endl;
	//-----------------------------------------HPBar
	plr->DrawHPBar(initmap->ren);
}