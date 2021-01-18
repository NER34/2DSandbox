#ifndef IFOOD
#define IFOOD

#include "parent_item.h"

//----------------------------------Food
/**
* Item is parent class. IÀùùâ has its own constructor and all methods of class Item.
*/
class IFood : public Item
{
public:
	/**
	* Initialize IFood object.
	*
	* @param[in] ren Renderer;
	* @param[in] str Address of picture in file system;
	* @param[in] num How many hp food restores;
	*/
	IFood(SDL_Renderer * ren, const char * str, int num);
	/**
	* This method allows to eat food.
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in,out] player Address of players object;
	* @param[in] x Ox coordinate of mouse;
	* @param[in] y Oy coordinate of mouse;
	* @param[in] tang Tangibility parameter of block with coordinates (x,y);
	*
	*/
	void Using(shared_ptr<Map> & map, Player * player, int x, int y, bool tang);
};
#endif
