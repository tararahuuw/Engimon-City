#include "Breeding.h"
#include "Skill.h"
#include "Species.h"
#include "Battle.h"

Engimon& Breeding :: breeding (Engimon A, Engimon B, SpeciesFactory specieses) {
    string nama;
    Species* spec;
  
    cout << "Masukkan nama anak : ";
    cin >> nama;
  
  	if (A.getElement() == B.getElement()) {
      	spec = A.getSpecies();
    }
    else
    {
        if (Battle::advantage(A,B,1) > Battle::advantage(A,B,2)) {
      		spec = A.getSpecies();
        }
        else if (Battle::advantage(A,B,1) == Battle::advantage(A,B,2)) {
      		spec = specieses[0];
        }
        else {
      		spec = B.getSpecies();
        }
    }

  	Engimon C(spec, nama, A.getSpecies(), A.getName(), B.getSpecies(), B.getName(),
        skillanak(A, B), 1, 0, 100, true, false);

    // Set ulang atribut parent
    A.downLevel(30);
    B.downLevel(30);
    
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
                n = n - 1;
          		for (int k = j; k < n; k++) {
                  	allSkill[k] = allSkill[k + 1];
                }
            }
        }
    }
  
    getSkill.clear();
    for (int i = 0; i < 4 || i < n; i++) {
        getSkill.push_back(allSkill[i]);
    }
  	return getSkill;
}