#ifndef HOGWEED_H
#define HOGWEED_H

#include "Plant.h"

class Hogweed : public Plant
{
public:
	Hogweed(World &w, int x, int y);
	virtual void TakeAction() override;
	virtual bool Collision(int x, int y) override;
	void Mayhem();
	Plant* Grow(int pos_x, int pos_y) override;
};

#endif
