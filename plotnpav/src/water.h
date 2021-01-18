#ifndef WATER
#define WATER

#include "parent_block.h"

/**
* Water block class. Block is parent class. Have changes in Physics method.
*/
class Water : public Block
{
public:
	/**
	* Construktor initialize water block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	Water(SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~Water();
	/**
	* If there is nothing under the block will be created falling water. If
	* there is nothing to the right(to the left) of the block will be created
	* running to the right(to the left) water block.
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in] x Ox coordinate of block;
	* @param[in] y Oy coordinate of block;
	*
	* @return Returns true.
	*/
	bool Physics(std::shared_ptr<Map> & map, int x, int y);
};
#endif