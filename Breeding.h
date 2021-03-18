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
        static Engimon& breeding (Engimon A, Engimon B) {
        	string nama;
            cout << "Masukkan Nama anakmu : ";
            cin >> nama;
            list <string> parent = {A.getParent(), B.getParent()};
            list <string> skillparent = {A.getSkills(), B.getSkills()};
            vector <string> elementparent = {A.getElement(), B.getElement()};
          
            int healthanak = 0
            if (A.getElement() >= B.getElement()) {
                healthanak = A.getHealth();
            }
            else {
                healthanak = B.getHealth();
            }
        		return (Engimon(nama, parent, skillparent, elementparent, 0, 0, 0, true, healthanak));
        }
}
#endif