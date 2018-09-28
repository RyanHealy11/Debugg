#include "Zergling.h"



Zergling::Zergling()
{
}


Zergling::~Zergling()
{
}

bool Zergling::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Zergling::attack()
{
	return 1;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
	}
}
