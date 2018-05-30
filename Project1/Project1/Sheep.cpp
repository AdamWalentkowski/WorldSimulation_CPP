#include "Sheep.h"


Sheep::Sheep(World &w, int x, int y) : Animal(w, x, y) {
	strength = 4;
	initiative = 4;
	symbol = 'S';
	name = "Sheep";
	age = 0;
}



Animal *Sheep::GiveBirth(int pos_x, int pos_y) {
	Animal *child = new Sheep(world, pos_x, pos_y);
	return child;
}
