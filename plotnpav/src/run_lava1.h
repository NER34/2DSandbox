#ifndef RUN_LAVA1
#define RUN_LAVA1

#include "parent_block.h"

/**
* RunLava1(running to the right) lava block class. Block is parent class. Have changes in Physics and DestroyIt methods.
*/
class RunLava1 : public Block // (to the right)
{
public:
	/**
	* Construktor initialize running to the right lava block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	RunLava1(SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~RunLava1();
	/**
	*  Will be created falling lava if there is nothing under the block.
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
	* @return false.
	*/
	bool DestroyIt(std::shared_ptr<Map> & map, Player * player, int x, int y);
};
#endif