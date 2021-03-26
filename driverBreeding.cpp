#include "Species.h"
#include "Breeding.h"
#include "Engimon.h"
#include "Skill.h"
#include "CustomException.h"

int main()
{
    SkillsFactory initSkill;
    SpeciesFactory specieses;
    specieses.initSpecies();

    // Engimon
    Breeding breeding;

    
    Engimon C(specieses[0], "Anjing", specieses[0]->getName(), "Anjing2", specieses[0]->getName(), "Kucing",
        31, 0, 3101, true, false);
    Engimon D(specieses[2], "Anjing3", specieses[0]->getName(), "Anjing4", specieses[0]->getName(), "Kucing2",
        31, 0, 3101, true, false);


    Skill skil1 = initSkill[0];
    skil1.setMasteryLevel(2);

    // Skill skil2 = initSkill[4];
    // skil2.setMasteryLevel(1);

    // Skill skil3 = initSkill[2];
    // skil3.setMasteryLevel(3);

    Skill skil4 = initSkill[0];
    skil4.setMasteryLevel(2);

    // Skill skil5 = initSkill[6];
    // skil5.setMasteryLevel(0);

    // Skill skil6 = initSkill[7];
    // skil6.setMasteryLevel(3);

    C.addSkill(skil1);
    // C.addSkill(skil2);
    // C.addSkill(skil3);

    D.addSkill(skil4);
    // D.addSkill(skil5);
    // D.addSkill(skil6);


    
    Engimon e3 = Breeding :: breeding(C, D, specieses);
    cout << e3.getSkills().at(0).getMasteryLevel() << "inii" << endl;
    C.downLevel(30);
    D.downLevel(30);
    

    e3.printDetail();
    C.printDetail();
    D.printDetail();


    // Engimon e3 = Breeding :: breeding(A, B, specieses);
    // A.downLevel(30);
    

    // e3.printDetail();
    // A.printDetail();
    // B.printDetail();

    // g++ -o test driverBreeding.cpp Breeding.cpp Engimon2.cpp Species.cpp Skill.cpp
    return 0;
}