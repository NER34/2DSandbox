#ifndef ENEMY
#define ENEMY

#include "person.h"

//-----------------------------------Enemy
/**
* Enemys class. Person is a parent class
*/
class Enemy : public Person
{
public:
	/**
	* Method for replacing(Ox) of enemy with some intervals
	*
	* @param[in] right If right = true - replace person to the right. If right = false
	* replaceperson to the left
	*/
	void MoveX(bool right);
	/**
	* @param ren Renderer
	* @param x Coordinate of enemy(Ox)
	* @param y Coordinate of enemy(Oy)
	* @param hp HP of enemy
	*/
	Enemy(SDL_Renderer * ren, int x, int y, int hp);
	/**
	* Save enemy to a save-file
	*
	* @param[out] out Output stream to a save-file
	*/
	void Save(std::ostream & out);
	~Enemy();
private:
	int CD;
};
#endif
