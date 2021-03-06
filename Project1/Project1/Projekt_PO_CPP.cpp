#include "World.h"
#include "Organism.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Man.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "Hogweed.h"

int main()
{
	World world;
	world.AddOrganism(new Wolf(world, 1, 1));
	world.AddOrganism(new Wolf(world, 4, 2));
	world.AddOrganism(new Antelope(world, 10, 11));
	world.AddOrganism(new Sheep(world, 13, 14));
	world.AddOrganism(new Fox(world, 11, 12));
	world.AddOrganism(new Fox(world, 15, 13));
	world.AddOrganism(new Sheep(world, 5, 14));
	world.AddOrganism(new Turtle(world, 17, 12));
	world.AddOrganism(new Grass(world, 1, 7));
	world.AddOrganism(new Guarana(world, 5, 19));
	world.AddOrganism(new Dandelion(world, 15, 12));
	world.AddOrganism(new Belladonna(world, 10, 12));
	world.AddOrganism(new Hogweed(world, 6, 6));
	world.AddOrganism(new Man(world, 9, 9));

	Sleep(1000);
	while (true) {
		system("cls");
		world.DrawBorders();
		world.DrawWorld();
		world.SortVector();
		world.OrderedTurn();
		world.ClearVector();
	}

	

	return 0;
}