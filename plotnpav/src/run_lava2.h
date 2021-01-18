#ifndef RUN_LAVA2
#define RUN_LAVA2

#include "parent_block.h"

/**
* RunLava2(running to the left) lava block class. Block is parent class. Have changes in Physics and DestroyIt methods.
*/
class RunLava2 : public Block // (to the left)
{
public:
	/**
	* Construktor initialize running to the left lava block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	RunLava2(SDL_Renderer * ren);
	/**
	* Destructor
	*/
	~RunLava2();
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