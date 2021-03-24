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
	//starter pack here
	//3 engimon (?)
	//3 proper item skills (?)
}

void Player::activateEngimon(int idx){
	Engimon dummy;
	try{
		dummy = this->listEngimon.getElementX(idx);
	}catch (exception& e){
		throw InvalidEngimonException(); 
	}
	if (this->isThereActiveEngimon){
		this->listEngimon.setElementX(this->activeEngimon, idx); //no exception guaranteed if this line executed
		//already checked using getelementx
		this->activeEngimon = dummy;
	}else{
		this->activeEngimon = dummy;
		this->listEngimon.delElementIndexX(idx);
	}
	
}

void Player:: learnSkill(int idx){
	this->activeEngimon.addSkill(this->listSkillItem.getSkillX(idx));
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