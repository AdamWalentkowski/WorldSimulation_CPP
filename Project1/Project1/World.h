#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Organism.h"
#include "Interface.h"

#define MAP_POS_X 1
#define MAP_POS_Y 1
#define MAP_SIZE 20
class Organism;
class Interface;
class World
{

private:
	Organism ***map;
	Interface *graphic;
	std::vector<Organism*> organisms_vector;

public:
	World();
	Organism* GetOrganism(int x, int y);

	void DrawBorders();
	void DrawWorld();

	void AddOrganism(Organism *organism);
	void KillOrganism(Organism *to_kill, Organism *killer);
	void EatPlant(Organism *to_eat, Organism *eater);
	void SayAboutDeflection(Organism *deflected);
	void SayAboutEscape(Organism *attacker);
	void SayAboutPower();
	void SayAboutCooldown();

	bool IsOnMap(int x, int y);
	bool IsOccupied(int x, int y);
	bool IsAnyAvailable(int x, int y);
	void SetRandomDirection(int &x, int &y);
	void MoveOrganism(Organism *organism, int x, int y);
	void ClearAfterOrganism(int x, int y);
	void DeleteOrganismFromVector(Organism *to_kill);
	void SortVector();
	void ClearVector();
	void OrderedTurn();
	~World();
};

#endif
