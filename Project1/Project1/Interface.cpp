#include "Interface.h"

Interface::Interface(World &world) : world(world)
{
	SetTitle("Adam Walentkowski s171717");
	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	i = 0;
}


void Interface::SetTitle(const char *title) {
	SetConsoleTitleA(title);
}

void Interface::Gotoxy(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(output_handle, pos);
}

void Interface::CommentAboutSpawn(Organism *new_organism) {
	Gotoxy(MAP_POS_X + MAP_SIZE + 2, 2 + i);
	std::cout<<"A "<<new_organism->GetName()<<" has been added";
	++i;
}

void Interface::CommentAboutDeath(Organism *prey, Organism *killer) {
	Gotoxy(MAP_POS_X + MAP_SIZE + 2, 2 + i);
	std::cout << "A " << prey->GetName() << " has been slain by a(n) " << killer->GetName();
	++i;
}

void Interface::CommentAboutEater(Organism *food, Organism *eater) {
	Gotoxy(MAP_POS_X + MAP_SIZE + 2, 2 + i);
	std::cout << "A " << eater->GetName() << " has eaten a(n) " << food->GetName();
	++i;
}

void Interface::CommentAboutDeflection(Organism *deflected) {
	Gotoxy(MAP_POS_X + MAP_SIZE + 2, 2 + i);
	std::cout << "A Turtle has deflected the attack of a(n) " << deflected->GetName();
	++i;
}

void Interface::CommentAboutEscape(Organism *attacker) {
	Gotoxy(MAP_POS_X + MAP_SIZE + 2, 2 + i);
	std::cout << "An Antelope has escaped from the combat with a(n) " << attacker->GetName();
	++i;
}

void Interface::CommentAboutPower() {
	Gotoxy(MAP_POS_X + MAP_SIZE + 2, 2 + i);
	std::cout << "A man used his special power, 3(+2) long jumps";
	++i;
	Sleep(2000);
}

void Interface::CommentAboutCooldown() {
	Gotoxy(MAP_POS_X + MAP_SIZE + 2, 2 + i);
	std::cout << "You cannot use man's special power until he cools down";
	++i;
	Sleep(2000);
}

void Interface::ResetComments() {
	i = 0;
}