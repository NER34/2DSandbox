#ifndef RUN_WATER1
#define RUN_WATER1

#include "parent_block.h"

/**
* RunWater1(running to the right water) block class. Block is parent class. Have changes in Physics and DestroyIt methods.
*/
class RunWater1 : public Block // (to the right)
{
public:
	/**
	* Construktor initialize running to the right water block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	RunWater1(SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~RunWater1();
	/**
	*  Will be created falling water if there is nothing under the block.
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in] x Ox coordinate of block;
	* @param[in] y Oy coordinate of block;
	*
	* @return Returns true
	*/
	bool Physics(std::shared_ptr<Map> & map, int x, int y);
	/**
	* Cant be destroyed
	*
	* @param[in,out] map All information about map(map, time, renderer)
	* @param[in,out] player Address of players object
	* @param[in] x Ox coordinate of block
	* @param[in] y Oy coordinate of block
	*
	* @return false
	*/
	bool DestroyIt(std::shared_ptr<Map> & map, Player * player, int x, int y);
};
#endif