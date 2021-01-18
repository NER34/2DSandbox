#ifndef RUN_WATER
#define RUN_WATER

#include "parent_block.h"

/**
* RunWater(falling water) block class. Block is parent class. Have changes in Physics and DestroyIt methods.
*/
class RunWater : public Block // (falling)
{
public:
	/**
	* Construktor initialize falling water block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	RunWater(SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~RunWater();
	/**
	* If there is nothing under the block will be created falling water. Else if
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
	/**
	* Cant be destroyed.
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in,out] player Address of players object;
	* @param[in] x Ox coordinate of block;
	* @param[in] y Oy coordinate of block;
	*
	* @return Returns false.
	*/
	bool DestroyIt(std::shared_ptr<Map> & map, Player * player, int x, int y);
};
#endif