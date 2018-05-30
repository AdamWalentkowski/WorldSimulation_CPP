#ifndef ANIMAL_H
#define ANIMAL_H

#include "World.h"
#include "Organism.h"

class Animal : public Organism {
protected:
	Animal(World &w, int x, int y);
	virtual void TakeAction() override;
	virtual bool Collision(int x, int y) override;
	void Procreate();
	virtual Animal *GiveBirth(int x, int y)=0;
};

#endif