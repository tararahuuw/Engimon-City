#ifndef BREEDING_HPP
#define BREEDING_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Engimon2.h"

const float table[5][5] = {{1,0,1,0.5,2},{2,1,0,1,1},{1,2,1,0,1.5},{1.5,1,2,1,0},{0,1,0.5,2,1}};

class Breeding {
    private :
    public :
    	// Asumsi engimon sudah level 30
        static Engimon breeding (Engimon A, Engimon B, SpeciesFactory specieses);

        static vector<Skill> skillanak(Engimon A, Engimon B);

};
#endif