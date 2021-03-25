#include "Player.h"
#include <bits/stdc++.h>

using namespace std;


// Player:: Player(){
// 	this->coordinate = make_pair(0,0);
// 	this->listEngimon = Inventory<Engimon>();
// 	this->listSkillItem = Inventory<Skill>();
// }
//no need dest
// Player::~Player(){
// 	this->listEngimon.
// }
Player::Player(pair<int,int> Coordinate, const Peta& p){
	this->coordinate = Coordinate;
	this->listEngimon = Inventory<Engimon>();
	this->listSkillItem = Inventory<Skill>();
	this->peta = p;
	this->isThereActiveEngimon = false;
	this->activeEngimon = Engimon();
	SkillsFactory katalogskill;
	Skill agni = katalogskill[2];
	Skill listrik = katalogskill[6];
	Skill toya = katalogskill[14];
	SpeciesFactory katalogspecies;
	katalogspecies.initSpecies();
	Species* A = katalogspecies[0];
	Species* L = katalogspecies[2];
	Species* T = katalogspecies[1];
	Engimon Alam(A, "Alam", "", "", "", "", 1, 0, 0, false, false);
	Engimon Chelsie(L, "Chelsie", "", "", "", "", 1,0,0,false, false);
	Engimon Monica(T, "Monica", "", "", "", "", 1, 0, 0, false, false);
	this->addEngimonToInven(Alam);
	this->addEngimonToInven(Chelsie);
	this->addEngimonToInven(Monica);
	this->addSkillItemToInven(agni);
	this->addSkillItemToInven(listrik);
	this->addSkillItemToInven(toya);
	this->coorActive = make_pair(-1,-1); //selama belum diaktifin, jadi -1 aja;
	this->peta.SetElementPeta(this->coordinate.first,this->coordinate.second,'P');
	//starter pack here
	//3 engimon (?)
	//3 proper item skills (?)
}

void Player::activateEngimon(int idx){
	Engimon dummy;
	try{
		this->listEngimon.getElementX(idx);
		// Species* tes = dummy.getSpecies();
		// if (tes->isSingleElement()) cout <<"salahku apa?" << endl;
	}catch (exception& e){
		throw InvalidEngimonException(); 
	}

	dummy = this->listEngimon.getElementX(idx);
	if (this->isThereActiveEngimon){
		this->listEngimon.setElementX(this->activeEngimon, idx); //no exception guaranteed if this line executed
		//already checked using getelementx
		this->activeEngimon = dummy;
	}else{
		// cout << "THERE" << endl;
		this->relocateAE();
		this->activeEngimon = dummy;
		this->listEngimon.delElementIndexX(idx);
	}
	this->isThereActiveEngimon = true;
	
}

void Player:: learnSkill(int idx){
	if (this->isThereActiveEngimon){
		this->activeEngimon.addSkill(this->listSkillItem.getSkillX(idx));
	//these lines below will be executed if there is no exception throwed
		this->listSkillItem.delElement(this->listSkillItem.getSkillX(idx));
	}else throw ActiveEngimonKosong();
}

// no need
int Player:: getXCoordinate(){
	return this->coordinate.second;
}

int Player:: getYCoordinate(){
	return this->coordinate.first;
}

int Player:: getXCoorAE(){
	return this->coorActive.second;
}

int Player:: getYCoorAE(){
	return this->coorActive.first;
}

Inventory<Skill> Player::getListSkill(){
	return this->listSkillItem;
}
Inventory<Engimon> Player::getListEng(){
	return this->listEngimon;
}

void Player:: viewListSkill(){
	this->listSkillItem.viewList();
}

void Player:: viewListEngimon(){
	this->listEngimon.viewList();
}

void Player:: addEngimonToInven(const Engimon& other){
	this->listEngimon.addElement(other);
}
void Player:: addSkillItemToInven(Skill& other){
	this->listSkillItem.addElement(other);
}

bool Player:: isThereActiveEngimonYet(){
	return this->isThereActiveEngimon;
}

Engimon Player:: getActiveEngimon(){
	if (!this->isThereActiveEngimonYet()) throw ActiveEngimonKosong();
	return this->activeEngimon;
}

