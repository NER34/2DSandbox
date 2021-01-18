#ifndef WOOD
#define WOOD

#include "parent_block.h"

/**
* Wood block class. Block is parent class. Have no changes in methods.
*/
class Wood : public Block
{
public:
	/**
	* Construktor initialize wood block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	Wood(SDL_Renderer * ren);
	/**
	* Destructor
	*/
	~Wood();
};
#endif