#ifndef CYBERDEMON_H
#define CYBERDEMON_H


#include <string>
#include "demon.h"

namespace cs_creature {
	class Cyberdemon : public Demon {
	public:
		Cyberdemon();
		Cyberdemon(int newStrength, int newHitpoints);
		std::string getSpecies() const; 
		// we will give cyberdemon a buff later:
		//int getDamage() const;
	};
}
#endif