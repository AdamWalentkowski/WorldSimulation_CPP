#ifndef SHEEP_H
#define SHEEP_H

#include "Animal.h"

class Sheep : public Animal
{
public:
	Sheep(World &w, int x, int y);
	Animal* GiveBirth(int pos_x, int pos_y) override;
};

#endif