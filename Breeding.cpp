#include "Breeding.h"
#include "Skill.h"
#include "Species.h"

Engimon Breeding :: breeding (Engimon A, Engimon B, SpeciesFactory specieses) {
    string nama;
    Species* spec;
  
    cout << "Masukkan nama anak : ";
    cin >> nama;
  	if (A.getElement().at(0) == B.getElement().at(0)) {
      	spec = A.getSpecies();
    }

    else
    {
      
        if (A.getAdvantageElement(B.getElement().at(0)) > B.getAdvantageElement(A.getElement().at(0))) {
      		spec = A.getSpecies();
        }
        else if (A.getAdvantageElement(B.getElement().at(0)) == B.getAdvantageElement(A.getElement().at(0))) {
          if ((A.getSpecies()->hasElement(fire) && B.getSpecies()->hasElement(electric)) ||
              (B.getSpecies()->hasElement(fire) && A.getSpecies()->hasElement(electric))) {
                  spec = specieses[5];
              }
          else if ((A.getSpecies()->hasElement(water) && B.getSpecies()->hasElement(ice)) ||
              (B.getSpecies()->hasElement(water) && A.getSpecies()->hasElement(ice))) {
                  spec = specieses[6];
              }
          else if ((A.getSpecies()->hasElement(water) && B.getSpecies()->hasElement(ground)) ||
              (B.getSpecies()->hasElement(water) && A.getSpecies()->hasElement(ground))) {
                  spec = specieses[7];
              }
          }
  
        else {
      		spec = B.getSpecies();
        }
        
    }

  	Engimon C(spec, nama, A.getSpecies()->getName(), A.getName(), B.getSpecies()->getName(), B.getName(),
        skillanak(A, B), 1, 0, 100, true, false);
    
    return C;
}

vector<Skill> Breeding :: skillanak(Engimon A, Engimon B) {
  	int masteryA, masteryB;
    vector<Skill> skillsA = A.getSkills();
    vector<Skill> skillsB = B.getSkills();
  	int n = skillsA.size() + skillsB.size();
    int max;
  	Skill allSkill[n];
  	Skill temp;
  	vector<Skill> getSkill;
  	
  	// Make a new array with all of the skills
	for (int i = 0; i < skillsA.size(); i++) {
      	allSkill[i] = skillsA[i];
    }
	for (int j = 0; j < skillsB.size(); j++) {
      	allSkill[j + skillsA.size()] = skillsB[j];
    }

  	// Sort all skills according to mastery level
	for (int i = 0; i < n - 1; i++) {
		max = i;
		for (int j = i + 1; j < n; j++) {
            masteryA = allSkill[max].getMasteryLevel();
            masteryB = allSkill[j].getMasteryLevel();
            if (masteryA < masteryB)
                max = j;
        }
        temp = allSkill[i];
        allSkill[i] = allSkill[max];
        allSkill[max] = temp;
    }


   // Remove duplicate skills
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
            if (allSkill[i] == allSkill[j]) {   
                int mastery = allSkill[i].getMasteryLevel() + 1;
                allSkill[i].setMasteryLevel(mastery);
                n = n - 1;
          		for (int k = j; k < n; k++) {
                  	allSkill[k] = allSkill[k + 1];
                }
            }
        }
    }
  
    getSkill.clear();
    for (int i = 0; i < 4 && i < n; i++) {
        getSkill.push_back(allSkill[i]);
    }
  	return getSkill;
}

// int Breeding :: getindexelement(Engimon A) {
//   SpeciesFactory specieses;
//   specieses.initSpecies();

//   for (int i = 0; i < specieses; i++) {

//   }
// }