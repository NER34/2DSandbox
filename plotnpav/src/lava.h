#ifndef LAVA
#define LAVA

#include "parent_block.h"

/**
* Lava block class. Block is parent class. Have changes in Physics method.
*/
class Lava : public Block
{
public:
	/**
	* Construktor initialize lava block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	Lava(SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~Lava();
	/**
	* If there is nothing under the block will be created falling lava. If
	* there is nothing to the right(to the left) of the block will be created
	* running to the right(to the left) lava block.
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