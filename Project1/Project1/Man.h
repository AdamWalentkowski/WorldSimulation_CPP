#ifndef MAN_H
#define MAN_H
#include <conio.h>
#include "Animal.h"

class Man : public Animal
{
private:
	int power_alpha;
	int power_beta;
	int cooldown;
public:
	Man(World &w, int x, int y);
	void TakeStep(int &x, int &y);
	void TurnOnThePower();
	virtual void TakeAction() override;
	virtual bool Collision(int x, int y) override;
	Animal* GiveBirth(int pos_x, int pos_y) override;
};

#endif