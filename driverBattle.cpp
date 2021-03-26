#include "CustomException.h"
#include "Player.h"
#include "Engimon2.h"
#include "Skill.h"
#include "Species.h"
#include "peta.h"
// g++ driverBattle.cpp Species.cpp Skill.cpp Engimon2.cpp Player.cpp peta.cpp
int main()
{
    Peta peta(14,14);
	peta.BacaFile();
	Player player1(make_pair(13,13), peta);
    SpeciesFactory specieses;
    specieses.initSpecies();

    Engimon e1(specieses[0], 1, 0, 0, true, false);
    Engimon e2(specieses[1], 1, 99, 100, true, false);
    player1.activateEngimon(0);
    player1.battle(e1);


    // Skill skil1 = initSkill[0];
    // skil1.setMasteryLevel(2);

    // Skill skil2 = initSkill[4];
    // skil2.setMasteryLevel(1);

    // Skill skil3 = initSkill[2];
    // skil3.setMasteryLevel(3);

    // Skill skil4 = initSkill[5];
    // skil4.setMasteryLevel(4);

    // Skill skil5 = initSkill[6];
    // skil5.setMasteryLevel(0);

    // Skill skil6 = initSkill[7];
    // skil6.setMasteryLevel(3);

    // C.addSkill(skil1);
    // C.addSkill(skil2);
    // C.addSkill(skil3);

    // D.addSkill(skil4);
    // D.addSkill(skil5);
    // D.addSkill(skil6);

    
   
    return 0;
}