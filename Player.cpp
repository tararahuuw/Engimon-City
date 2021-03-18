#include "Player.h"
#include <bits/stdc++.h>

using namespace std;
Player:: Player(){
	this->coordinate = make_pair(0,0);
	//implement engimon here
}
Player::~Player(){
	// delete this->listEngimon;
	// delete this->listSkillItem;
}
Player::Player(pair<int,int> Coordinate){
	this->coordinate = Coordinate;
}

int Player:: getXCoordinate(){
	return this->coordinate.first;
}

int Player:: getYCoordinate(){
	return this->coordinate.second;
}