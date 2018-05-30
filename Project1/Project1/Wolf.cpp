#include "Wolf.h"


Wolf::Wolf(World &w, int x, int y) : Animal(w, x, y) {
	strength = 9;
	initiative = 5;
	symbol = 'W';
	name = "Wolf";
	age = 0;
}

Animal *Wolf::GiveBirth(int pos_x, int pos_y) {
	Animal *child = new Wolf(world, pos_x, pos_y);
	return child;
}

