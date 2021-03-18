#ifndef PLAYER_H
#define PLAYER_H

#include <bits/stdc++.h> //powerfull library
//TODO : include other needed MODULE

using namespace std;

//TODO : breeding, 
class Player{
private:
pair<int,int> coordinate;
//Inventory<engimon> listEngimon;
//Inventory<Skill> listSkillItem;
// tambahkan active engimon di sini
public:
	Player();
	~Player();
	Player(pair<int,int> Coordinate);
	//should we implement cctor and assignment operator? we only have 1 player in the game

	int getXCoordinate();

	int getYCoordinate();

	//getter list engimon
	//getter active engimon


};

template<class T>
class Inventory{
private:
	deque<T> Array; //still debatable between vector/deque and list. vector/deque contigous (random access and easy caching hit) but inefficient in deleting non-end element, list easy to insert and delete not only end but frequently miss cache and doesnt have random access 
	int maxCapacity;
public:
	Inventory(){
		this->Array = deque<T>(); //should we implement like this or fixed size (maxcap)? if option 1 then this code working well otherwise need refactor
		this->maxCapacity = 5;
	}

	Inventory(int maxCapacity){
		this->Array = deque<T>();
		this->maxCapacity = maxCapacity;
	}

	//should we implement cctor and op assignment? again its only 1 player in the game

	T getElementX(int x){
		this->Array.at(x);
		return this->Array.at(x); //will throw exception out of range if needed. operator[] is fine but wont throw exception
	}
	void addElement(T x){
		if (this->maxCapacity > this->Array.size()){
			this->Array.push_back(x);
		}else cout << "Array penuh" << endl; //change to exception if needed
	}

	T delElementIndexX(int x){
		if (this->Array.size() == 0){
			// cout << "Array kosong" << endl; //change to exception if needed
			throw "Array Kosong" ;//change to proper exception if needed
		}else if(this->Array.size() <= x){
			// cout << "Invalid index" << endl; //change to exception if needed
			throw "Invalid index" ;//change to proper exception if needed
		}else{
			T dummy = this->getElementX(x); //class T need to have operator assignment
			this->Array.erase(this->Array.begin()+x);
			return dummy;
		}
	}

	int getSize(){
		return this->Array.size();
	}
};

//NEED TESTING USING SKILL MODULE
/**
template <>
class Inventory<Skill>{
private:
	map<Skill,int> Array;
	int maxCapacity;
public:
	Inventory(){
		this->Array = map<Skill,int>();
		this->maxCapacity = 50;
	}
	Inventory(int maxCapacity){
		this->Array = map<Skill,int>();
		this->maxCapacity = maxCapacity;
	}
	~Inventory(){
		this->Array.~map();
	}

	int getAmountSkill(Skill s){
		if (this->Array.count(s) == 0){
			cout << "Tidak ada skill yang diinginkan" <<endl; //change to exception if needed
		}else{
			return map[s];
		}
	}

	int getActualSize(){
		map<Skill,int>::iterator it; //using iterator cause thats what mr fitra said. alternatively can use auto if we use c++ 11
		int actualSize = 0;
		for (it = this->Array.begin(); it != this->Array.end(); it++){
			actualSize += it->second;
		}
		return actualSize;
	}

	void addElement(Skill s){
		if (this->Array.count(s) == 0 and this->getActualSize() < this->maxCapacity){
			this->Array.insert(pair<Skill, int> (s,1));
		}else if (this->Array.count(s) > 0 and this -> getActualSize() < this -> maxCapacity){
			this->Array[s]++; //need testing
		}else{
			cout << "Inventory full" << endl; //change to exception if needed
		}
	}

	void delElement(Skill s){
		if (this->Array.count(s) == 0){
			cout << "No item s" << endl; //change to exception if needed
		}else{
			this->Array[s]--;
			if (this->Array.count(s) == 0){
				this->Array.erase(s); //need testing, use iterator if this fail
			}
		}
	}
};
**/

#endif