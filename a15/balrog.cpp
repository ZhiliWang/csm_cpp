#include <iostream>
#include "balrog.h"
using namespace std;

namespace cs_creature {
	Balrog::Balrog()
	: Demon() {
	}

	Balrog::Balrog (int newStrength, int newHitpoints)
	: Demon(newStrength, newHitpoints) {
	}

	string Balrog::getSpecies() const {
		return "Balrog";
	}

	int Balrog::getDamage() const {
		int damage;
		int damage2 = (rand() % getStrength()) + 1;
		damage = Demon::getDamage();

		cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
		damage += damage2;
	
		return damage;
	}
}