void Player:: moveW(){
	int y = this->coordinate.first;
	int x = this->coordinate.second;
	if (y - 1 >= 0 and (this->peta.GetElementPeta(y-1,x) == '-' or this->peta.GetElementPeta(y-1, x) == 'o' or this->peta.GetElementPeta(y-1,x)=='X')){
		
		// if (this->isThereActiveEngimonYet()){
		// 	this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second, this->peta.GetElementPetaTetap(this->coorActive.first, this->coorActive.second));
		// 	this->coorActive = make_pair(y,x);
		// 	this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second,'X');
		// }else{
		// 	this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		// }
		this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		this->coordinate.first = y-1;
		this->peta.SetElementPeta(y-1,x,'P');
		
	}else throw InvalidMove();
}
void Player:: moveA(){
	int y = this->coordinate.first;
	int x = this->coordinate.second;
	if (x - 1 >= 0 and (this->peta.GetElementPeta(y,x-1) == '-' or this->peta.GetElementPeta(y, x-1) == 'o' or this->peta.GetElementPeta(y,x-1)=='X')){
		
		// if (this->isThereActiveEngimonYet()){
		// 	this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second, this->peta.GetElementPetaTetap(this->coorActive.first, this->coorActive.second));
		// 	this->coorActive = make_pair(y,x);
		// 	this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second,'X');
		// }else{
		// 	this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		// }
		this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		this->coordinate.second = x-1;
		this->peta.SetElementPeta(y,x-1,'P');
	}else throw InvalidMove();
}
void Player:: moveD(){
	int y = this->coordinate.first;
	int x = this->coordinate.second;
	if (x + 1 < this->peta.GetKolom() and (this->peta.GetElementPeta(y,x+1) == '-' or this->peta.GetElementPeta(y, x+1) == 'o' or this->peta.GetElementPeta(y,x+1)=='X')){
		
		// if (this->isThereActiveEngimonYet()){
		// 	this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second, this->peta.GetElementPetaTetap(this->coorActive.first, this->coorActive.second));
		// 	this->coorActive = make_pair(y,x);
		// 	this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second,'X');
		// }else{
		// 	this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		// }
		this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		this->coordinate.second = x+1;
		this->peta.SetElementPeta(y,x+1, 'P');
	}else throw InvalidMove();
}
void Player:: moveS(){
	int y = this->coordinate.first;
	int x = this->coordinate.second;
	if (y + 1 < this->peta.GetBaris() and (this->peta.GetElementPeta(y+1,x) == '-' or this->peta.GetElementPeta(y+1, x) == 'o' or this->peta.GetElementPeta(y+1,x)=='X')){
		
		// if (this->isThereActiveEngimonYet()){
		// 	this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second, this->peta.GetElementPetaTetap(this->coorActive.first, this->coorActive.second));
		// 	this->coorActive = make_pair(y,x);
		// 	this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second,'X');
		// }else{
		// 	this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		// }
		this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		this->coordinate.first = y+1;
		this->peta.SetElementPeta(y+1,x,'P');
	}else throw InvalidMove();

}

void Player:: moveAE(string move){
	bool exc = false;
	int y = this->coordinate.first;
	int x = this->coordinate.second;
	

	if (move == "D" or move == "d"){
		if (this->peta.GetElementPeta(y,x-1) != '-' and this->peta.GetElementPeta(y,x-1) != 'o'){
			exc = true;
		}else{
			if (this->coorActive.first != y or this->coorActive.second != x) this->peta.SetElementPeta(coorActive.first,coorActive.second,this->peta.GetElementPetaTetap(coorActive.first,coorActive.second));
			this->coorActive = make_pair(y,x-1);
			this->peta.SetElementPeta(y,x-1, 'X');
		}
	}else if (move == "S" or move == "s"){
		if (this->peta.GetElementPeta(y-1,x) != '-' and this->peta.GetElementPeta(y-1,x) != 'o'){
			exc = true;
		}else{
			if (this->coorActive.first != y or this->coorActive.second != x) this->peta.SetElementPeta(coorActive.first,coorActive.second,this->peta.GetElementPetaTetap(coorActive.first,coorActive.second));
			this->coorActive = make_pair(y-1,x);
			this->peta.SetElementPeta(y-1,x,'X');
		}
	}else if (move == "A" or move == "a"){
		if (this->peta.GetElementPeta(y,x+1) != '-' and this->peta.GetElementPeta(y,x+1) != 'o'){
			exc = true;
		}else{
			if (this->coorActive.first != y or this->coorActive.second != x) this->peta.SetElementPeta(coorActive.first,coorActive.second,this->peta.GetElementPetaTetap(coorActive.first,coorActive.second));
			this->coorActive = make_pair(y,x+1);
			this->peta.SetElementPeta(y,x+1,'X');
		}
	}else if (move == "W" or move == "w"){
		if (this->peta.GetElementPeta(y+1,x) != '-' and this->peta.GetElementPeta(y+1,x) != 'o'){
			exc = true;
		}else{
			if (this->coorActive.first != y or this->coorActive.second != x) this->peta.SetElementPeta(coorActive.first,coorActive.second,this->peta.GetElementPetaTetap(coorActive.first,coorActive.second));
			this->coorActive = make_pair(y+1,x);
			this->peta.SetElementPeta(y+1,x, 'X');
		}
	}

	if (exc) throw InvalidMoveEngimon();
}

