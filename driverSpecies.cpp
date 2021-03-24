#include "Species.h"

int main()
{
    SpeciesFactory specieses;
    SkillsFactory skills;
    specieses.initSpecies();
    
    // test
    // cctor
    Species* s1 (specieses[0]);
    Species* s2 (specieses[0]);
    // delete s1;
    Species** s3 = new Species*(specieses[0]);
    
    delete s3;
    if (s1 == s2) cout << "Sama" << endl;
    cout << s1->getBaseSkill() << endl;
    try{
        specieses.printAllSpecies();   
    }
    catch(exception e)
    {

    }
    // g++ -o test driverSpecies.cpp Species.cpp Skill.cpp
    return 0;
}