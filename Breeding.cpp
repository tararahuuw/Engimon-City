#include "Breeding.h"
#include "Skill.h"
#include "Species.h"

Engimon Breeding :: breeding (Engimon A, Engimon B, SpeciesFactory specieses) {
    string nama;
    Species* spec;
  
    cout << "Masukkan nama anak : ";
    cin >> nama;
    cout << "masuk1" << endl;
  	if (A.getElement().at(0) == B.getElement().at(0)) {
      	spec = A.getSpecies();
        cout << "masuk2" << endl;
    }

    else
    {
      cout << "masukajg" << endl;
        if (advantagebreeding(A,B,1) > advantagebreeding(A,B,2)) {
      		spec = A.getSpecies();
          cout << "masuk3" << endl;
        }
        else if (advantagebreeding(A,B,1) == advantagebreeding(A,B,2)) {
      		spec = specieses[0];
          cout << "masuk4" << endl;
        }
        else {
      		spec = B.getSpecies();
          cout << "masuk5" << endl;
        }
        
    }

    cout << "masuk6" << endl;
  	Engimon C(spec, nama, A.getSpecies()->getName(), A.getName(), B.getSpecies()->getName(), B.getName(),
        skillanak(A, B), 1, 0, 100, true, false);
    cout << "masuk7" << endl;

    // Set ulang atribut parent
    //A.downLevel(30); diluar aja
    //B.downLevel(30);
    
    return C;
}

vector<Skill> Breeding :: skillanak(Engimon A, Engimon B) {
  	int masteryA, masteryB;
    cout << "anjing1" << endl;
    vector<Skill> skillsA = A.getSkills();
    vector<Skill> skillsB = B.getSkills();
    cout << "anjing2" << endl;
  	int n = skillsA.size() + skillsB.size();
    cout << "anjing3" << endl;
    int max;
  	Skill allSkill[n];
  	Skill temp;
  	vector<Skill> getSkill;
  	
  	// Make a new array with all of the skills
	for (int i = 0; i < skillsA.size(); i++) {
      	allSkill[i] = skillsA[i];
    }
    cout << "anjing4" << endl;
	for (int j = 0; j < skillsB.size(); j++) {
      	allSkill[j + skillsA.size()] = skillsB[j];
    }
    cout << "anjing5" << endl;

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

  cout << "anjing6" << endl;

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
    cout << "anjing7" << endl;
  
    getSkill.clear();
    for (int i = 0; i < 4 && i < n; i++) {
        getSkill.push_back(allSkill[i]);
        cout << i << endl;
        cout << "anjingbanget" << endl;
    }
    cout << "anjing8" << endl;
  	return getSkill;
}

float Breeding::advantagebreeding(Engimon& e1,Engimon& e2,int n) {
    int x = 0;
    int y = 0;
    for (auto i = e1.getElement().begin(); i != e1.getElement().end(); ++i) {
        for (auto j = e2.getElement().begin(); i != e2.getElement().end(); ++i) {
            if(table[*i][*j] > x) {
                x = table[*i][*j];
            }
            if(table[*j][*i] > y) {
                y = table[*j][*i];
            }
        }
    }
    if(n == 1) {
        return x;
    }
    else if(n == 2) {
        return y;
    }
}