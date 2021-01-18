#ifndef TREE
#define TREE

#include "parent_block.h"

/**
* Tree block class. Block is parent class. Have changes in Physics and Save methods.
*/
class Tree : public Block
{
public:
	/**
	* Construktor initialize tree block class (all textures, drop id and tangibility).
	*
	* @param[in] in Input stream from save file;
	* @param[in] ren Renderer;
	*/
	Tree(std::istream & in, SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~Tree();
	/**
	* If there is no dirt or grass block under the block, it will be deleted.
	* The tree will grow after a while.
	*
	* @param[in,out] map All information about map(map, time, renderer);
	* @param[in] x Ox coordinate of block;
	* @param[in] y Oy coordinate of block;
	*
	* @return Returns true.
	*/
	bool Physics(std::shared_ptr<Map> & map, int x, int y);
	/**
	* Write information about each tree to the save file.
	*
	* @param[out] out Output stream to save file;
	*/
	void Save(std::ostream & out);
private:
	SDL_Texture ** time; // for any time of day
	std::map<std::pair<int, int>, int> trees; // characteristics of any tree on the Map (first.first   x, first.second   y, second   tiner)
};
#endif