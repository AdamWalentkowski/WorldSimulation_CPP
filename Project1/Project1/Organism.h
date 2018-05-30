#ifndef ORGANISM_H
#define ORGANISM_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "World.h"
#include "Organism.h"

class World;


class Organism
{
protected:
	World &world;
	int pos_x;
	int pos_y;
	int strength;
	int initiative;
	int age;
	char symbol;
	std::string name;
	bool is_dead;

public:
	Organism(World &w, int x, int y);
	int GetPosX();
	int GetPosY();
	int GetStrength();
	int GetInitiative();
	int GetAge();
	char GetSymbol();
	bool GetStatus();
	void SetStatus(bool is_dead);
	void SetStrength(int strength);
	std::string GetName();
	void IncreaseAge(int &age);
	bool CompareStrength(Organism *attacker);
	virtual bool Collision(int x, int y)=0;
	virtual void TakeAction()=0;
};

#endif