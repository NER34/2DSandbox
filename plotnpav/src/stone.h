#ifndef STONE
#define STONE

#include "parent_block.h"

/**
* Stone block class. Block is parent class. Have no changes in methods.
*/
class Stone : public Block
{
public:
	/**
	* Construktor initialize stone block class (all textures, drop id and tangibility).
	*
	* @param[in] ren Renderer;
	*/
	Stone(SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~Stone();
};
#endif