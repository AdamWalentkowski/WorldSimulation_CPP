#include "Dandelion.h"


Dandelion::Dandelion(World &w, int x, int y) : Plant(w, x, y) {
	strength = 0;
	initiative = 0;
	symbol = 'd';
	name = "Dandelion";
	age = 0;
}

void Dandelion::TakeAction() {
	IncreaseAge(age);
	for (int i = 0; i < 3; i++) {
		Spread();
	}
}

Plant *Dandelion::Grow(int pos_x, int pos_y) {
	Plant *child = new Dandelion(world, pos_x, pos_y);
	return child;
}

