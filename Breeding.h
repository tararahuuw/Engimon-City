#ifndef BREEDING_HPP
#define BREEDING_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Engimon2.h"

class Breeding {
    private :
    public :
    	// Asumsi engimon sudah level 30
        static Engimon& breeding (Engimon A, Engimon B, SpeciesFactory specieses);

        vector<Skill> skillanak(Engimon A, Engimon B);


};
#endif