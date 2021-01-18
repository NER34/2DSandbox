#include<SDL2/SDL.h>
#include<queue>
#include<map>

using namespace std;

#include "game.h"

bool Game::MovePersonRightLeft(bool right, shared_ptr<Person> & pers)
{
	int x = (pers->GetRect()->x) / 40;
	int y = (pers->GetRect()->y + 80) / 40;
	if (right && x != 31) // if the person is moving to the right and not in the last column 
	{
		if (!(!(pers->GetRect()->x % 40) && (blocks_type[initmap->map[y - 2][x + 1]]->GetTangibility() || blocks_type[initmap->map[y - 1][x + 1]]->GetTangibility()))) // id there is nothing to the right of person
		{
			pers->MoveX(true);
			return true;
		}
		return false;
	}
	else if (x != 0 && !right) // if the person is moving to the left and not in the first column 
	{
		if (!(!(pers->GetRect()->x % 40) && (blocks_type[initmap->map[y - 2][x - 1]]->GetTangibility() || blocks_type[initmap->map[y - 1][x - 1]]->GetTangibility()))) // id there is nothing to the left of person
		{
			pers->MoveX(false);
			return true;
		}
		return false;
	}
	return false;
}

void Game::MovePersonJump(shared_ptr<Person> & pers)
{
	int x = (pers->GetRect()->x) / 40;
	int y = (pers->GetRect()->y + 80) / 40;

	if (y > 2) // person cant jump from the third row
	{
		if (pers->GetKoef() == 0 && blocks_type[initmap->map[y][x]]->GetTangibility()) // if you standing on the ground
		{
			if (blocks_type[initmap->map[y - 3][x]]->GetTangibility()) // if something above  a person
				pers->MoveY(2);
			else
				pers->MoveY(8);
		}
	}
	else
		pers->MoveY(0);

}

void Game::MovePlayer()
{
	Player * plr = ((Player *)player.get());
	if (player->Dead())
		plr->ReSpawn(initmap->map, x_size, y_size);
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			endGame = true;
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_d)
				MovePersonRightLeft(true, player);
			if (e.key.keysym.sym == SDLK_a)
				MovePersonRightLeft(false, player);
			if (e.key.keysym.sym == SDLK_SPACE)
				MovePersonJump(player);
			if (e.key.keysym.sym == SDLK_1)
				plr->GetInventory()->SetActiveSlot(0);
			if (e.key.keysym.sym == SDLK_2)
				plr->GetInventory()->SetActiveSlot(1);
			if (e.key.keysym.sym == SDLK_3)
				plr->GetInventory()->SetActiveSlot(2);
			if (e.key.keysym.sym == SDLK_4)
				plr->GetInventory()->SetActiveSlot(3);
			if (e.key.keysym.sym == SDLK_5)
				plr->GetInventory()->SetActiveSlot(4);
			if (e.key.keysym.sym == SDLK_6)
				plr->GetInventory()->SetActiveSlot(5);
			if (e.key.keysym.sym == SDLK_7)
				plr->GetInventory()->SetActiveSlot(6);
			if (e.key.keysym.sym == SDLK_8)
				plr->GetInventory()->SetActiveSlot(7);
			if (e.key.keysym.sym == SDLK_i)
				inv = !inv;
			if (e.key.keysym.sym == SDLK_ESCAPE)
				endGame = true;
		}
		if (e.type == SDL_MOUSEMOTION)
		{
			plr->GetMouse()->GetRect()->x = (e.button.x / 40) * 40;
			plr->GetMouse()->GetRect()->y = (e.button.y / 40) * 40;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
				WClick();
			if (e.button.button == SDL_BUTTON_RIGHT)
				SClick();
		}
	}
}

void Game::MoveEnemies()
{
	int x1 = player->GetRect()->x / 40;
	for (auto it = enemies.begin(); it != enemies.end(); it++)
	{
		if ((*it)->Dead())
		{
			enemies.erase(it);
			break;
		}
		else
		{
			int x;
			x = (*it)->GetRect()->x / 40;
			if (x < x1)
			{
				if (!MovePersonRightLeft(true, *it))
					MovePersonJump(*it);
			}
			else if (x > x1)
			{
				if (!MovePersonRightLeft(false, *it))
					MovePersonJump(*it);
			}
			else if (x == x1)
			{
				int y1 = player->GetRect()->y / 40;
				int y = (*it)->GetRect()->y / 40;
				if (y == y1)
					player->TakeDamage((*it)->GetDamage());
			}
		}
	}
}
