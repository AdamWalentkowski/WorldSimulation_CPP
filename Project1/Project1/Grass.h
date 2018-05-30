#ifndef GRASS_H
#define GRASS_H

#include "Plant.h"

class Grass : public Plant
{
public:
	Grass(World &w, int x, int y);
	Plant* Grow(int pos_x, int pos_y) override;
};

#endif