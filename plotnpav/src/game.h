#ifndef GAME
#define GAME

#include <string>
#include <fstream>
#include <list>
#include <memory>
#include <vector>

#include "map.h"
#include "persons.h"
#include "items.h"
#include "blocks.h"
/**
* Central class.
* Have all information about map, player, enemies, blocks and items.
*/
class Game
{
public:
	/**
	* Construktor initialize the game class (map, all blocks and items, player and enemies).
	*
	* @param[in] in Input stream from a save file;
	* @param[in] ren Renderer;
	*/
	Game(istream & in, SDL_Renderer * ren);
	/**
	* This method save all important parameters to the save file.
	*
	* @param[in] name Name of save file;
	*/
	void End(const std::string & name);
	/**
	* This method calles all draw functions and enemy spawn function.
	*/
	void Draw();
	/**
	* This method calles all moving functions.
	*/
	void Move();
	/**
	* This method spown enemies on the map.
	*/
	void EnemySpown();
	/**
	* This method create 2d map array.
	*
	* @param[in] in Input from the save file;
	*
	* @return Returns 2d map array.
	*/
	std::vector<std::vector<int> > CreateMap(istream & in);
	bool endGame;
	//           Drawing              
	/**
	* This method take data from initmap and draw map in the window.
	* At the same time it calles physics function of each block.
	*/
	void DrawMap();
	/**
	* This method draw persons. It can be player or enemy.
	* At the same time it calles physics function of person.
	*
	* @param[in,out] per Address of person;
	*/
	void DrawPerson(std::shared_ptr<Person> & per);
	/**
	* This method draws the mouse.
	*/
	void DrawMouse();
	/**
	* This method draws players HP and function, which draw players inventory.
	*/
	void DrawPlayerInfo();
	//            Moving              
	/**
	* This method replace person to the left or to the right. It can be player or enemy.
	*
	* @param[in] right If right = true person move to the right, if right = false it move to the left;
	* @param[in,out] pers Address of person;
	*
	* @return Return true if person can move. Return false if person cant move.
	*/
	bool MovePersonRightLeft(bool right, std::shared_ptr<Person> & pers);
	/**
	* This method allows the person to jump. It can be player or enemy.
	*
	* @param[in,out] pers Address of person;
	*/
	void MovePersonJump(std::shared_ptr<Person> & pers);
	/**
	* This method allows the player destroy blocks or damage enemies.
	*/
	void WClick();
	/**
	* This method allows the player use blocks or items.
	*/
	void SClick();
	/**
	* This method moves player.
	*
	* A   move to the left;
	* D   move to the right;
	* Space   jumping;
	* Esc   save and exit to the main menu;
	* I   show/hide players inventory and HP;
	* LMB(Left Mouse Botton)   take block or damage enemy;
	* RMB(Right Mouse Botton)   use blocks or items;
	*/
	void MovePlayer();
	/**
	* This method moves enemies.
	*/
	void MoveEnemies();
private:
	bool inv; // show/hide inventory
	std::shared_ptr<Person> player;
	std::list<shared_ptr<Person> > enemies;
	std::vector<shared_ptr<Item> > items_type;
	std::vector<shared_ptr<Block> > blocks_type;
	std::shared_ptr<Map> initmap;
};

#endif // !GAME