#include <iostream>
#include "demon.h"
using namespace std;

namespace cs_creature {
	Demon::Demon()
	: Creature() {
	}

	Demon::Demon (int newStrength, int newHitpoints)
	: Creature(newStrength, newHitpoints) {
	}

	string Demon::getSpecies() const {
		return "Demon";
	}

	int Demon::getDamage() const {
		int damage;
		
		damage = Creature::getDamage();

		if((rand() % 4) == 0) {
			damage += 50;
			cout << "Demonic attack inflicts 50 additional damage points!" << endl;
		}

		return damage;
	}
}