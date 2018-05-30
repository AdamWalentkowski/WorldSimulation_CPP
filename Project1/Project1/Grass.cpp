#include "Grass.h"


Grass::Grass(World &w, int x, int y) : Plant(w, x, y) {
	strength = 0;
	initiative = 0;
	symbol = 'g';
	name = "Grass";
	age = 0;
}



Plant *Grass::Grow(int pos_x, int pos_y) {
	Plant *child = new Grass(world, pos_x, pos_y);
	return child;
}

