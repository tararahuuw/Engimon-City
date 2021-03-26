#include "Engimon2.h"

int main(){
    SkillsFactory initSkill;
    SpeciesFactory initSpecies;
    initSpecies.initSpecies();

    // Engimon liar
    Engimon e1(initSpecies[0], 40, 0, 0, true, true);
    Engimon e2(initSpecies[1], 1, 99, 100, true, true);
    // Species** meow = new Species*(initSpecies[1]);
    Engimon* e3 = new Engimon(initSpecies[1], 1, 99, 100, true, false);
    // cout << *e3 << endl;
    delete e3;
    // initSpecies.printAllSpecies();
    Engimon D(initSpecies[1], "Anjing3", initSpecies[0]->getName(), "Anjing4", initSpecies[0]->getName(), "Kucing2",
        31, 0, 3101, false, false);

    // Test addSkill
    e1.downLevel(30);
    try{
        e1.addSkill(initSkill[4]);
        e1.addSkill(initSkill[1]);
        e2.addSkill(initSkill[0]);
    } catch (exception& e){
        cout << e.what() << endl;
    }
    cout << e1 << endl;
    cout << e2 << endl;
    e1.printDetail();
    cout << endl;
    D.printDetail();

    return 0;
}

// g++ -o testEngimon driverEngimon.cpp Engimon2.cpp Skill.cpp Species.cpp