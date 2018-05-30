#ifndef GUARANA_H
#define GUARANA_H

#include "Plant.h"

class Guarana : public Plant
{
public:
	Guarana(World &w, int x, int y);
	virtual bool Collision(int x, int y) override;
	Plant* Grow(int pos_x, int pos_y) override;
};

#endif