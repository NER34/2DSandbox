using namespace std;

#include"enemy.h"

//-----------------------------------Enemy
Enemy::Enemy(SDL_Renderer * ren, int x, int y, int hp)
{
	time = new SDL_Texture *[4];
	SDL_Surface * sur = SDL_LoadBMP("src/texture/persons/Enemy1.bmp");
	time[0] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/persons/Enemy2.bmp");
	time[1] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/persons/Enemy3.bmp");
	time[2] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/persons/Enemy4.bmp");
	time[3] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/persons/Damage.bmp");
	damtex = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	health = hp;
	damage = 10;
	coor = new SDL_Rect;
	coor->w = 40;
	coor->h = 80;
	coor->x = x * 40;
	coor->y = y * 40;
	CD = 40;
	dam_cd = 0;
}

Enemy::~Enemy()
{
	SDL_DestroyTexture(texture);
	delete coor;
}

void Enemy::Save(ostream & out)
{
	out << coor->x / 40 << " " << coor->y / 40 << " " << health;
}

void Enemy::MoveX(bool right)
{
	if (CD == 0)
	{
		right ? coor->x += 40 : coor->x -= 40;
		CD += 40;
	}
	else
		CD--;
}
