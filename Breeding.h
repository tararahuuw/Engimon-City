#ifndef BREEDING_HPP
#define BREEDING_HPP

#include <iostream>
#include <string>
#include <list>
#include "Engimon.hpp"

class Breeding {
    private :
    public :
    	// Asumsi engimon sudah level 30
        static Engimon& breeding (Engimon A, Engimon B);

        string elemenanak(Engimon A, Engimon B);

        List& skillanak(Engimon A, Engimon B);


};
#endif