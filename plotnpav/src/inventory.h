#ifndef INVENTORY
#define INVENTORY
#include <vector>
#include <SDL2/SDL.h>
#include <fstream>
/**
* Presen players inventory.
*/
class Inventory
{
public:
	/**
	* Constructor initialize inventory class(coordinates and texture).
	*
	* @param[in] in Input stream from save-file;
	* @param[in] ren Renderer;
	*/
	Inventory(std::istream & in, SDL_Renderer * ren);
	/**
	* Destructor.
	*/
	~Inventory();
	/**
	* Save inventory to the save-file.
	*
	* @param[out] out Output stream to a save-file;
	*/
	void Save(std::ostream & out);
	/**
	* Draw players inventory.
	*
	* @param[out] ren Renderer;
	*/
	void DrawInventory(SDL_Renderer * ren);
	/**
	* Draw each slot of players inventory.
	*
	* @param[out] ren Renderer;
	* @param[in] i Number of slot;
	* @param[in] tex Items texture;
	*/
	void DrawSlot(SDL_Renderer * ren, int i, SDL_Texture * tex);
	/**
	* Paste item to the players inventory if it already in or there is empty slot.
	*
	* @param[in] id Item id;
	* @param[in] num Number of items;
	*/
	bool PasteToInventory(int id, int num);
	/**
	* Deletes items from active slot if this slot is not empty.
	*
	* @param[in] num Number of items which should be deleted;
	*/
	bool DelFromInventory(int num);
	/**
	* @param AS Index of active slot.
	*/
	void SetActiveSlot(int AS);
	/**
	* @return Index of active slot.
	*/
	int GetActiveSlot() const;
	/**
	* @param[in] i Slot index.
	*
	* @return Item ID.
	*/
	int GetItemID(int i) const;
	/**
	* @return Size of inventory.
	*/
	int GetInventorySize() const;
	/**
	* @return Inventory texture.
	*/
	SDL_Texture * GetTexture() const;
private:
	SDL_Texture * tex;
	SDL_Texture ** numbers;
	int active_slot;
	std::vector<std::pair<int, int> >  slots;
};
#endif
