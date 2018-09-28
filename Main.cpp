// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include "Marine.h"
#include "Zergling.h"


using std::cout;
using std::endl;
// Is there a Marine Alive?
bool marineAlive(int squadsize);


// Is there a zergling Alive
bool zerglingAlive(int squadsize);


int main()
{
	int MsquadSize = 10;
	int ZsquadSize = 20;
	int currentmarine = 0;
	int currentzerg = 0;
	Marine squad[10];
	Zergling swarm[20];

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(MsquadSize) || zerglingAlive(ZsquadSize)) // If anyone is left alive to fight . . .
	{
		if (marineAlive(MsquadSize)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < MsquadSize; i++) // go through the squad
			{
				// each marine will attack the first zergling in the swarm
				if (ZsquadSize > 0) 
				{
					cout << "A marine fires for " << squad[i].attack() << " damage. " << endl;
					int damage = squad[i].attack();
					swarm[currentzerg].takeDamage(damage);
					if (!swarm[currentzerg].isAlive()) // if the zergling dies, it is marked as such
					{
						cout << "The zergling target dies" << endl;
						++currentzerg;
						--ZsquadSize;
						cout << "There are " << ZsquadSize << " zerglings left." << endl;
					}
				}
			}
		}
		if (zerglingAlive(ZsquadSize)) // if there's at least one zergling alive
		{
			for (int i = 0; i < ZsquadSize; i++) // loop through zerglings
			{
				if (MsquadSize > 0)
				{
					cout << "A zergling attacks for " << swarm[currentzerg].attack() << " damage." << endl;
					squad[currentmarine].takeDamage(swarm[currentzerg].attack());
					if (!squad[currentmarine].isAlive())
					{
						cout << "The marine succumbs to his wounds." << endl;
						++currentmarine;
						--MsquadSize;
						cout << "There are " << MsquadSize << " marines left." << endl;
					}
				}
			}
		}
		if (ZsquadSize <= 0)
		{
			cout << "The fight is over. ";
			cout << "The Marines win." << endl;
			system("pause");
			return 0;
		}
		else if (MsquadSize <= 0)
		{
			cout << "The fight is over. ";
			cout << "The Zerg win." << endl;
			system("pause");
			return 0;
		}
	}


	// Once one team is completely eliminated, the fight ends and one team wins
	
	
}

// Is there a Marine Alive?
bool marineAlive(int squadsize)
{
	if (squadsize > 0) 
	{
		return true;
	}
	return false;
}

// Is there a zergling Alive
bool zerglingAlive(int squadsize)
{
	if (squadsize > 0)
	{
		return true;
	}
	return false;
}
