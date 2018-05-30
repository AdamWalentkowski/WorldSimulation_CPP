#include "World.h"

World::World() {
	srand((unsigned int)time(NULL));
	map = new Organism**[MAP_SIZE];
	for (int i = 0; i < MAP_SIZE; i++) {
		map[i] = new Organism*[MAP_SIZE];
	}
	for (int i = 0; i < MAP_SIZE; i++) {
		memset(map[i], NULL, sizeof(*map)*MAP_SIZE);
	}
	graphic = new Interface(*this);
}

Organism *World::GetOrganism(int x, int y) {
	return map[y][x];
}

void World::DrawBorders() {
	for (int i = 0; i < MAP_SIZE + 2; i++) {
		graphic->Gotoxy(MAP_POS_X - 1, MAP_POS_Y - 1+i);
		for (int j = 0; j < MAP_SIZE + 2; j++) {
			if (i == 0 || i == MAP_SIZE + 1 || j == 0 || j == MAP_SIZE + 1) {
				putchar('#');
			}
			else putchar(' ');
		}
	}
}

void World::DrawWorld() {
	for (int i = 0; i < MAP_SIZE; i++) {
		graphic->Gotoxy(MAP_POS_X, MAP_POS_Y+i);
		for (int j = 0; j < MAP_SIZE; j++) {
			if (map[i][j]) {
				putchar(map[i][j]->GetSymbol());
			}
			else {
				putchar('.');
			}
		}
	}
}

void World::AddOrganism(Organism *organism) {
	if (!map[organism->GetPosX()][organism->GetPosY()]) {
		map[organism->GetPosY()][organism->GetPosX()] = organism;
		organisms_vector.push_back(organism);
		graphic->CommentAboutSpawn(organism);
	}
}

void World::KillOrganism(Organism *to_kill, Organism *killer) {
	graphic->CommentAboutDeath(to_kill, killer);
	to_kill->SetStatus(true);
	ClearAfterOrganism(to_kill->GetPosX(), to_kill->GetPosY());
}

void World::EatPlant(Organism *to_eat, Organism *eater) {
	graphic->CommentAboutEater(to_eat, eater);
	to_eat->SetStatus(true);
	ClearAfterOrganism(to_eat->GetPosX(), to_eat->GetPosY());
}

void World::SayAboutDeflection(Organism *deflected) {
	graphic->CommentAboutDeflection(deflected);
}

void World::SayAboutEscape(Organism *attacker) {
	graphic->CommentAboutEscape(attacker);
}

void World::SayAboutPower() {
	graphic->CommentAboutPower();
}

void World::SayAboutCooldown() {
	graphic->CommentAboutCooldown();
}

bool World::IsOnMap(int x, int y) {
	if (x < 0 || y < 0 || x > MAP_SIZE - 1 || y > MAP_SIZE - 1) return false;
	return true;
}

bool World::IsOccupied(int x, int y) {
	if (map[y][x] == NULL) return false;
	return true;
}

bool World::IsAnyAvailable(int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (IsOnMap(x + i-1, y + j-1)) {
				if (!IsOccupied(x + i-1, y + j-1)) return true;
			}
		}
	}
	return false;
}

void World::SetRandomDirection(int &x, int &y) {
	int dx;
	int dy;
	do {
		switch ((rand() % 4))
		{
		case 0:
			dx = 1;
			dy = 0;
			break;
		case 1:
			dx = -1;
			dy = 0;
			break;
		case 2:
			dx = 0;
			dy = 1;
			break;
		case 3:
			dx = 0;
			dy = -1;
			break;
		default:
			dx = 0;
			dy = 0;
			break;
		}
	} while (!IsOnMap(x + dx, y + dy));

	x += dx;
	y += dy;
}

void World::MoveOrganism(Organism *organism, int x, int y) {
	map[y][x] = organism;
}

void World::ClearAfterOrganism(int x, int y) {
	map[y][x] = NULL;
}

void World::SortVector() {
	std::sort(organisms_vector.begin(), organisms_vector.end(),
		[](Organism *first_animal, Organism *second_animal)->bool {
		if (first_animal->GetInitiative() == second_animal->GetInitiative()) return first_animal->GetAge() > second_animal->GetAge();
		return first_animal->GetInitiative() > second_animal->GetInitiative(); });
}

void World::ClearVector() {
	for (size_t i = 0,  k = organisms_vector.size(); i < k; i++, k = organisms_vector.size()) {
		if (organisms_vector[i]->GetStatus()) {
			DeleteOrganismFromVector(organisms_vector[i]);
		}
	}
}

void World::DeleteOrganismFromVector(Organism *to_kill) {
		std::vector<Organism*>::iterator it = std::find(organisms_vector.begin(), organisms_vector.end(), to_kill);
		delete *it;
		organisms_vector.erase(it);
}

void World::OrderedTurn() {
	int number_of_organisms = organisms_vector.size();
	for (int i = 0; i < number_of_organisms; i++) {
		if (!organisms_vector[i]->GetStatus()) {
			organisms_vector[i]->TakeAction();
		}
	}
	graphic->ResetComments();
}

World::~World() {
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; i++) {
			delete[] map[i][j];
		}
	}
	delete[] map;
}