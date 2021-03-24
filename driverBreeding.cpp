#include "Species.h"
#include "Breeding.h"
#include "Engimon2.h"

int main()
{
    SkillsFactory initSkill;
    SpeciesFactory specieses;
    specieses.initSpecies();

    // Engimon
    Engimon e1(specieses[0], "Engimon1", specieses[1], "Par1", specieses[2], "Par2", 1, 0, 100, true, false);
    Engimon e2(specieses[1], 1, 99, 100, true, false);
    Engimon e3 = breeding(e1, e2, specieses);

    // g++ -o test driverBreeding.cpp Breeding.cpp Engimon2.cpp Species.cpp
    return 0;
}