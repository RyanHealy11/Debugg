#pragma once

class Zergling
{
public:
	Zergling();
	~Zergling();
	int health = 800;
	bool isAlive();
	int attack();
	void takeDamage(int damage);

};

