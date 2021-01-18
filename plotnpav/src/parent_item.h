#ifndef PARENT_ITEM
#define PARENT_ITEM

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <memory>

#include "map.h"
#include "persons.h"

//----------------------------------Item
/**
* Item is parent class for every item-class.
*/
class Item
{
public:
	/**
	* This method returns items texture.
	*
	* @return Texture.
	*/
	SDL_Texture * GetTexture() const;
	/**
	* This method allows to use the item.
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in,out] player Address of players object;
	* @param[in] x Ox coordinate of mouse;
	* @param[in] y Oy coordinate of mouse;
	* @param[in] tang Tangibility parameter of block with coordinates (x,y);
	*
	*/
	virtual void Using(shared_ptr<Map> & map, Player * player, int x, int y, bool tang) = 0;
	/**
	* Destructor.
	*/
	~Item();
protected:
	int num;
	SDL_Texture * tex;
};
#endif
