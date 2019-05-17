#include <iostream>
#include "human.h"
using namespace std;

namespace cs_creature {
	Human::Human()
	: Creature() {
	}

	Human::Human (int newStrength, int newHitpoints)
	: Creature(newStrength, newHitpoints) {
	}

	string Human::getSpecies() const {
		return "Human";
	}
}