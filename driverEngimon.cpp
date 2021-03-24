#include "Engimon2.h"

int main(){
    SkillsFactory initSkill;
    SpeciesFactory initSpecies;
    initSpecies.initSpecies();

    // Engimon liar
    Engimon e1(initSpecies[0], 1, 0, 0, true, false);
    Engimon e2(initSpecies[1], 1, 99, 100, true, false);
    // Species** meow = new Species*(initSpecies[1]);
    Engimon* e3 = new Engimon(initSpecies[1], 1, 99, 100, true, false);
    cout << *e3 << endl;
    delete e3;
    initSpecies.printAllSpecies();

    // Test addSkill
    try{
        e1.addSkill(initSkill[4]);
        e1.addSkill(initSkill[1]);
        e2.addSkill(initSkill[0]);
    } catch (const char* e){
        cout << e << endl;
    }
    cout << e1 << endl;
    cout << e2 << endl;
    return 0;
}

// g++ -o testEngimon driverEngimon.cpp Engimon2.cpp Skill.cpp Species.cpp