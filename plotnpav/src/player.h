#ifndef PLAYER
#define PLAYER

#include "person.h"

//-----------------------------------Player
/**
* Players class. Person is a parent class
*/
class Player : public Person
{
public:
	/**
	* @param[in] in Input stream from save-file
	* @param[out] ren Renderer
	*/
	Player(std::istream & in, SDL_Renderer * ren);
	~Player();
	/**
	* Save players information to the save-file
	*
	* @param[out] out Output stream to the save-file
	*/
	void Save(std::ostream & out);
	/**
	* Draws players hp bar
	*
	* @param[out] ren Renderer
	*/
	void DrawHPBar(SDL_Renderer * ren);
	/**
	* @return Address of the mouse object
	*/
	Mouse * GetMouse() const;
	/**
	* @return Address of the inventory object
	*/
	Inventory * GetInventory() const;
	/**
	* Respawn the player
	*
	* @param[in] map Map of the world
	* @param[in] x_max Max size of the world(Ox)
	* @param[in] y_max Max size of the world(Oy)
	*/
	void ReSpawn(std::vector<std::vector<int> > & map, int x_max, int y_max);
private:
	int air;
	SDL_Texture ** hp_bar;
	Inventory * inventory;
	Mouse * mouse;
};
#endif
