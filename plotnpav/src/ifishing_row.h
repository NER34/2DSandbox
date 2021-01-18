#ifndef IFISHING_ROW
#define IFISHING_ROW

#include "parent_item.h"

//----------------------------------Fishing Row
/**
* Item is parent class. IFishingRow has its own constructor and all methods of class Item.
*/
class IFishingRow : public Item
{
public:
	/**
	* Initialize IFishingRow object.
	*
	* @param[in] ren Renderer;
	* @param[in] str Address of picture in file system;
	* @param[in] id Block id;
	*/
	IFishingRow(SDL_Renderer * ren, const char * str, int id);
	/**
	* This method allows to use fishing row.
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
