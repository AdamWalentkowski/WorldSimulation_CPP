#include "Belladonna.h"


Belladonna::Belladonna(World &w, int x, int y) : Plant(w, x, y) {
	strength = 99;
	initiative = 0;
	symbol = 'b';
	name = "Belladonna";
	age = 0;
}

bool Belladonna::Collision(int x, int y) {
	world.KillOrganism(world.GetOrganism(x, y), this);
	return false;
}


Plant *Belladonna::Grow(int pos_x, int pos_y) {
	Plant *child = new Belladonna(world, pos_x, pos_y);
	return child;
}

