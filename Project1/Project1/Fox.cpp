#include "Fox.h"


Fox::Fox(World &w, int x, int y) : Animal(w, x, y) {
	strength = 3;
	initiative = 7;
	symbol = 'F';
	name = "Fox";
	age = 0;
}

void Fox::TakeAction() {
	bool status = false;
	int new_pos_x = pos_x;
	int new_pos_y = pos_y;
	IncreaseAge(age);
	world.SetRandomDirection(new_pos_x, new_pos_y);
	if (!world.IsOccupied(new_pos_x, new_pos_y)) {
		status = true;
	}
	if (world.IsOccupied(new_pos_x, new_pos_y)&&CompareStrength(world.GetOrganism(new_pos_x, new_pos_y))) {
		status = world.GetOrganism(new_pos_x, new_pos_y)->Collision(pos_x, pos_y);
	}

	if (status) {
		world.ClearAfterOrganism(pos_x, pos_y);
		pos_x = new_pos_x;
		pos_y = new_pos_y;
		world.MoveOrganism(this, pos_x, pos_y);
	}
}

Animal *Fox::GiveBirth(int pos_x, int pos_y) {
	Animal *child = new Fox(world, pos_x, pos_y);
	return child;
}

