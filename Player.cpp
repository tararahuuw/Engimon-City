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
		int y = this->coordinate.first;
		int x = this->coordinate.second;
		if (y+1 < this->peta.GetBaris() and (this->peta.GetElementPeta(y+1,x) == '-' or this->peta.GetElementPeta(y+1,x) == 'o')){
			this->coorActive = make_pair(y+1,x);
			this->peta.SetElementPeta(y+1,x,'X');
		}else if (x + 1 < this->peta.GetKolom() and (this->peta.GetElementPeta(y,x+1) == '-' or this->peta.GetElementPeta(y,x+1) == 'o')){
			this->coorActive = make_pair(y, x+1);
			this->peta.SetElementPeta(y,x+1,'X');
		}else if (x - 1 >= 0 and (this->peta.GetElementPeta(y,x-1) == '-' or this->peta.GetElementPeta(y,x-1) == 'o')){
			this-> coorActive = make_pair(y, x-1);
			this->peta.SetElementPeta(y,x-1,'X');
		}else if (y - 1 >= 0 and (this->peta.GetElementPeta(y-1,x) == '-' or this->peta.GetElementPeta(y-1, x) == 'o')){
			this->coorActive = make_pair(y-1,x);
			this->peta.SetElementPeta(y-1,x,'X');
		}else{
			this -> coorActive = make_pair(y,x); //kasus khusus ketika tidak ada tiles yang tepat, engimon tidak akan muncul di peta;
		}
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

//no need
// int Player:: getXCoordinate(){
// 	return this->coordinate.first;
// }

// int Player:: getYCoordinate(){
// 	return this->coordinate.second;
// }

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
		
		if (this->isThereActiveEngimonYet()){
			this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second, this->peta.GetElementPetaTetap(this->coorActive.first, this->coorActive.second));
			this->coorActive = make_pair(y,x);
			this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second,'X');
		}else{
			this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		}
		this->coordinate.first = y-1;
		this->peta.SetElementPeta(y-1,x,'P');
		
	}else throw InvalidMove();
}
void Player:: moveA(){
	int y = this->coordinate.first;
	int x = this->coordinate.second;
	if (x - 1 >= 0 and (this->peta.GetElementPeta(y,x-1) == '-' or this->peta.GetElementPeta(y, x-1) == 'o' or this->peta.GetElementPeta(y,x-1)=='X')){
		
		if (this->isThereActiveEngimonYet()){
			this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second, this->peta.GetElementPetaTetap(this->coorActive.first, this->coorActive.second));
			this->coorActive = make_pair(y,x);
			this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second,'X');
		}else{
			this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		}
		this->coordinate.second = x-1;
		this->peta.SetElementPeta(y,x-1,'P');
	}else throw InvalidMove();
}
void Player:: moveD(){
	int y = this->coordinate.first;
	int x = this->coordinate.second;
	if (x + 1 < this->peta.GetKolom() and (this->peta.GetElementPeta(y,x+1) == '-' or this->peta.GetElementPeta(y, x+1) == 'o' or this->peta.GetElementPeta(y,x+1)=='X')){
		
		if (this->isThereActiveEngimonYet()){
			this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second, this->peta.GetElementPetaTetap(this->coorActive.first, this->coorActive.second));
			this->coorActive = make_pair(y,x);
			this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second,'X');
		}else{
			this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		}
		this->coordinate.second = x+1;
		this->peta.SetElementPeta(y,x+1, 'P');
	}else throw InvalidMove();
}
void Player:: moveS(){
	int y = this->coordinate.first;
	int x = this->coordinate.second;
	if (y + 1 < this->peta.GetBaris() and (this->peta.GetElementPeta(y+1,x) == '-' or this->peta.GetElementPeta(y+1, x) == 'o' or this->peta.GetElementPeta(y+1,x)=='X')){
		
		if (this->isThereActiveEngimonYet()){
			this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second, this->peta.GetElementPetaTetap(this->coorActive.first, this->coorActive.second));
			this->coorActive = make_pair(y,x);
			this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second,'X');
		}else{
			this->peta.SetElementPeta(y,x,this->peta.GetElementPetaTetap(y,x));
		}
		this->coordinate.first = y+1;
		this->peta.SetElementPeta(y+1,x,'P');
	}else throw InvalidMove();

}

void Player:: lihatPeta(){
	this->peta.PrintPeta();
}