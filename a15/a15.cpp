// Client File
// g++ a15.cpp creature.cpp demon.cpp human.cpp elf.cpp cyberdemon.cpp balrog.cpp -o test

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "creature.h"
#include "human.h"
#include "elf.h"
#include "cyberdemon.h"
#include "balrog.h"
using namespace std;
using namespace cs_creature;

void battleArena(Creature& Creature1, Creature& Creature2);
int main() {
    srand(static_cast<unsigned>(time(0)));

    Elf e(50,50);
    Balrog b(50,50);

    battleArena(e, b);  
}

void battleArena(Creature& Creature1, Creature& Creature2) {
    
}














int main()
{
    srand(static_cast<unsigned>(time(0)));
        
    Elf e(50,50);
    Balrog b(50,50);
    
    Elf e2(25, 100);
    Cyberdemon c(20, 100);
    
    Balrog b2(15, 150);
    Cyberdemon c2(20, 200);
    
    Human h(25, 100);
    Elf e3(20, 75);
    
    Human h2(10, 75);
    Balrog b3(10, 50);
    
    Human h3(40, 200);
    Cyberdemon c3(30, 150);
    
    battleArena(e, b); // Elf verse Balrog
    battleArena(e2, c); // Elf verse Cyberdemon
    battleArena(b2, c2); // Balrog verse Cyberdemon
    battleArena(h, e3); // Human verse Elf
    battleArena(h2, b3); // Human verse Balrog
    battleArena(h3, c3); // Human verse Cyberdemon
    
}


void battleArena(Creature &Creature1, Creature &Creature2){
    static int gameCount = 0;
    int roundCount = 0;
    int creature1RemainingHealth, creature2RemainingHealth;
    int creature1TotalDamage, creature2TotalDamage;
    gameCount++;
    do {
        roundCount++;
        if (gameCount == 1 && roundCount == 1){
            cout << "---------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\tGAME " << gameCount << endl;
            cout << "---------------------------------------------------------" << endl;
        } else if (gameCount > 1 && roundCount == 1){
            cout << "\t\t\t\t\t\tGAME " << gameCount << endl;
            cout << "---------------------------------------------------------" << endl;
        }
        if (roundCount > 1){
            cout << "---------------------------------------------------------" << endl;
        }
        cout << "\tRound " << roundCount << ": Battle between "
             << Creature1.getSpecies() << " and " << Creature2.getSpecies()
             << " begins!" << endl;
        cout << "---------------------------------------------------------" << endl;
        creature1TotalDamage = Creature1.getDamage();
        creature2TotalDamage = Creature2.getDamage();
        creature1RemainingHealth =  Creature1.getHitpoints() - creature2TotalDamage;
        creature2RemainingHealth = Creature2.getHitpoints() - creature1TotalDamage;
        cout << "---------------------------------------------------------" << endl;
        cout << "Total damage inflicted by " << Creature1.getSpecies() << ": "
             << creature1TotalDamage << endl;
        cout << "Total damage inflicted by " << Creature2.getSpecies() << ": "
        << creature2TotalDamage << endl;
        cout << "---------------------------------------------------------" << endl;
        Creature1.setHitpoints(creature1RemainingHealth);
        Creature2.setHitpoints(creature2RemainingHealth);
        cout << "Remaining health for " << Creature1.getSpecies() << ": "
             << creature1RemainingHealth << endl;
        cout << "Remaining health for " << Creature2.getSpecies() << ": "
             << creature2RemainingHealth << endl;
    } while (creature1RemainingHealth > 0 && creature2RemainingHealth > 0);
    
    
    if (creature1RemainingHealth <= 0 && creature2RemainingHealth <= 0){
        cout << "---------------------------------------------------------" << endl;
        cout << "The battle between " << Creature1.getSpecies()
             << " and " << Creature2.getSpecies() << " resulted in a tie!" << endl;
        cout << "---------------------------------------------------------" << endl;
    } else if (creature1RemainingHealth <= 0 && creature2RemainingHealth > 0){
        cout << "---------------------------------------------------------" << endl;
        cout << Creature2.getSpecies() << " has defeated " << Creature1.getSpecies()
             << "!" << endl;
        cout << "---------------------------------------------------------" << endl;
    } else if (creature1RemainingHealth > 0 && creature2RemainingHealth <= 0){
        cout << "---------------------------------------------------------" << endl;
        cout << Creature1.getSpecies() << " has defeated " << Creature2.getSpecies()
        << "!" << endl;
        cout << "---------------------------------------------------------" << endl;
    }
}

