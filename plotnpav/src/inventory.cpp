using namespace std;

#include "inventory.h"


Inventory::Inventory(istream & out, SDL_Renderer * ren)
{
	for (int i = 0; i < 8; i++)
	{
		int id, num;
		out >> id >> num; // read from save file to the array
		slots.push_back(make_pair(id, num));
	}

	active_slot = 0;
	SDL_Surface * sur = SDL_LoadBMP("src/texture/persons/Inventory.bmp");
	tex = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);

	numbers = new SDL_Texture *[10];
	sur = SDL_LoadBMP("src/texture/menu/0.bmp");
	numbers[0] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/1.bmp");
	numbers[1] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/2.bmp");
	numbers[2] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/3.bmp");
	numbers[3] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/4.bmp");
	numbers[4] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/5.bmp");
	numbers[5] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/6.bmp");
	numbers[6] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/7.bmp");
	numbers[7] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/8.bmp");
	numbers[8] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
	sur = SDL_LoadBMP("src/texture/menu/9.bmp");
	numbers[9] = SDL_CreateTextureFromSurface(ren, sur);
	SDL_FreeSurface(sur);
}

void Inventory::Save(ostream & out)
{
	for (unsigned i = 0; i < slots.size(); i++)
		out << " " << slots[i].first << " " << slots[i].second; // write from the array to save file
}

Inventory::~Inventory()
{
	SDL_DestroyTexture(tex);
	for (int i = 0; i < 10; i++)
		SDL_DestroyTexture(numbers[i]);
	delete[] numbers;
}


void Inventory::DrawInventory(SDL_Renderer * ren)
{
	SDL_Rect r;
	r.h = 60;
	r.w = 410;
	r.x = 0;
	r.y = 0;
	SDL_RenderCopy(ren, tex, NULL, &r);

}

void Inventory::DrawSlot(SDL_Renderer * ren, int i, SDL_Texture * tex)
{
	SDL_Rect r;
	r.h = 40;
	r.w = 40;
	r.x = 10 + 50 * i;
	r.y = 10;
	SDL_RenderCopy(ren, tex, NULL, &r);
	r.h = 20;
	r.w = 10;
	r.x += 30;
	r.y += 20;
	int x = slots[i].second;
	for (int i = 0; i < 2; i++)
	{
		r.x -= 10 * i; // drawing numbers
		SDL_RenderCopy(ren, numbers[x % 10], NULL, &r);
		x /= 10;
	}
}

bool Inventory::PasteToInventory(int id, int num)
{
	int find = -1;
	int size = slots.size();
	if (id != -1) // if drop exists
		for (int i = 0; i < size; i++)
			if (slots[i].first == id) // if you already have this item
				find = i;
	if (find > -1)
	{
		slots[find].second += num;
		return true;
	}
	else
		for (int i = 0; i < size; i++)
			if (slots[i].first == -1) // if you have empty slot
			{
				slots[i].first = id;
				slots[i].second += num;
				return true;
			}
	return false;
}

bool Inventory::DelFromInventory(int num)
{
	if (slots[active_slot].first != -1) // if something inside active slot
	{
		slots[active_slot].second -= num;
		if (slots[active_slot].second <= 0)
		{
			slots[active_slot].first = -1;
			slots[active_slot].second = 0;
		}
		return true;
	}
	return false;
}

int Inventory::GetActiveSlot() const
{
	return active_slot;
}

void Inventory::SetActiveSlot(int AS)
{
	active_slot = AS;
}

int Inventory::GetItemID(int i) const
{
	return slots[i].first;
}

SDL_Texture * Inventory::GetTexture() const
{
	return tex;
}

int Inventory::GetInventorySize() const
{
	return slots.size();
}
