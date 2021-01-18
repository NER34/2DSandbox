#ifndef DIRT
#define DIRT

#include "parent_block.h"

/**
* Dirt block class. Block is parent class. Have changes in Physics method.
*/
class Dirt : public Block
{
public:
	/**
	* Construktor initialize dirt block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	Dirt(SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~Dirt();
	/**
	* If somewhere near the block will be grass, it will grow on this block.
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