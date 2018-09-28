#include "Marine.h"



Marine::Marine()
{
	 health = 50;
}


Marine::~Marine()
{
}

bool Marine::isAlive()
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

int Marine::attack()
{
	return 61;
}

void Marine::takeDamage(int damage)
{
	health -= damage;
}
