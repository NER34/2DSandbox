#ifndef AIR
#define AIR

#include "parent_block.h"

/**
* Air block class. Block is parent class. Have changes in Physics and DestroyIt methods.
*/
class Air : public Block
{
public:
	/**
	* Construktor initialize air block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	Air(SDL_Renderer * ren);
	/**
	* Destructor
	*/
	~Air();
	/**
	* Texture depends on time of day.
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in] x Ox coordinate of block;
	* @param[in] y Oy coordinate of block;
	*
	* @return Returns true.
	*/
	bool Physics(std::shared_ptr<Map> & map, int x, int y);
	/**
	* Cant be destroyed.
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in,out,out] player Address of players object;
	* @param[in] x Ox coordinate of block;
	* @param[in] y Oy coordinate of block;
	*
	* @return Returns false.
	*/
	bool DestroyIt(std::shared_ptr<Map> & map, Player * player, int x, int y);
private:
	SDL_Texture ** time; // for any time of day
};
#endif