#ifndef DANDELION_H
#define DANDELION_H

#include "Plant.h"

class Dandelion : public Plant
{
public:
	Dandelion(World &w, int x, int y);
	virtual void TakeAction() override;
	Plant* Grow(int pos_x, int pos_y) override;

};

#endif