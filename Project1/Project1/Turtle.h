#ifndef TURTLE_H
#define TURTLE_H

#include "Animal.h"

class Turtle : public Animal
{
public:
	Turtle(World &w, int x, int y);
	virtual void TakeAction() override;
	virtual bool Collision(int x, int y) override;
	Animal* GiveBirth(int pos_x, int pos_y) override;

};

#endif