// Run

/*
 
 
 default Human strength/hitpoints: 10/10
 default Elf strength/hitpoints: 10/10
 default Cyberdemon strength/hitpoints: 10/10
 default Balrog strength/hitpoints: 10/10
 non-default Human strength/hitpoints: 20/30
 non-default Elf strength/hitpoints: 40/50
 non-default Cyberdemon strength/hitpoints: 60/70
 non-default Balrog strength/hitpoints: 80/90
 
 
 Examples of Human damage:
 The Human attacks for 15 points!
 Total damage = 15
 
 The Human attacks for 1 points!
 Total damage = 1
 
 The Human attacks for 14 points!
 Total damage = 14
 
 The Human attacks for 11 points!
 Total damage = 11
 
 The Human attacks for 5 points!
 Total damage = 5
 
 The Human attacks for 14 points!
 Total damage = 14
 
 The Human attacks for 2 points!
 Total damage = 2
 
 The Human attacks for 18 points!
 Total damage = 18
 
 The Human attacks for 7 points!
 Total damage = 7
 
 The Human attacks for 8 points!
 Total damage = 8
 
 
 Examples of Elf damage:
 The Elf attacks for 40 points!
 Total damage = 40
 
 The Elf attacks for 3 points!
 Total damage = 3
 
 The Elf attacks for 17 points!
 Total damage = 17
 
 The Elf attacks for 40 points!
 Total damage = 40
 
 The Elf attacks for 36 points!
 Total damage = 36
 
 The Elf attacks for 28 points!
 Total damage = 28
 
 The Elf attacks for 38 points!
 Magical attack inflicts 38 additional damage points!
 Total damage = 76
 
 The Elf attacks for 12 points!
 Magical attack inflicts 12 additional damage points!
 Total damage = 24
 
 The Elf attacks for 20 points!
 Magical attack inflicts 20 additional damage points!
 Total damage = 40
 
 The Elf attacks for 5 points!
 Magical attack inflicts 5 additional damage points!
 Total damage = 10
 
 
 Examples of Cyberdemon damage:
 The Cyberdemon attacks for 29 points!
 Total damage = 29
 
 The Cyberdemon attacks for 38 points!
 Demonic attack inflicts 50 additional damage points!
 Total damage = 88
 
 The Cyberdemon attacks for 3 points!
 Total damage = 3
 
 The Cyberdemon attacks for 33 points!
 Total damage = 33
 
 The Cyberdemon attacks for 26 points!
 Total damage = 26
 
 The Cyberdemon attacks for 10 points!
 Total damage = 10
 
 The Cyberdemon attacks for 27 points!
 Demonic attack inflicts 50 additional damage points!
 Total damage = 77
 
 The Cyberdemon attacks for 20 points!
 Demonic attack inflicts 50 additional damage points!
 Total damage = 70
 
 The Cyberdemon attacks for 55 points!
 Total damage = 55
 
 The Cyberdemon attacks for 11 points!
 Total damage = 11
 
 
 Examples of Balrog damage:
 The Balrog attacks for 30 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 70 additional damage points!
 Total damage = 150
 
 The Balrog attacks for 66 points!
 Balrog speed attack inflicts 66 additional damage points!
 Total damage = 132
 
 The Balrog attacks for 22 points!
 Balrog speed attack inflicts 71 additional damage points!
 Total damage = 93
 
 The Balrog attacks for 31 points!
 Balrog speed attack inflicts 37 additional damage points!
 Total damage = 68
 
 The Balrog attacks for 79 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 48 additional damage points!
 Total damage = 177
 
 The Balrog attacks for 30 points!
 Balrog speed attack inflicts 26 additional damage points!
 Total damage = 56
 
 The Balrog attacks for 43 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 53 additional damage points!
 Total damage = 146
 
 The Balrog attacks for 6 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 48 additional damage points!
 Total damage = 104
 
 The Balrog attacks for 31 points!
 Balrog speed attack inflicts 22 additional damage points!
 Total damage = 53
 
 The Balrog attacks for 32 points!
 Balrog speed attack inflicts 49 additional damage points!
 Total damage = 81
 
 
 Program ended with exit code: 0
 
 */
