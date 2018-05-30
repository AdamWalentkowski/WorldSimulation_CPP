#ifndef INTERFACE_H
#define INTERFACE_H

#include <Windows.h>
#include "World.h"
#include "Organism.h"

class World;
class Organism;

class Interface
{
private:
	HANDLE output_handle;
	World &world;
	int i;
public:
	Interface(World &world);
	void SetTitle(const char *title);
	void Gotoxy(int x, int y);
	void CommentAboutSpawn(Organism *new_organism);
	void CommentAboutDeath(Organism *prey, Organism *killer);
	void CommentAboutEater(Organism *food, Organism *eater);
	void CommentAboutDeflection(Organism *deflected);
	void CommentAboutEscape(Organism *attacker);
	void CommentAboutPower();
	void CommentAboutCooldown();
	void ResetComments();
};

#endif