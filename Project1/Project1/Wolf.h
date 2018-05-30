#ifndef WOLF_H
#define WOLF_H

#include "Animal.h"

class Wolf : public Animal
{
public:
	Wolf(World &w, int x, int y);
	Animal* GiveBirth(int pos_x, int pos_y) override;

};

#endif