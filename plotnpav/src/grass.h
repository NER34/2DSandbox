#ifndef GRASS
#define GRASS

#include "parent_block.h"

/**
* Grass block class. Block is parent class. Have changes in Physics method.
*/
class Grass : public Block
{
public:
	/**
	* Construktor initialize grass block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	Grass(SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~Grass();
	/**
	* If there is something above the block, it will be replaced by the dirt block.
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