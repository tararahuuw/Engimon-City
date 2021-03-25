#ifndef PLAYER_H
#define PLAYER_H
#include <bits/stdc++.h> //powerfull library
#include "Skill.h"
#include "peta.h"
#include "Engimon2.h"
#include "CustomException.h"
//TODO : include other needed MODULE

using namespace std;


namespace InvProp{
	static const int maxCapacity = 50;
	static int banyakItem = 0;
}


template<class T>
class Inventory{
private:
	deque<T> Array; //still debatable between vector/deque and list. vector/deque contigous (random access and easy caching hit) but inefficient in deleting non-end element, list easy to insert and delete not only end but frequently miss cache and doesnt have random access 

public:
	Inventory(){
		this->Array = deque<T>(); //should we implement like this or fixed size (maxcap)? if option 1 then this code working well otherwise need refactor
	}

	Inventory& operator=(const Inventory& other){
		this-> Array = other.Array;
		return *this;
	}
	// Inventory(int maxCapacity){
	// 	this->Array = deque<T>();
	// 	this->maxCapacity = maxCapacity;
	// }s

	//should we implement cctor and op assignment? again its only 1 player in the game

	T getElementX(int x){
		//cout << "YEET" << endl;
		this->Array.at(x);
		// cout << "YEET2" << endl;
		return this->Array.at(x); //will throw exception out of range if needed. operator[] is fine but wont throw exception
	}
	void addElement(const T& x){
		if (InvProp::maxCapacity > InvProp::banyakItem){
			this->Array.push_back(x);
			InvProp::banyakItem++;
		}else throw InventoryPenuhException(); //change to exception if needed
	}

	void setElementX(const Engimon& other, int x){
		//check for exception
		try{
			this->Array.at(x) = other;
		}catch (exception& e){
			throw InvalidIndexException();
		}
	}

	void delElementIndexX(int x){
		if (this->Array.size() == 0){
			// cout << "Array kosong" << endl; //change to exception if needed
			throw InventoryKosongException();//change to proper exception if needed
		}else if(this->Array.size() <= x){
			// cout << "Invalid index" << endl; //change to exception if needed
			throw InvalidIndexException();//change to proper exception if needed
		}else{
			// T dummy = this->getElementX(x); //class T need to have operator assignment
			this->Array.erase(this->Array.begin()+x);
			// for (int i = x; i<this->Array.size()-1; i++){
			// 	Array[i] = Array[i+1];
			// }
			// this->Array.erase(this->Array.end());
			InvProp::banyakItem--;
			// return *dummy;
			//no need  return
		}
	}

	int getSize(){
		return this->Array.size();
	}

	void viewList(){
		for (int i =0; i < this->Array.size(); i++){
			cout <<i+1 << ". "<< this->Array[i] << "\n" <<endl;
		}
	}
};

//NEED TESTING USING SKILL MODULE
//FCK ERROR IF USING MAP
template <>
class Inventory<Skill>{
private:
	vector<Skill> Array;
	vector<int> Jumlah;
public:
	Inventory(){
		this->Array = vector<Skill>();
		this->Jumlah = vector<int>();
	}
	// Inventory(int maxCapacity){
	// 	this->Array = map<Skill,int>();
	// 	this->maxCapacity = maxCapacity;
	// }
	// ~Inventory(){
	// 	this->Array.~map();
	// }
	//no need destructor

	Skill& getSkillX(int idx){
		try{
			this->Array.at(idx);
		}catch (exception& e){
			throw InvalidIndexException();
		}
		return this->Array.at(idx);
	}

	Inventory& operator=(const Inventory& other){
		this->Array = other.Array;
		this->Jumlah = other.Jumlah;
		return *this;
	}

	int getIdx(Skill& s){
		for (int i = 0; i < this->Array.size(); i++){
			if (this->Array[i] == s){
				return i;
			}
		}
		return -1;
	}

	int getAmountSkill(Skill& s){
		for (int i = 0; i < this->Array.size(); i++){
			if (this->Array[i] == s){
				return this->Jumlah[i];
			}
		}
		return 0;

		// if (this->Array.count(s) == 0){
		// 	cout << "Tidak ada skill yang diinginkan" <<endl; //change to exception if needed
		// }else{
		// 	return (this->Array)[s];
		// }
	}

