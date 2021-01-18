#ifndef RUN_LAVA
#define RUN_LAVA

#include "parent_block.h"

/**
* RunLava(falling) block class. Block is parent class. Have changes in Physics and DestroyIt methods.
*/
class RunLava : public Block  // (falling)
{
public:
	/**
	* Construktor initialize falling lava block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	RunLava(SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~RunLava();
	/**
	* If there is nothing under the block will be created falling lava. Else if
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