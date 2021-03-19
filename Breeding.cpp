#include "Breeding.h"

Engimon& Breeding :: breeding (Engimon A, Engimon B) {
    string nama;
    cout << "Masukkan nama anak : ";
    cin >> nama;

    list <string> parent = {A.getParent(), B.getParent()};
    list <string> skillparent = {A.getSkills(), B.getSkills()};
    vector <string> elementparent = {A.getElement(), B.getElement()};
    
    int healthanak = 0;
    if (A.getElement() >= B.getElement()) {
        healthanak = A.getHealth();
    }
    else {
        healthanak = B.getHealth();
    }

    // Set ulang atribut parent
    A.downLevel(30);
    B.downLevel(30);
    
    return (Engimon(nama, parent, skillparent, elementparent, 1, 0, 0, true, healthanak));
}

string Breeding :: elemenanak(Engimon A, Engimon B) {
    if (A.getElement() == B.getElement()) {
        return A.getElement();
    }
    else
    {
        if (A.getelementadv() > B.getelementadv()) {
            return A.getElement();
        }
        else if (A.getelementadv() == B.getelementadv()) {
            return A.getElement();
        }
        else {
            B.getElement();
        }
    }
}

List& Breeding :: skillanak(Engimon A, Engimon B) {

}