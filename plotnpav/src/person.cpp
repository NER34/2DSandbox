using namespace std;

#include"person.h"

//-----------------------------------Person

void Person::MoveX(bool right)
{
	right ? coor->x += 40 : coor->x -= 40;
}

void Person::MoveY(int new_coef)
{
	if (new_coef == 0)
		if (coef <= -16)
		{
			coef += 15;
			coef *= -1;
			TakeDamage(5 * coef);
		}
	coef = new_coef;
	coor->y -= coef;
}

void Person::Time(int i)
{
	texture = time[i];
}

bool Person::TakeDamage(int t)
{
	if (dam_cd <= 0)
		health -= t;
	if (health > 100)
		health = 100;
	if (t > 0)
		if (dam_cd <= 0)
			dam_cd = 15;
	if (health <= 0)
		return true;
	return false;
}

void Person::Physics(std::vector<std::vector<int> > & map, bool tang, int x, int y, SDL_Renderer * ren)
{
	//-------------------------Gravity
	if (y >= 31) // if person fall under the world
		TakeDamage(100);
	else if (tang) // if there is something with tangibility = true under the person 
	{
		MoveY(0);
		coor->y = y * 40;
	}
	else
		MoveY(coef - 1);
	//---------------------------Water
	if (map[y][x] == 5 || map[y][x] == 9 || map[y][x] == 10 || map[y][x] == 11)
	{
		if (air >= 500)
			TakeDamage(1);
		else
			air++;
	}
	else
		air = 0;
	//---------------------------Lava
	if ((map[y][x] == 6 || map[y][x] == 12 || map[y][x] == 13 || map[y][x] == 14) || (map[y + 1][x] == 6 || map[y + 1][x] == 12 || map[y + 1][x] == 13 || map[y + 1][x] == 14))
		TakeDamage(100);
}

SDL_Texture * Person::GetTexture()
{
	if (dam_cd > 0)
	{
		dam_cd -= 1;
		return damtex;
	}
	else
		return texture;

}

SDL_Rect * Person::GetRect() const
{
	return coor;
}

int Person::GetKoef() const
{
	return coef;
}

int Person::GetHP() const
{
	return health;
}

int Person::GetDamage() const
{
	return damage;
}

bool Person::Dead()
{
	return health <= 0;
}
