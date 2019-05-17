#ifndef CREATURE_H
#define CREATURE_H

#include <string>

namespace cs_creature {
    class Creature {

        
        public:
            Creature();             // initialize to Human, 10 strength, 10 hitpoints
            Creature(int newStrength, int newHitpoints);
            
            virtual std::string getSpecies() const = 0; // returns the type of species
            virtual int getDamage() const;         // returns the amount of damage this Creature
                                     // inflicts in one round of combat
              
            int getStrength() const;    // returns the maximum damage this Creature can inflict
            int getHitpoints() const;   // returns the amount of health this Creature has
            void setStrength(int updatedStrength); // sets the Creature's Strength
            void setHitpoints(int updatedHitPoints); // sets the Creature's Health 





        private:
            int strength;           // how much damage this Creature inflicts
            int hitpoints;          // how much damage this Creature can sustain

            // for my own updates later:
            //int type;               // 0 Human, 1 Cyberdemon, 2 Balrog, 3 elf
            //string getSpecies() const;    // returns the type of the species
    };
}
#endif