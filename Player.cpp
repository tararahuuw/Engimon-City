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
void Player::battle(Engimon& enemy) {
	int ongoing = 1;
	int attempt = 1;
	while(ongoing == 1) {
		string answer;
		cout << "Enemy : " << enemy.getSpecies() << endl;
		cout << "Element : ";
		vector<Element> element = enemy.getElement();
		for (auto i = element.begin(); i != element.end(); ++i) {
			cout << " - " << *i << endl;
		} 
		cout << "Level : " << enemy.getLevel() << endl;

		cout << "What will you do?" << endl;
		cout << "- attack" << endl;
		cout << "- change active engimon" << endl;
		cout << "- run" << endl;
		cout << "Choose a command : ";
		cin >> answer;
		if(answer == "attack") {
			//ongoing = attack(P,P.getActiveEngimon(),enemy,attempt); // error soalnya harusnya pake reference
			SkillsFactory sf = SkillsFactory(); //buat nanti dapet skill item
			float adv1 = Engimon::advantage(this->activeEngimon,enemy,1);
			float adv2 = Engimon::advantage(this->activeEngimon,enemy,2);
			float power1 = Engimon::countPower(this->activeEngimon,adv1);
			float power2 = Engimon::countPower(enemy,adv2);
			cout << "Player Engimon attacks with a total power of " << power1 << endl;
			cout << "Wild Engimon attacks with a total power of " << power2 << endl;
			if(power1 >= power2) { // kalo player menang
				cout << "Player Engimon wins" << endl;
				this->activeEngimon.addEXP(enemy.getLevel()*5); // tambah exp
				this->addEngimonToInven(enemy); // nambah engimon ke inventoy

				//dapet skill random
				int ele2 = enemy.getElement().at(0); //yang dipake elemen enemy pertama
				int x = rand() % sf.getSkills().size();
				Skill s = Skill(sf[x]);
				while(count(s.getElement().begin(),s.getElement().end(),ele2) == 0) { //skill randomnya beda elemen
					x = (x + 1) % sf.getSkills().size();
					s = Skill(sf[x]);
				} 
				this->addSkillItemToInven(s);
				ongoing = 0;
			}
			else {
				cout << "Your Engimon is defeated" << endl;
				this->activeEngimon = Engimon(); // Engimon player ditimpa default Engimon
				this->isThereActiveEngimon = false;
				//changeEngimon(p,attempt); // kalo Engimon mati wajib ganti
				if(this->getListEng().getSize() >= 1) { // kalo masih ada Engimon di inventory
					int found = 0;
					while(found == 0) {
						int x,y;
						cout << "Please choose another Engimon to be active" << endl;
						this->viewListEngimon(); 
						cout << "Input the index of the Engimon : ";
						cin >> x;
						y = x - 1;
						try {
							this->activateEngimon(y); // error kalo input index di luar batas
						}
						catch (exception& e)
						{
							throw InvalidIndexException();
						}
						cout << "You have successfully changed your active Engimon" << endl;
						found = 1;
					}
				}
				else {
					if(this->isThereActiveEngimon = false) { // otomatis kalah kalo Active Engimon mati dan nggak ada lagi di inventory
						cout << "All of your Engimon are defeated." << endl;
    					cout << "GAME OVER" << endl;
					}
					else {
						cout << "You don't have any other available Engimon" << endl; 
					}
				}
				ongoing = 0;
			}
					
		}
		else if(answer == "change active engimon") {
			if(this->getListEng().getSize() >= 1) { // kalo masih ada Engimon di inventory
				int found = 0;
				while(found == 0) {
					int x,y;
					cout << "Please choose another Engimon to be active" << endl;
					this->viewListEngimon(); 
					cout << "Input the index of the Engimon : ";
					cin >> x;
					y = x - 1;
					try {
						this->activateEngimon(y); // error kalo input index di luar batas
					}
					catch (exception& e)
					{
						throw InvalidIndexException();
					}
					cout << "You have successfully changed your active Engimon" << endl;
					found = 1;
				}
			}
			else {
				if(this->isThereActiveEngimon = false) { // otomatis kalah kalo Active Engimon mati dan nggak ada lagi di inventory
					cout << "All of your Engimon are defeated." << endl;
					cout << "GAME OVER" << endl;
				}
				else {
					cout << "You don't have any other available Engimon" << endl; 
				}
			}

		}
		else if(answer == "run") {
			//ongoing = run(attempt);
			int x = rand() % 2 + 1;
			if(attempt > 0) {
				attempt = attempt - 1;
				if(x == 1) {
					cout << "You failed to run" << endl;
					ongoing = 1;
				}
				else {
					cout << "You successfully fled" << endl;
					ongoing = 0;
				}
			}
			else {
				cout << "You may only attempt to run once." << endl;
				ongoing = 1;
			}
		}

	}
}