	int getActualSize(){
		int result;
		for (int i =0; i < this->Jumlah.size(); i++){
			result += this->Jumlah[i];
		}
		return result;
		// map<Skill,int>::iterator it; //using iterator cause thats what mr fitra said. alternatively can use auto if we use c++ 11
		// int actualSize = 0;
		// for (it = this->Array.begin(); it != this->Array.end(); it++){
		// 	actualSize += it->second;
		// }
		// return actualSize;
	}

	void addElement(Skill& s){
		if (this->getAmountSkill(s) == 0 and InvProp::banyakItem < InvProp::maxCapacity){
			this->Array.push_back(s);
			this->Jumlah.push_back(1);
			InvProp::banyakItem++;
		}else if (this-> getAmountSkill(s) > 0 and InvProp::banyakItem < InvProp::maxCapacity){
			this->Jumlah[this->getIdx(s)]++;
			InvProp::banyakItem++;
		}else throw  InventoryPenuhException();
		// if (this->Array.count(s) == 0 and InvProp::banyakItem < InvProp::maxCapacity){
		// 	this->Array.insert(pair<Skill, int> (s,1));
		// 	InvProp::banyakItem++;
		// }else if (this->Array.count(s) > 0 and InvProp::banyakItem < InvProp::maxCapacity){
		// 	(this->Array)[s]++; //need testing
		// 	InvProp::banyakItem++;
		// }else{
		// 	throw "Inventory full"; //change to exception if needed
		// }
	}

	void delElement(Skill& s){
		if (this->getAmountSkill(s) == 0) throw EmptySkillsItemException();
		else{
			int index = this->getIdx(s);
			this->Jumlah[index]--;
			if (this->Jumlah[index] == 0){
				this->Array.erase(this->Array.begin()+index);
				this->Jumlah.erase(this->Jumlah.begin()+index);
			}
			InvProp::banyakItem--;
		}
		// if (this->Array.count(s) == 0){
		// 	cout << "No item s" << endl; //change to exception if needed
		// }else{
		// 	(this->Array)[s]--;
		// 	if (this->Array.count(s) == 0){
		// 		this->Array.erase(s); //need testing, use iterator if this fail
		// 	}
		// 	InvProp::banyakItem--;
		// }
	}

	void viewList(){
		for (int i = 0; i < this->Array.size(); i++){
			cout << i+1 << ". " << this->Array[i] << endl;
			cout << "| Jumlah       : " << this->Jumlah[i] << "\n" << endl;
		}
	}
	
};

//TODO : breeding, battle
//spawn wild engimon
//need to fix output view inventory, currently ugly
//waiting thomas fixing output

class Player{
private:
pair<int,int> coordinate;
pair<int,int> coorActive;
Inventory<Engimon> listEngimon;
Inventory<Skill> listSkillItem;
Engimon activeEngimon; //if there is not an active engimon, this will be filled by default ctor	 engimon
Peta peta;
bool isThereActiveEngimon; //can be false if : not activate engimon yet, lose battle
// tambahkan active engimon di sini
public:
	// Player();
	// ~Player();
	Player(pair<int,int> Coordinate, const Peta& peta);
	//should we implement cctor and assignment operator? we only have 1 player in the game

	//no need
	int getXCoordinate();

	int getYCoordinate();

	int getXCoorAE();

	int getYCoorAE();

	Inventory<Skill> getListSkill();
	Inventory<Engimon> getListEng();

	bool isThereActiveEngimonYet();
	//invalid move ketika menabrak batas peta, engimon lain, kecuali active engimonnya
	void moveW();
	void moveA();
	void moveD();
	void moveS();
	void moveAE(string move);

	void lihatPeta();

	void activateEngimon(int idx); //activate engimon based on index inventory of engimon
	void learnSkill(int idx); //learn skill based on index inventory of skill. requirement : active engimon

	void viewListSkill();
	void viewListEngimon();
	void addEngimonToInven(const Engimon& other);
	void addSkillItemToInven(Skill& other);
	// void setActiveEngimon(const Engimon& other); //activate based on engimon (rarely used maybe?)

	Engimon getActiveEngimon();
	// Peta getPeta();
	// char getPetaTetap(int b, int k);
	// void setPeta(int b, int k, char c);
	void relocateAE(); //asumsi sudah ada active engimon

	void spawn();
	void randomMove();

	// Breeding Engimon
	void breeding (int Index1, int Index2);

    vector<Skill> skillanak(Engimon A, Engimon B);
	void battle(Engimon& enemy);
};






#endif