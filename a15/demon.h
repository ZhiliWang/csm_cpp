#ifndef DEMON_H
#define DEMON_H


#include <string>
#include "creature.h"

namespace cs_creature {
	class Demon : public Creature {
	public:
		Demon();
		Demon(int newStrength, int newHitpoints);
		std::string getSpecies() const; 
		int getDamage() const;
	};
}
#endif