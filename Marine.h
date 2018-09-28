#pragma once

class Marine
{
public:
	int health = 50;
	Marine();
	~Marine();
	bool isAlive();
	int attack();
	void takeDamage(int damage);

};

