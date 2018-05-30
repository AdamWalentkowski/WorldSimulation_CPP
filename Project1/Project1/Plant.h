#ifndef PLANT_H
#define PLANT_H

#include "World.h"
#include "Organism.h"

class Plant : public Organism {
public:
	Plant(World &w, int x, int y);
	virtual void TakeAction() override;
	virtual bool Collision(int x, int y) override;
	void Spread();
	virtual Plant *Grow(int x, int y)=0;
};

#endif