void Player:: lihatPeta(){
	this->peta.PrintPeta();
}

// Peta Player::getPeta(){
// 	return this->peta;
// }

void Player:: relocateAE(){
	int y = this->coordinate.first;
	int x = this->coordinate.second;
	bool found = true;
	int a;
	int b;
	if (y+1 < this->peta.GetBaris() and (this->peta.GetElementPeta(y+1,x) == '-' or this->peta.GetElementPeta(y+1,x) == 'o')){
		a = y+1;
		b = x;
	}else if (x + 1 < this->peta.GetKolom() and (this->peta.GetElementPeta(y,x+1) == '-' or this->peta.GetElementPeta(y,x+1) == 'o')){
		a = y;
		b = x+1;
	}else if (x - 1 >= 0 and (this->peta.GetElementPeta(y,x-1) == '-' or this->peta.GetElementPeta(y,x-1) == 'o')){
		a = y;
		b = x-1;
	}else if (y - 1 >= 0 and (this->peta.GetElementPeta(y-1,x) == '-' or this->peta.GetElementPeta(y-1, x) == 'o')){
		a =  y-1;
		b = x;
	}else if (y+1 < this->peta.GetBaris() and x + 1 < this->peta.GetKolom() and (this->peta.GetElementPeta(y+1,x+1) == '-' or this->peta.GetElementPeta(y+1,x+1) == 'o')){
		a = y+1;
		b = x+1;
	}else if (y+1 < this->peta.GetBaris() and x - 1 >= 0 and (this->peta.GetElementPeta(y+1,x-1) == '-' or this->peta.GetElementPeta(y+1,x-1) == 'o')){
		a = y + 1;
		b = x-1;
	}else if (y - 1 >= 0 and x + 1 < this->peta.GetKolom() and (this->peta.GetElementPeta(y-1,x+1) == '-' or this->peta.GetElementPeta(y-1,x+1) == 'o')){
		a = y-1;
		b = x+1;
	}else if (y - 1 >= 0 and x - 1 >= 0 and (this->peta.GetElementPeta(y-1,x-1) == '-' or this->peta.GetElementPeta(y-1,x-1) == 'o')){
		a = y-1;
		b = x-1;
	}
	else{
		found = false;
		a=y;
		b=x; //kasus khusus ketika tidak ada tiles yang tepat, engimon tidak akan muncul di peta;
	}
	this->coorActive = make_pair(a,b);
	if (found) this->peta.SetElementPeta(a,b,'X');
}

void Player:: spawn(){
	this->peta.SpawnEngimon();
}
void Player:: randomMove(){
	this->peta.GerakinSemuaEngimon();
}

void Player :: breeding (int Index1, int Index2) {
    string nama;
    Species* spec;
	SpeciesFactory specieses;
    specieses.initSpecies();

	Engimon A = this->listEngimon.getElementX(Index1);
	Engimon B = this->listEngimon.getElementX(Index2);
  
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
    
	addEngimonToInven(C);
}

vector<Skill> Player :: skillanak(Engimon A, Engimon B) {
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