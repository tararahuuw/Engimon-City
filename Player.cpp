#include "Player.h"
#include <bits/stdc++.h>

using namespace std;


Player:: Player(){
	this->coordinate = make_pair(0,0);
	this->listEngimon = Inventory<Engimon>();
	this->listSkillItem = Inventory<Skill>();
}
//no need dest
// Player::~Player(){
// 	this->listEngimon.
// }
Player::Player(pair<int,int> Coordinate){
	this->coordinate = Coordinate;
	this->listEngimon = Inventory<Engimon>();
	this->listSkillItem = Inventory<Skill>();
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