using namespace std;

#include"player.h"

//-----------------------------------Plyer

Player::Player(istream & out, SDL_Renderer * ren)
{
	time = new SDL_Texture *[4];
	SDL_Surface * sur = SDL_LoadBMP("src/texture/persons/Player1.bmp");
	time[0] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/persons/Player2.bmp");
	time[1] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/persons/Player3.bmp");
	time[2] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/persons/Player4.bmp");
	time[3] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/persons/Damage.bmp");
	damtex = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	damage = 20;
	coor = new SDL_Rect;
	coor->w = 40;
	coor->h = 80;
	out >> coor->x;
	coor->x *= 40;
	out >> coor->y;
	coor->y *= 40;
	out >> health;
	mouse = new Mouse(ren);
	inventory = new Inventory(out, ren);
	hp_bar = new SDL_Texture *[3];
	sur = SDL_LoadBMP("src/texture/persons/Empty.bmp");
	hp_bar[0] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/persons/Half.bmp");
	hp_bar[1] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/persons/Full.bmp");
	hp_bar[2] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	dam_cd = 0;
}

void Player::Save(ostream & out)
{
	out << coor->x / 40 << " " << coor->y / 40 << " " << health;
	inventory->Save(out);
	out << endl;
}

Player::~Player()
{
	for (int i = 0; i < 4; i++)
		SDL_DestroyTexture(time[i]);
	delete[] time;
	SDL_DestroyTexture(damtex);
	for (int i = 0; i < 3; i++)
		SDL_DestroyTexture(hp_bar[i]);
	delete[] hp_bar;
	delete coor;
	delete mouse;
	delete inventory;
}

void Player::DrawHPBar(SDL_Renderer * ren)
{
	SDL_Rect r;
	r.h = 20;
	r.w = 20;
	r.y = 10;
	for (int i = 0; i < 10; i++)
	{
		int x = health - 10 * i;
		r.x = 1000 + 20 * i;
		if (x <= 0)
			SDL_RenderCopy(ren, hp_bar[0], NULL, &r);
		else if (x <= 5)
			SDL_RenderCopy(ren, hp_bar[1], NULL, &r);
		else
			SDL_RenderCopy(ren, hp_bar[2], NULL, &r);
	}
}

Mouse * Player::GetMouse() const
{
	return mouse;
}

Inventory * Player::GetInventory() const
{
	return inventory;
}

void Player::ReSpawn(vector<vector<int> > & map, int x_max, int y_max)
{
	coor->x = 22 * 40;
	coor->y = 8 * 40;
	health = 100;
	coef = 0;
}