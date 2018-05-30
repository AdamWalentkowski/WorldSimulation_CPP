#ifndef BELLADONNA_H
#define BELLADONNA_H

#include "Plant.h"

class Belladonna : public Plant
{
public:
	Belladonna(World &w, int x, int y);
	virtual bool Collision(int x, int y) override;
	Plant* Grow(int pos_x, int pos_y) override;
};

#endif
