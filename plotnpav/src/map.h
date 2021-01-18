#ifndef INIT
#define INIT

#include <SDL2/SDL.h>
#include <fstream>
#include <vector>

#define x_size 32
#define y_size 16
#define HIGH 640
#define LENGHTH 1280

/**
 * Presents worlds map.
 */
class Map
{
public:
	/**
	* @param[in] map Worlds map;
	* @param[in] t Time;
	* @param[in] ren Renderer;
	*/
	Map(std::vector<std::vector<int> > map, int t, SDL_Renderer * ren);
	/**
	* Save information about the world to the save-file.
	*
	* @param[out] out Output stream to a save-file;
	*/
	void Save(std::ostream & out);
	int time; // Get time.
	SDL_Renderer * ren; // Get renderer
	std::vector<std::vector<int> > map; // Get mapp
};

#endif