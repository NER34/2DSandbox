#include <SDL2/SDL.h>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

#include "menu.h"

Menu::Menu()
{
	win = SDL_CreateWindow("The Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LENGHTH, HIGH, SDL_WINDOW_SHOWN);

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	textures = new SDL_Texture *[8];
	SDL_Surface * sur = SDL_LoadBMP("src/texture/menu/MainMenu.bmp");
	textures[0] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/NewGame.bmp");
	textures[1] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/Continue.bmp");
	textures[2] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/Exit.bmp");
	textures[3] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/SelectSaving.bmp");
	textures[4] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/Saving_1.bmp");
	textures[5] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/Saving_2.bmp");
	textures[6] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/Saving_3.bmp");
	textures[7] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
}

Menu::~Menu()
{
	for (int i = 0; i < 8; i++)
		SDL_DestroyTexture(textures[i]);
	delete[] textures;
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

void Menu::MainMenu()
{
	int fun = NEW_GAME;
	bool end = false;
	while (!end)
	{
		DrawMainMenu(fun);
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_s)
				{
					if (fun == 2)
						fun -= 3;
					fun++;
				}
				if (e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_w)
				{
					if (fun == 0)
						fun += 3;
					fun--;
				}
				if (e.key.keysym.sym == SDLK_e || e.key.keysym.sym == SDLK_SPACE)
				{
					string name = "src/saving/save_";
					if (fun == NEW_GAME) {
						string num;
						num = SelectSaving(); // choose save file
						if (num != "0") {
							name += num + ".txt";
							ifstream in("src/saving/default.txt");
							game = new Game(in, ren);
							in.close();
							while (!game->endGame)
							{
								game->Draw();
								game->Move();
							}
							game->End(name);
							delete game;
						}
					}
					if (fun == CONTINUE) {
						string num;
						num = SelectSaving();
						if (num != "0") {
							name += num + ".txt";
							ifstream in(name);
							int control = 0;
							in >> control;
							if (control == 1) {
								game = new Game(in, ren);
								in.close();
								while (!game->endGame)
								{
									game->Draw();
									game->Move();
								}
								game->End(name);
								delete game;
							}
							else
								in.close();
						}
					}
					if (fun == EXIT)
						end = true;
				}
			}
		}
	}
}

void Menu::DrawMainMenu(int fun)
{

	SDL_RenderCopy(ren, textures[0], NULL, NULL);
	SDL_Rect r;
	switch (fun)
	{
	case NEW_GAME:
		r.x = 500;
		r.y = 240;
		r.h = 85;
		r.w = 305;
		SDL_RenderCopy(ren, textures[1], NULL, &r);
		break;
	case CONTINUE:
		r.x = 512;
		r.y = 345;
		r.h = 90;
		r.w = 270;
		SDL_RenderCopy(ren, textures[2], NULL, &r);
		break;
	case EXIT:
		r.x = 585;
		r.y = 450;
		r.h = 80;
		r.w = 135;
		SDL_RenderCopy(ren, textures[3], NULL, &r);
		break;
	}
	SDL_RenderPresent(ren);
}

string Menu::SelectSaving()
{
	int fun = 0;
	while (true)
	{
		DrawSelectSaving(fun);
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
					return "0";
				if (e.key.keysym.sym == SDLK_DOWN || e.key.keysym.sym == SDLK_s)
				{
					if (fun == 2)
						fun -= 3;
					fun++;
				}
				if (e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_w)
				{
					if (fun == 0)
						fun += 3;
					fun--;
				}
				if (e.key.keysym.sym == SDLK_e || e.key.keysym.sym == SDLK_SPACE)
				{
					if (fun == 0)
						return "1";
					else if (fun == 1)
						return "2";
					else
						return "3";
				}
			}
		}
	}
}

void Menu::DrawSelectSaving(int fun)
{
	SDL_RenderCopy(ren, textures[4], NULL, NULL);
	SDL_Rect r;
	switch (fun + 3)
	{
	case SAVING_1:
		r.x = 500;
		r.y = 200;
		r.h = 110;
		r.w = 270;
		SDL_RenderCopy(ren, textures[5], NULL, &r);
		break;
	case SAVING_2:
		r.x = 500;
		r.y = 315;
		r.h = 110;
		r.w = 270;
		SDL_RenderCopy(ren, textures[6], NULL, &r);
		break;
	case SAVING_3:
		r.x = 500;
		r.y = 435;
		r.h = 110;
		r.w = 270;
		SDL_RenderCopy(ren, textures[7], NULL, &r);
		break;
	}
	SDL_RenderPresent(ren);
}
