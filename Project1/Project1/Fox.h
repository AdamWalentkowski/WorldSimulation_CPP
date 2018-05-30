#ifndef FOX_H
#define FOX_H

#include "Animal.h"

class Fox : public Animal
{
public:
	Fox(World &w, int x, int y);
	virtual void TakeAction() override;
	Animal* GiveBirth(int pos_x, int pos_y) override;

};

#endif