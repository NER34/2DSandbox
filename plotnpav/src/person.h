#ifndef PERSON
#define PERSON

#include <vector>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <fstream>

#include "inventory.h"
#include "mouse.h"

//-----------------------------------Person
/**
 * This is a parent class for players and enemies
 */
class Person
{
public:
	/**
	* Save person to a save-file
	*
	* @param[out] out Output stream to a save-file
	*/
	virtual void Save(std::ostream & out) {}
	/**
	* Method for replacing(Ox) of person
	*
	* @param[in] right If right = true - replace person to the right. If right = false
	* replaceperson to the left
	*/
	virtual void MoveX(bool right);
	/**
	* Method for replacing(Ox) of person
	*
	* @param[in] new_coef how far it should be replaced
	*/
	void MoveY(int new_coef);
	/**
	* This method damege the person
	*
	* @param[in] t If t > 0, the person will get damage. Otherwise it will be healed
	*/
	bool TakeDamage(int t);
	/**
	* Persons texture depends on time
	*
	* @param[in] i Texture index
	*/
	void Time(int i);
	/**
	* @param[in] map Map of the world
	* @param[in] tang Tangebility of the block under the person
	* @param[in] x Coordinate of the person(Ox)
	* @param[in] y Coordinate of the person(Oy)
	* @param[in] ren Renderer
	*/
	void Physics(std::vector<std::vector<int> > & map, bool tang, int x, int y, SDL_Renderer * ren);
	/**
	* @return Texture of the person
	*/
	SDL_Texture * GetTexture();
	/**
	* @return Coordinates of the person
	*/
	SDL_Rect * GetRect() const;
	/**
	* @return Coefficient of falling
	*/
	int GetKoef() const;
	/**
	* @return HP
	*/
	int GetHP() const;
	/**
	* @return Damage
	*/
	int GetDamage() const;
	/**
	* @return If health <= 0 - returns true. Otherwise returns false
	*/
	bool Dead();
protected:
	SDL_Texture * texture;
	SDL_Texture ** time; // textures for all time of day
	SDL_Texture * damtex; // damage texture
	int health;
	int damage;
	int air;
	SDL_Rect * coor;
	int coef;
	int dam_cd;
};
#endif
