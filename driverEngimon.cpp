#include "Engimon.h"

int main(){
    KatalogEngimon engimons;
    KatalogSkill skills;

    cout << "==========1============" << endl;

    engimons.printKatalogEngimon();
    cout << skills[8];
    engimons[1].addSkills(skills[8]);
    engimons[1].addEXP(210);
    engimons[1].addSkills(skills[9]);
    
    cout << endl << "==========2============" << endl;
    engimons.printKatalogEngimon();
    engimons[0].dropSkills(skills[8]);

    cout << endl << "==========3============" << endl;

    engimons.printKatalogEngimon();

    return 0;
}

// g++ -o testEngi driverEngimon.cpp Engimon.cpp Skill.cpp