#include "Breeding.h"
#include "Skill.h"

Engimon& Breeding :: breeding (Engimon A, Engimon B) {
    string nama;
  	Engimon C;
  
    cout << "Masukkan nama anak : ";
    cin >> nama;
	
  	C.setName(nama);
    C.setParent(A.getSpesies(),A.getParent(), B.getSpesies(), B.getParent()); //katanya headernya mau diubah
  
  	C.setSkills(skillanak(A,B));
  
  	if (A.getElement() == B.getElement()) {
        C.setElements(A.getElement());
      	C.setSpesies(A.getSpesies());
    }
    else
    {
        if (Battle::advantage(A,B,1) > Battle::advantage(A,B,2)) {
            C.setElements(A.getElement());
      		C.setSpesies(A.getSpesies());
        }
        else if (A.getelementadv() == B.getelementadv()) {
            C.setElements(A.getElement());
      		C.setSpesies("Pikachu");
        }
        else {
            C.setElements(B.getElement());
      		C.setSpesies(B.getSpesies());
        }
    }
  
    C.setLevel(1);
    C.setEXP(0);
    C.setCumulativeEXP(100);
    C.setStatus(true);

    // Set ulang atribut parent
    A.downLevel(30);
    B.downLevel(30);
  	A.setEXP(0);
    B.setEXP(0);
    A.setCumulativeEXP(A.getCumulativeEXP() -  3000);
    B.setCumulativeEXP(A.getCumulativeEXP() -  3000);
    
    return C;
}

Vector& Breeding :: skillanak(Engimon A, Engimon B) {
  	int masteryA, masteryB;
  	int n = A.skills.size() + B.skills.size();
    int max;
  	Skill allSkill[n];
  	Skill temp;
  	vector<Skill> getSkill;
  	
  	// Make a new array with all of the skills
	for (int i = 0; i < A.skills.size(); i++) {
      	allSkill[i] = A.skills[i];
    }
	for (int j = 0; j < B.skills.size(); j++) {
      	allSkill[j + A.skills.size()] = B.skills[j];
    }

  	// Sort all skills according to mastery level
	for (int i = 0; i < n - 1; i++) {
		max = i;
		for (int j = i + 1; j < n; j++) {
            masteryA = allSkill[max].getMasteryLevel;
            masteryB = allSkill[j].getMasteryLevel;
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