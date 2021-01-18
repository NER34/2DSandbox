#ifndef PARENT_BLOCK
#define PARENT_BLOCK

#include <SDL2/SDL.h>
#include <memory>
#include <map>
#include <fstream>

#include "map.h"
#include "persons.h"

/**
* Block is parent class for each block class.
*/
class Block
{
public:
	/**
	* This method set physics for blocks
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in] x Ox coordinate of block;
	* @param[in] y Oy coordinate of block;
	*
	* @return Returns true if block have physics. If not returns false.
	*/
	virtual bool Physics(std::shared_ptr<Map> & map, int x, int y) { return false; };
	/**
	* This method delete block on the map and give it to player
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in,out] player Address of players object;
	* @param[in] x Ox coordinate of block;
	* @param[in] y Oy coordinate of block;
	*
	* @return Returns true if block can be deleted. If not returns false.
	*/
	virtual bool DestroyIt(std::shared_ptr<Map> & map, Player * player, int x, int y);
	/**
	* This method allows to use the block.
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in,out] player Address of players object;
	* @param[in] x Ox coordinate of block;
	* @param[in] y Oy coordinate of block;
	*
	* @return Returns true if block can be used. If not returns false.
	*/
	virtual bool Using(std::shared_ptr<Map> & map, Player * player, int x, int y) { return false; }
	/**
	* This method allows to save information about the block. It do nothing if block have nothing to save.
	*
	* @param[out] out Stream to save file.
	*/
	virtual void Save(std::ostream & out) {}
	/**
	* This method returns blocks texture.
	*/
	SDL_Texture * GetTexture() const;
	/**
	* This method returns blocks tangibility parameter.
	*/
	bool GetTangibility() const;
	/**
	* This method returns blocks drop id.
	*/
	int GetDropID() const;
protected:
	SDL_Texture * texture;
	bool tang; // tangibility
	int drop_id;
};
#endif
