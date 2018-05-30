#ifndef ANTELOPE_H
#define ANTELOPE_H

#include "Animal.h"

class Antelope : public Animal
{
public:
	Antelope(World &w, int x, int y);
	virtual void TakeAction() override;
	virtual bool Collision(int x, int y) override;
	Animal* GiveBirth(int pos_x, int pos_y) override;
};

#endif