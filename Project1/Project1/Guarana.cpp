#include "Guarana.h"


Guarana::Guarana(World &w, int x, int y) : Plant(w, x, y) {
	strength = 0;
	initiative = 0;
	symbol = '+';
	name = "Guarana";
	age = 0;
}

bool Guarana::Collision(int x, int y) {
	if (CompareStrength(world.GetOrganism(x, y))) {
		world.KillOrganism(world.GetOrganism(x, y), this);
		return false;
	}
	else if (world.GetOrganism(x, y)->GetSymbol() >= 'A' && world.GetOrganism(x, y)->GetSymbol() <= 'Z' && !CompareStrength(world.GetOrganism(x, y))) {
		world.EatPlant(this, world.GetOrganism(x, y));
		world.GetOrganism(x, y)->SetStrength(world.GetOrganism(x, y)->GetStrength() + 3);
		return false;
	}
	else if (!CompareStrength(world.GetOrganism(x, y))) {
		world.KillOrganism(this, world.GetOrganism(x, y));
		return true;
	}
	return false;
}


Plant *Guarana::Grow(int pos_x, int pos_y) {
	Plant *child = new Guarana(world, pos_x, pos_y);
	return child;
}

