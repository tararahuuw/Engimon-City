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
Player::Player(pair<int,int> Coordinate){
	this->coordinate = Coordinate;
	this->listEngimon = Inventory<Engimon>();
	this->listSkillItem = Inventory<Skill>();
	// this->peta = map;
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
	if (L->isSingleElement()) cout <<"Beuh" << endl;
	Engimon Alam(A, "Alam", "", "", "", "", 1, 0, 0, false, false);
	Engimon Chelsie(L, "Chelsie", "", "", "", "", 1,0,0,false, false);
	Engimon Monica(T, "Monica", "", "", "", "", 1, 0, 0, false, false);
	this->addEngimonToInven(Alam);
	this->addEngimonToInven(Chelsie);
	this->addEngimonToInven(Monica);
	this->addSkillItemToInven(agni);
	this->addSkillItemToInven(listrik);
	this->addSkillItemToInven(toya);
	//starter pack here
	//3 engimon (?)
	//3 proper item skills (?)
}

void Player::activateEngimon(int idx){
	Engimon dummy;
	try{
		this->listEngimon.getElementX(idx);
		cout << "BRUH" << endl;
		// Species* tes = dummy.getSpecies();
		// if (tes->isSingleElement()) cout <<"salahku apa?" << endl;
	}catch (exception& e){
		throw InvalidEngimonException(); 
	}

	dummy = this->listEngimon.getElementX(idx);
	if (dummy.getSpecies()->isSingleElement()) cout <<"salahku apa?" << endl;
	if (this->isThereActiveEngimon){
		cout << "YEET" << endl;
		this->listEngimon.setElementX(this->activeEngimon, idx); //no exception guaranteed if this line executed
		//already checked using getelementx
		this->activeEngimon = dummy;
	}else{
		// cout << "THERE" << endl;
		
		this->activeEngimon = dummy;
		cout << "THere" << endl;
		if (dummy.getSpecies()->isSingleElement()) cout <<"salahku apa?" << endl;
		this->listEngimon.delElementIndexX(idx);
		if (dummy.getSpecies()->isSingleElement()) cout <<"salahku apa?" << endl;
		if (this->activeEngimon.getSpecies()->isSingleElement()) cout <<"salahku apa?" << endl;
		cout << "lah" <<endl;
	}
	this->isThereActiveEngimon = true;
	
}

void Player:: learnSkill(int idx){
	this->activeEngimon.addSkill(this->listSkillItem.getSkillX(idx));
	cout << "sampai sini gak?" << endl;
	//these lines below will be executed if there is no exception throwed
	this->listSkillItem.delElement(this->listSkillItem.getSkillX(idx));
}

int Player:: getXCoordinate(){
	return this->coordinate.first;
}

int Player:: getYCoordinate(){
	return this->coordinate.second;
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