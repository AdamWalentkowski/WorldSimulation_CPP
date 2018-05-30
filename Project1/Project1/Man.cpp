#include "Man.h"


Man::Man(World &w, int x, int y) : Animal(w, x, y) {
	strength = 5;
	initiative = 4;
	symbol = 'M';
	name = "Man";
	age = 0;
	power_alpha=0;
	power_beta=0;
	cooldown = 10;
}

void Man::TakeAction() {
	bool status = true;
	int new_pos_x = pos_x;
	int new_pos_y = pos_y;
	IncreaseAge(age);
	TakeStep(new_pos_x, new_pos_y);
	if (world.IsOccupied(new_pos_x, new_pos_y)&&this!=world.GetOrganism(new_pos_x, new_pos_y)) {
		status = world.GetOrganism(new_pos_x, new_pos_y)->Collision(pos_x, pos_y);
		Sleep(2000);
	}

	if (status) {
		world.ClearAfterOrganism(pos_x, pos_y);
		pos_x = new_pos_x;
		pos_y = new_pos_y;
		world.MoveOrganism(this, pos_x, pos_y);
	}
}

bool Man::Collision(int x, int y) {
	if (CompareStrength(world.GetOrganism(x, y))) {
		world.KillOrganism(world.GetOrganism(x, y), this);
		return false;
	}
	else {
		world.KillOrganism(this, world.GetOrganism(x, y));
		return true;
	}
	return false;
}

void Man::TakeStep(int &x, int &y) {
	int dx=0;
	int dy=0;
		switch (_getch()) {
		case 'w':
			dy--;
			if (power_alpha >= age) {
				dy--;
			}
			else if (power_beta >= age) {
				if (rand() % 2 < 1) {
					dy--;
				}
			}
			break;
		case 's':
			dy++;
			if (power_alpha >= age) {
				dy++;
			}
			else if (power_beta >= age) {
				if (rand() % 2 < 1) {
					dy++;
				}
			}
			break;
		case  'd':
			dx++;
			if (power_alpha >= age) {
				dx++;
			}
			else if (power_beta >= age) {
				if (rand() % 2 < 1) {
					dx++;
				}
			}
			break;
		case 'a':
			dx--;
			if (power_alpha >= age) {
				dx--;
			}
			else if (power_beta >= age) {
				if (rand() % 2 < 1) {
					dx--;
				}
			}
			break;
		case 'p':
			if (cooldown >= 10) {
				TurnOnThePower();
			}
			else {
				world.SayAboutCooldown();
			}
			break;
		default: break;
		}

	if (world.IsOnMap(x+dx, y+dy)) {
		x += dx;
		y += dy;
	}
	cooldown++;
}

void Man::TurnOnThePower() {
	world.SayAboutPower();
	power_alpha = age+3;
	power_beta = power_alpha+2;
	cooldown = 0;
}

Animal *Man::GiveBirth(int pos_x, int pos_y) {
	Animal *child = new Man(world, pos_x, pos_y);
	return child;
}