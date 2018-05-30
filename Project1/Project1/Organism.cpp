#include "Organism.h"


Organism::Organism(World &w, int x, int y) : world(w), pos_x(x), pos_y(y) {
	is_dead = false;
}

int Organism::GetPosX() {
	return pos_x;
}

int Organism::GetPosY() {
	return pos_y;
}

int Organism::GetStrength() {
	return strength;
}

int Organism::GetInitiative() {
	return initiative;
}

int Organism::GetAge() {
	return age;
}

char Organism::GetSymbol() {
	return symbol;
}

bool Organism::GetStatus() {
	return is_dead;
}

void Organism::SetStatus(bool is_dead) {
	this->is_dead = is_dead;
}

void Organism::SetStrength(int strength) {
	this->strength = strength;
}

std::string Organism::GetName() {
	return name;
}

void Organism::IncreaseAge(int &age) {
	++age;
}

bool Organism::CompareStrength(Organism *attacker) {
	if (this->GetStrength() > attacker->GetStrength()) {
		return true;
	}
	else if (this->GetStrength() < attacker->GetStrength()) {
		return false;
	}
	return true;
}
