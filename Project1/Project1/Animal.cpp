#include "Animal.h"


Animal::Animal(World &w, int x, int y) : Organism(w, x, y) {
}

void Animal::TakeAction() {
	bool status = true;
	int new_pos_x = pos_x;
	int new_pos_y = pos_y;
	IncreaseAge(age);
	world.SetRandomDirection(new_pos_x, new_pos_y);
	if(world.IsOccupied(new_pos_x, new_pos_y)){
		status = world.GetOrganism(new_pos_x, new_pos_y)->Collision(pos_x, pos_y);
	}

	if (status) {
		world.ClearAfterOrganism(pos_x, pos_y);
		pos_x = new_pos_x;
		pos_y = new_pos_y;
		world.MoveOrganism(this, pos_x, pos_y);
	}
}

bool Animal::Collision(int x, int y) {
	if (this->GetSymbol() == world.GetOrganism(x, y)->GetSymbol()) {
		if (this->GetAge()>10 && world.GetOrganism(x, y)->GetAge()>10) {
			Procreate();
		}
		return false;
	}
	else if (CompareStrength(world.GetOrganism(x, y))) {
		world.KillOrganism(world.GetOrganism(x, y), this);
		return false;
	}
	else if (!CompareStrength(world.GetOrganism(x, y))) {
		world.KillOrganism(this, world.GetOrganism(x, y));
		return true;
	}
	return false;
}

void Animal::Procreate() {
	int new_x = pos_x;
	int new_y = pos_y;
	if (world.IsAnyAvailable(pos_x, pos_y)) {
		do {
			world.SetRandomDirection(new_x, new_y);
		} while (world.IsOccupied(new_x, new_y));
		world.AddOrganism(GiveBirth(new_x, new_y));
	}
}
