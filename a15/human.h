#ifndef HUMAN_H
#define HUMAN_H


#include <string>
#include "creature.h"

namespace cs_creature {
	class Human : public Creature {
	public:
		Human();
		Human(int newStrength, int newHitpoints);
		std::string getSpecies() const; 
		
		// just in-case humans get a buff later:
		//int getDamage() const; 
	};
}
#endif