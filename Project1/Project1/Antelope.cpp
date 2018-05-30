#include "Antelope.h"


Antelope::Antelope(World &w, int x, int y) : Animal(w, x, y) {
	strength = 4;
	initiative = 4;
	symbol = 'A';
	name = "Antelope";
	age = 0;
}

void Antelope::TakeAction() {
	bool status = true;
	int new_pos_x = pos_x;
	int new_pos_y = pos_y;
	IncreaseAge(age);
	world.SetRandomDirection(new_pos_x, new_pos_y);
	int newer_pos_x = new_pos_x;
	int newer_pos_y = new_pos_y;
	if (rand() % 2 < 1) {
		do {
			world.SetRandomDirection(newer_pos_x, newer_pos_y);
		} while (newer_pos_x == pos_x && newer_pos_y == pos_y);
	}
	if (world.IsOccupied(newer_pos_x, newer_pos_y)) {
		status = world.GetOrganism(newer_pos_x, newer_pos_y)->Collision(pos_x, pos_y);
	}

	if (status) {
		world.ClearAfterOrganism(pos_x, pos_y);
		pos_x = newer_pos_x;
		pos_y = newer_pos_y;
		world.MoveOrganism(this, pos_x, pos_y);
	}
}

bool Antelope::Collision(int x, int y) {
	if (this->GetSymbol() == world.GetOrganism(x, y)->GetSymbol()) {
		if (this->GetAge()>10 && world.GetOrganism(x, y)->GetAge()>10) {
			Procreate();
		}
		return false;
	}
	if(rand()%2<1){
		if (CompareStrength(world.GetOrganism(x, y))) {
			world.KillOrganism(world.GetOrganism(x, y), this);
			return false;
		}
		else {
			world.KillOrganism(this, world.GetOrganism(x, y));
			return true;
		}
	}
	else if (world.IsAnyAvailable(pos_x, pos_y)) {
		world.SayAboutEscape(world.GetOrganism(x, y));
		int temp_pos_x;
		int temp_pos_y;
		do {
			temp_pos_x = pos_x;
			temp_pos_y = pos_y;
			world.SetRandomDirection(temp_pos_x, temp_pos_y);
		} while (world.IsOccupied(temp_pos_x, temp_pos_y));
		world.ClearAfterOrganism(pos_x, pos_y);
		pos_x = temp_pos_x;
		pos_y = temp_pos_y;
		world.MoveOrganism(this, pos_x, pos_y);
		return true;
	}
	world.SayAboutEscape(world.GetOrganism(x, y));
	return false;
}

Animal *Antelope::GiveBirth(int pos_x, int pos_y) {
	Animal *child = new Antelope(world, pos_x, pos_y);
	return child;
}