#include "Plant.h"

Plant::Plant(World &w, int x, int y) : Organism(w, x, y) {
}

void Plant::TakeAction() {
	IncreaseAge(age);
	Spread();
}

bool Plant::Collision(int x, int y) {
	if (CompareStrength(world.GetOrganism(x, y))) {
		world.KillOrganism(world.GetOrganism(x, y), this);
		return false;
	}
	else if (world.GetOrganism(x, y)->GetSymbol() >= 'A' && world.GetOrganism(x, y)->GetSymbol() <= 'Z' && !CompareStrength(world.GetOrganism(x, y))) {
		world.EatPlant(this, world.GetOrganism(x, y));
		return false;
	}
	else if (!CompareStrength(world.GetOrganism(x, y))) {
		world.KillOrganism(this, world.GetOrganism(x, y));
		return true;
	}
	return false;
}

void Plant::Spread() {
	if (rand() % 100 < 2) {
		int new_x = pos_x;
		int new_y = pos_y;
		if (world.IsAnyAvailable(pos_x, pos_y)) {
			do {
				world.SetRandomDirection(new_x, new_y);
			} while (world.IsOccupied(new_x, new_y));
			world.AddOrganism(Grow(new_x, new_y));
		}
	}
}