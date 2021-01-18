#ifndef LEAVES
#define LEAVES

#include "parent_block.h"

/**
* Leaves block class. Block is parent class. Have changes in Physics and DestroyIt methods.
*/
class Leaves : public Block
{
public:
	/**
	* Construktor initialize tree block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	Leaves(SDL_Renderer * ren);
	/**
	* Destructor
	*/
	~Leaves();
	/**
	* If there is no leaves or wood block near the block, it will be deleted.
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in] x Ox coordinate of block;
	* @param[in] y Oy coordinate of block;
	*
	* @return Returns true.
	*/
	bool Physics(std::shared_ptr<Map> & map, int x, int y);
	/**
	* After destroying with a small chance the block will drop a tree.
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in,out] player Address of players object;
	* @param[in] x Ox coordinate of block;
	* @param[in] y Oy coordinate of block;
	*
	* @return Returns drop id.
	*/
	bool DestroyIt(std::shared_ptr<Map> & map, Player * player, int x, int y);
};
#endif