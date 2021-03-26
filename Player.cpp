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
	Engimon Alam(A, "Alam", "", "", "", "", 10, 0, 0, true, false);
	Engimon Chelsie(L, "Chelsie", "", "", "", "", 10,0,0,true, false);
	Engimon Monica(T, "Monica", "", "", "", "", 10, 0, 0, true, false);
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
bool Player::battle(Engimon& enemy) {
	int ongoing = 1;
	int attempt = 1;
	bool hasil;
	while(ongoing == 1) {
		int answer;
		cout << "------------------------" << endl;
		cout << enemy;
		cout << "Level : " << enemy.getLevel() << endl;
		cout << "Element : " << endl;
		vector<Element> element = enemy.getElement();
        for (auto i = element.begin(); i != element.end(); ++i) {
            cout << " - " << *i << endl;
        }
		cout << "------------------------" << endl; 

		cout << "Input the number of the command you want to do" << endl;
		cout << "1. attack" << endl;
		cout << "2. change active engimon" << endl;
		cout << "3. run" << endl;
		cout << "Choose a command : ";
		cin >> answer;
		if(answer == 1) {
			//ongoing = attack(P,P.getActiveEngimon(),enemy,attempt); // error soalnya harusnya pake reference
			SkillsFactory sf = SkillsFactory(); //buat nanti dapet skill item
			float adv1 = Engimon::advantage(this->activeEngimon,enemy,1);
			float adv2 = Engimon::advantage(this->activeEngimon,enemy,2);
			float power1 = Engimon::countPower(this->activeEngimon,adv1);
			float power2 = Engimon::countPower(enemy,adv2);
			cout << "Your Engimon attacks with a total power of " << power1 << endl;
			cout << "Wild Engimon attacks with a total power of " << power2 << endl;
			if(power1 >= power2) { // kalo player menang
				cout << "Your Engimon wins" << endl;
				this->activeEngimon.addEXP(enemy.getLevel()*5); // tambah exp
				cout << "Your active engimon gained " << enemy.getLevel()*5 << " experience points" << endl;
				if(this->activeEngimon.getStatus() == false) {
					this->activeEngimon = Engimon();
					this->isThereActiveEngimon = false;
					this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second, this->peta.GetElementPetaTetap(this->coorActive.first,this->coorActive.second));

					cout << "Your active Engimon has reached its limit. He will ascend to Engimon heaven" << endl;
				}
				enemy.setWild(false);
				this->addEngimonToInven(enemy); // nambah engimon ke inventoy

				//dapet skill random
				vector<Skill> skills = sf.getSkills();
				int ele2 = enemy.getElement().at(0); //yang dipake elemen enemy pertama
				int x = rand() % skills.size();
				Skill s = skills.at(x);

				while(!s.hasElement(ele2)) { //skill randomnya beda elemen
					x = (x + 1) % skills.size();
					s = skills.at(x);
				}
				this->addSkillItemToInven(s);
				cout << "You obtained skill item : " << s.getName() << endl;
				ongoing = 0;
				hasil = true;
			}
			else {
				cout << "Your Engimon is defeated" << endl;
				this->activeEngimon = Engimon(); // Engimon player ditimpa default Engimon
				this->isThereActiveEngimon = false;
				this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second, this->peta.GetElementPetaTetap(this->coorActive.first,this->coorActive.second));
				//changeEngimon(p,attempt); // kalo Engimon mati wajib ganti
				ongoing = 0;
				//oh ini harusnya kalau sampai sini gak battle lagi ya?
				//kalau iya hasilnya false;
				hasil = false;

				//kalau dia kalah dia wajib activate engimon waktu mash mode battle? kalau di luar mode battle gimna?
			}
					
		}
		else if(answer == 2) {
			if(this->getListEng().getSize() >= 1) { // kalo masih ada Engimon di inventory
				int found = 0;
				while(found == 0) {
					int x,y;
					cout << "Please choose another Engimon to be active" << endl;
					this->viewListEngimon(); 
					cout << "Input the index of the Engimon : ";
					cin >> x;
					y = x - 1;
					if(x <= this->getListEng().getSize()) {
						this->activateEngimon(y); // error kalo input index di luar batas
						cout << "You have successfully changed your active Engimon" << endl;
						found = 1;
					}
					else {
						cout << "Invalid index"<< endl;
						cout << "" << endl;
					}
					
				}
			}
			else {
				if(this->isThereActiveEngimon = false) { // otomatis kalah kalo Active Engimon mati dan nggak ada lagi di inventory
					cout << "All of your Engimon are defeated." << endl;
					cout << "GAME OVER" << endl;
					hasil = false;
					//flow program gak bakal bisa sampai kesini, karena init battle mewajibkan active engimon ada sebelumnya
				}
				else {
					cout << "You don't have any other available Engimon" << endl; 
				}
			}

		}
		else if(answer == 3) {
			//ongoing = run(attempt);
			int x = rand() % 2 + 1;
			if(attempt > 0) {
				attempt = attempt - 1;
				if(x == 1) {
					cout << "You failed to run" << endl;
					cout << "" << endl;
					ongoing = 1;
				}
				else {
					cout << "You successfully fled" << endl;
					ongoing = 0;
					hasil = false;
				}
			}
			else {
				cout << "You may only attempt to run once." << endl;
				cout << "" << endl;
				ongoing = 1; //ini attempt runnya gak tiap engimon aja? kalau 1 tiap player bisa langsung kalah kalau enemynya OP
			}
		}
		else {
			cout << "invalid command" << endl;
		}

	}
	return hasil;
}

void Player:: initBattle(){
	if (this->isThereActiveEngimon and this->isEnemyAround()){
		pair<int,int> coorEnemy = this->getEnemyAround();
		Engimon enemy = this->peta.GetEngimonLiar(coorEnemy.first,coorEnemy.second);
		bool win = this->battle(enemy);
		if (win) {
			this->peta.DeleteEngimon2(coorEnemy.first,coorEnemy.second);
		}
	}else{
		if (not this->isThereActiveEngimon){
			throw ActiveEngimonKosong();
		}else throw EnemyKosong();
	}
}

bool Player:: isEnemyAround(){
	int y = this->coordinate.first;
	int x = this->coordinate.second;
	if ( y-1 >= 0 and (this->peta.GetElementPeta(y-1,x) != '-' and this->peta.GetElementPeta(y-1,x) != 'o' and this->peta.GetElementPeta(y-1,x) != 'X')){
		return true;
	}else if (x+1 < this->peta.GetKolom() and (this->peta.GetElementPeta(y,x+1) != '-' and this->peta.GetElementPeta(y,x+1) != 'o' and this->peta.GetElementPeta(y,x+1) != 'X')){
		return true;
	}else if (y+1 < this->peta.GetBaris() and (this->peta.GetElementPeta(y+1,x) != '-' and this->peta.GetElementPeta(y+1,x) != 'o' and this->peta.GetElementPeta(y+1,x) != 'X')){
		return true;
	}else if (x-1 >= 0 and (this->peta.GetElementPeta(y,x-1) != '-' and this->peta.GetElementPeta(y,x-1) != 'o' and this->peta.GetElementPeta(y,x-1) != 'X')){
		return true;
	}

	return false;
}

pair<int,int> Player:: getEnemyAround(){
	int y = this->coordinate.first;
	int x = this->coordinate.second;
	int a;
	int b;
	if ( y-1 >= 0 and (this->peta.GetElementPeta(y-1,x) != '-' and this->peta.GetElementPeta(y-1,x) != 'o' and this->peta.GetElementPeta(y-1,x) != 'X')){
		a= y-1;
		b=x;
	}else if (x+1 < this->peta.GetKolom() and (this->peta.GetElementPeta(y,x+1) != '-' and this->peta.GetElementPeta(y,x+1) != 'o' and this->peta.GetElementPeta(y,x+1) != 'X')){
		a = y;
		b=x+1;
	}else if (y+1 < this->peta.GetBaris() and (this->peta.GetElementPeta(y+1,x) != '-' and this->peta.GetElementPeta(y+1,x) != 'o' and this->peta.GetElementPeta(y+1,x) != 'X')){
		a=y+1;
		b=x;
	}else if (x-1 >= 0 and (this->peta.GetElementPeta(y,x-1) != '-' and this->peta.GetElementPeta(y,x-1) != 'o' and this->peta.GetElementPeta(y,x-1) != 'X')){
		a = y;
		b = x-1;
	}else {a = -1; b=-1;}

	return make_pair(a,b);
}

bool Player::isGameOver(){
	return (!(this->isThereActiveEngimon) && (this->getListEng().getSize()==0));
}

void Player::deactivateEngimon(){
	if (this->isThereActiveEngimon){
		this->addEngimonToInven(this->activeEngimon);
		this->isThereActiveEngimon =false;
		this->activeEngimon = Engimon();
		this->peta.SetElementPeta(this->coorActive.first,this->coorActive.second,this->peta.GetElementPetaTetap(this->coorActive.first,this->coorActive.second));
	}else throw ActiveEngimonKosong();
}

void Player::delearnSkill(int idx){
	if (this->isThereActiveEngimon){
		Skill dummy = this->activeEngimon.getSkills().at(idx);
		this->activeEngimon.dropSkill(dummy);
	//these lines below will be executed if there is no exception throwed
		// this->listSkillItem.addElement(dummy);
		//ditambahin ke invent gak ya?
	}else throw ActiveEngimonKosong();
}

void Player :: drawing(int index) {
	if (index == -1) {
	cout << " _   /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\   _ " << endl;
    cout << "| | |/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\| | |" << endl;
    cout << "| |                                                                     | |" << endl;
    cout << "| |                                                                     | |" << endl;
    cout << "| |                                                                     | |" << endl;
    cout << "| |                                                                     | |" << endl;
    cout << "| |                                                                     | |" <<endl;
    cout << "|_|   ______             _                          _____ _ _           |_|" <<endl;
    cout << "| |  |  ____|           (_)                        / ____(_| |          | |" <<endl;
    cout << "| |  | |__   _ __   __ _ _ _ __ ___   ___  _ __   | |     _| |_ _   _   | |" <<endl;
    cout << "| |  |  __| | '_ \\ / _` | | '_ ` _ \\ / _ \\| '_ \\  | |    | | __| | | |  | |" <<endl;
    cout << "| |  | |____| | | | (_| | | | | | | | (_) | | | | | |____| | |_| |_| |  | |" <<endl;
    cout << "| |  |______|_| |_|\\__, |_|_| |_| |_|\\___/|_| |_|  \\_____|_|\\__|\\__, |  | |" <<endl;
    cout << "| |                 __/ |                                        __/ |  | |" <<endl;
    cout << "|_|                |___/                                        |___/   |_|" <<endl;
    cout << "| |                                                                     | |" <<endl;
    cout << "| |                                                                     | |" <<endl;
    cout << "| |                                                                     | |" <<endl;
    cout << "| |                                                                     | |" <<endl;
    cout << "| |                                                                     | |" <<endl;
    cout << "| |______ ______ ______ ______ ______ ______ ______ ______ ______ ______| |" <<endl;
    cout << "|_|______|______|______|______|______|______|______|______|______|______|_|" <<endl;
	}
	else if (index == 0) {
    cout << "" << endl;
    cout <<"              _.--\"\"`-.. "<< endl;
    cout <<"            ,'          `. "<< endl;
    cout <<"          ,'          __  `. "<< endl;
    cout <<"         /|          \" __   \\ "<< endl;
    cout <<"        , |           / |.   . "<< endl;
    cout <<"        |,'          !_.'|   | "<< endl;
    cout <<"      ,'             '   |   | "<< endl;
    cout <<"     /              |`--'|   | "<< endl;
    cout <<"    |                `---'   | "<< endl;
    cout <<"     .   ,                   |                       ,\". "<< endl;
    cout <<"      ._     '           _'  |                    , ' \\ ` "<< endl;
    cout <<"  `.. `.`-...___,...---\"\"    |       __,.        ,`\"   L,| "<< endl;
    cout <<"  |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \\ "<< endl;
    cout <<"-:..     `. `-..--_.,.<       `\"      / `.        `-/ |   . "<< endl;
    cout <<"  `,         \"\"\"\"'     `.              ,'         |   |  ',, "<< endl;
    cout <<"    `.      '            '            /          '    |'. |/ "<< endl;
    cout <<"      `.   |              \\       _,-'           |       '' "<< endl;
    cout <<"        `._'               \\   '\"\\                .      | "<< endl;
    cout <<"           |                '     \\                `._  ,' "<< endl;
    cout <<"           |                 '     \\                 .'| "<< endl;
    cout <<"           |                 .      \\                | | "<< endl;
    cout <<"           |                 |       L              ,' | "<< endl;
    cout <<"           `                 |       |             /   ' "<< endl;
    cout <<"            \\                |       |           ,'   / "<< endl;
    cout <<"          ,' \\               |  _.._ ,-..___,..-'    ,' "<< endl;
    cout <<"         /     .             .      `!             ,j' "<< endl;
    cout <<"        /       `.          /        .           .'/ "<< endl;
    cout <<"       .          `.       /         |        _.'.' "<< endl;
    cout <<"        `.          7`'---'          |------\"'_.' "<< endl;
    cout <<"       _,.`,_     _'                ,''-----\"' "<< endl;
    cout <<"   _,-_    '       `.     .'      ,\\ "<< endl;
    cout <<"   -\" /`.         _,'     | _  _  _.| "<< endl;
    cout <<"    \"\"--'---\"\"\"\"\"'        `' '! |! / "<< endl;
    cout <<"                            `\" \" -'" << endl;
	}
	else if (index == 1) {
	cout << "                                       __,......._"<<endl;
    cout << "    _............___          ____....<__         `\"._"<<endl;
    cout << "   '._      `\",     `'--._,.-'   ___     `\"-.    ___..>---,---------.."<<endl;
    cout << " ____ -.,..--\"            `-  ,-'   `       .`-\"'       .'_         ,-'"<<endl;
    cout << "'._  \"\"'-.                  .'     _.._                    `-._ ,.-'"<<endl;
    cout << "   `-._   `._              .     ,'    `.                    ,-'----.._"<<endl;
    cout << "       _>.   -.            `     |      |                _,-'          )"<<endl;
    cout << ",..--\"\"`--\"\"\"\"\"`-.          \\    `-.    |             ,.+.__   _,;---\"\""<<endl;
    cout << "\\_ |              `.         `.       _.'         _,-`      `\"\"   `."<<endl;
    cout << "  \"\\                `       / _`\"----'           '                 /-."<<endl;
    cout << "   `.____                  |  #      #' \\                         `,..'"<<endl;
    cout << "       ,-\"--...__          `--        --'                   ___,..'"<<endl;
    cout << "      '-.---\"'  |           -.,........,            ,.---\"\"\" ."<<endl;
    cout << "                |            |        \\'             \\\"\"--..._`"<<endl;
    cout << "                |             \\       /              |"<<endl;
    cout << "                .              `.    /               |"<<endl;
    cout << "                 ,               `--'                j"<<endl;
    cout << "                j \\                                 /"<<endl;
    cout << "                |  .                               '`."<<endl;
    cout << "                 L._`.                           .' ,|"<<endl;
    cout << "                 |  `.:-._                    _,' ,' |"<<endl;
    cout << "                 `.,'| \"\"\"`.__            _,< _..-   '"<<endl;
    cout << "                     `...-'   `----------'   `-.__|`' "<<endl;
	}
	else if (index == 2) {
	cout << "                                             ,-."<<endl;
    cout << "                                          _.|  '"<<endl;
    cout << "                                        .'  | /"<<endl;
    cout << "                                      ,'    |'"<<endl;
    cout << "                                     /      /"<<endl;
    cout << "                       _..----\"\"---.'      /"<<endl;
    cout << " _.....---------...,-\"\"                  ,'"<<endl;
    cout << " `-._  \\                                /"<<endl;
    cout << "     `-.+_            __           ,--. ."<<endl;
    cout << "          `-.._     .:  ).        (`--\"| \\"<<endl;
    cout << "               7    | `\" |         `...'  \\"<<endl;
    cout << "               |     `--'     '+\"        ,\". ,\"\"-"<<endl;
    cout << "               |   _...        .____     | |/    '"<<endl;
    cout << "          _.   |  .    `.  '--\"   /      `./     j"<<endl;
    cout << "         \\' `-.|  '     |   `.   /        /     /"<<endl;
    cout << "         '     `-. `---\"      `-\"        /     /"<<endl;
    cout << "          \\       `.                  _,'     /"<<endl;
    cout << "           \\        `                        ."<<endl;
    cout << "            \\                                j"<<endl;
    cout << "             \\                              /"<<endl;
    cout << "              `.                           ."<<endl;
    cout << "                +                          \\"<<endl;
    cout << "                |                           L"<<endl;
    cout << "                |                           |"<<endl;
    cout << "                |  _ /,                     |"<<endl;
    cout << "                | | L)'..                   |"<<endl;
    cout << "                | .    | `                  |"<<endl;
    cout << "                '  \\'   L                   '"<<endl;
    cout << "                 \\  \\   |                  j"<<endl;
    cout << "                  `. `__'                 /"<<endl;
	}

	else if (index == 3) {
	cout <<"                       _"<<endl;
    cout <<"            _,..-\"\"\"--' `,.-\"."<<endl;
    cout <<"          ,'      __.. --',  |"<<endl;
    cout <<"        _/   _.-\"' |    .' | |       ____"<<endl;
    cout <<"  ,.-\"\"'    `-\"+.._|     `.' | `-..,',--.`."<<endl;
    cout <<" |   ,.                      '    j 7    l \\__"<<endl;
    cout <<" |.-'                            /| |    j||  ."<<endl;
    cout <<" `.                   |         / L`.`\"\"','|\\  \\"<<endl;
    cout <<"   `.,----..._       ,'`\"'-.  ,'   \\ `\"\"'  | |  l"<<endl;
    cout <<"     Y        `-----'       v'    ,'`,.__..' |   ."<<endl;
    cout <<"      `.                   /     /   /     `.|   |"<<endl;
    cout <<"        `.                /     l   j       ,^.  |L"<<endl;
    cout <<"          `._            L       +. |._   .' \\|  | \\"<<endl;
    cout <<"            .`--...__,..-'\"\"'-._  l L  \"\"\"    |  |  \\"<<endl;
    cout <<"          .'  ,`-......L_       \\  \\ \\     _.'  ,'.  l"<<endl;
    cout <<"       ,-\"`. / ,-.---.'  `.      \\  L..--\"'  _.-^.|   l"<<endl;
    cout <<" .-\"\".'\"`.  Y  `._'   '    `.     | | _,.--'\"     |   |"<<endl;
    cout <<"  `._'   |  |,-'|      l     `.   | |\"..          |   l"<<endl;
    cout <<"  ,'.    |  |`._'      |      `.  | |_,...---\"\"\"\"\"`    L"<<endl;
    cout <<" /   |   j _|-' `.     L       | j ,|              |   |"<<endl;
    cout <<"`--,\"._,-+' /`---^..../._____,.L',' `.             |\\  |"<<endl;
    cout <<"   |,'      L                   |     `-.          | \\j"<<endl;
    cout <<"            .                    \\       `,        |  |"<<endl;
    cout <<"             \\                __`.Y._      -.     j   |"<<endl;
    cout <<"              \\           _.,'       `._     \\    |  j"<<endl;
    cout <<"              ,-\"`-----\"\"\"\"'           |`.    \\  7   |"<<endl;
    cout <<"             /  `.        '            |  \\    \\ /   |"<<endl;
    cout <<"            |     `      /             |   \\    Y    |"<<endl;
    cout <<"            |      \\    .             ,'    |   L_.-')"<<endl;
    cout <<"             L      `.  |            /      ]     _.-^._"<<endl;
    cout <<"              \\   ,'  `-7         ,-'      / |  ,'      `-._"<<endl;
    cout <<"             _,`._       `.   _,-'        ,',^.-            `."<<endl;
    cout <<"          ,-'     v....  _.`\"',          _:'--....._______,.-'"<<endl;
    cout <<"        ._______./     /',,-'\"'`'--.  ,-'  `."<<endl;
    cout <<"                 \"\"\"\"\"`.,'         _\\`----...' "<<endl;
    cout <<"                        --------\"\"'"<<endl;
	}

	else if (index == 4) {
    cout << "               _," << endl;
    cout << "             .'.'  _." << endl;
    cout << "           ,' ._,-'_\"'" << endl;
    cout << "        _,'   '  ------\"\"'`._" << endl;
    cout << "      ,'                 _,.--\"'              ___        __,.." << endl;
    cout << "      |    _,..       ,-'             _,.--\"\"'   7_,.--\"'    ,'" << endl;
    cout << "      j. .'D  |       |            ,'\"       _.-'       _.-\"\"'.  _,..-\"'" << endl;
    cout << " ,---'  `+----'       |`._      _.'         '                '.-'      /" << endl;
    cout << "j         `.       ,-'    `'--,\"                           ,'       ,-'" << endl;
    cout << "|    __    |      '-.._,    .'                           ,'     ,.-'" << endl;
    cout << "`. ,' ('T--'        .\"     /                          _.'  _,--\"" << endl;
    cout << "  `   `,  /         _`.   j                         _', ,-\"__,..,-." << endl;
    cout << "      `-\"`.        \\   `-.|                        _,'\"\"\"\"'       l" << endl;
    cout << "           `.,      \\     L                     _.'      __,...--'" << endl;
    cout << "            ` '-    .`     `._             _,.-' ,--'\"\"\"\"" << endl;
    cout << "             '  \\`.,\\         `+------,--\"'     /" << endl;
    cout << "                 \\ )`'      ,-'      /         /" << endl;
    cout << "                  `     _,-'       ,'         /" << endl;
    cout << "                   `+\"\"'         ,'     ,.  ,'" << endl;
    cout << "                     `.        ,'     ,'   ." << endl;
    cout << "                       `-._.,-'      /. _.,j" << endl;
    cout << "                           \"\"`-----.'  '  /" << endl;
    cout << "                                / /   /  /" << endl;
    cout << "                    _.......__,' /__,' ,'" << endl;
    cout << "                  ,\\  ,--..--------\"_  ...._" << endl;
    cout << "                 '--\"(_,`|  ,..-' _,....__  |." << endl;
    cout << "                        '-./...-'\"        `\"\"\"- " << endl;
	}
	else if (index == 5) {
    cout << "                    _,.-''\"\"\"`-._" << endl;
    cout << "                  ,\"             `._" << endl;
    cout << "                ,'   ..     .       `." << endl;
    cout << "              .'     ||     ||        `._" << endl;
    cout << "   ,.....---'\"                         `._`-..._" << endl;
    cout << "   `._  _,.-\"/        `\"--'         `  `. `._   `\"'-." << endl;
    cout << "  __..-'   ,' /                      \\   `.  `-.__.-'" << endl;
    cout << "`._    __,'  ,                        `.   `.    \"--." << endl;
    cout << "   `\"'.'   .'       _,.+..              `.   `.-...-'" << endl;
    cout << "    ,'  _,'     _.-\"   A  `-._            `._  `-." << endl;
    cout << "    `\"+'       '     ,' `     `-             \"''-'" << endl;
    cout << "      '            ,' ___`.                   |" << endl;
    cout << "     .            ' .`   `.`.                 |  _,." << endl;
    cout << "     |            ,'       `                  |,\" ,'" << endl;
    cout << "     |           /          \\                 |  /" << endl;
    cout << "     |          j            '                | /" << endl;
    cout << "     '          |'`\"\"''\"`'\"\"\"|                |/" << endl;
    cout << "      .         `            '               ,'" << endl;
    cout << "       `.        \\          /              ,'" << endl;
    cout << "         `._      `._     ,'             .'" << endl;
    cout << "            `._      `\"\"\"'             .'" << endl;
    cout << "          _,'  `-.....___________...-'`-." << endl;
    cout << "         `...---'               `--.....-' " << endl;
	}

	else if (index == 6) {
    cout <<"                                           /"<<endl;
    cout <<"                        _,.------....___,.' ',.-."<<endl;
    cout <<"                     ,-'          _,.--\"        |"<<endl;
    cout <<"                   ,'         _.-'              ."<<endl;
    cout <<"                  /   ,     ,'                   `"<<endl;
    cout <<"                 .   /     /                     ``."<<endl;
    cout <<"                 |  |     .                       \\.\\"<<endl;
    cout <<"       ____      |___._.  |       __               \\ `."<<endl;
    cout <<"     .'    `---\"\"       ``\"-.--\"'`  \\               .  \\"<<endl;
    cout <<"    .  ,            __               `              |   ."<<endl;
    cout <<"    `,'         ,-\"'  .               \\             |    L"<<endl;
    cout <<"   ,'          '    _.'                -._          /    |"<<endl;
    cout <<"  ,`-.    ,\".   `--'                      >.      ,'     |"<<endl;
    cout <<" . .'\\'   `-'       __    ,  ,-.         /  `.__.-      ,'"<<endl;
    cout <<" ||:, .           ,'  ;  /  / \\ `        `.    .      .'/"<<endl;
    cout <<" j|:D  \\          `--'  ' ,'_  . .         `.__, \\   , /"<<endl;
    cout <<"/ L:_  |                 .  \"' :_;                `.'.'"<<endl;
    cout <<".    \"\"'                  \"\"\"\"\"'                    V"<<endl;
    cout <<" `.                                 .    `.   _,..  `"<<endl;
    cout <<"   `,_   .    .                _,-'/    .. `,'   __  `"<<endl;
    cout <<"    ) \\`._        ___....----\"'  ,'   .'  \\ |   '  \\  ."<<endl;
    cout <<"   /   `. \"`-.--\"'         _,' ,'     `---' |    `./  |"<<endl;
    cout <<"  .   _  `\"\"'--.._____..--\"   ,             '         |"<<endl;
    cout <<"  | .\" `. `-.                /-.           /          ,"<<endl;
    cout <<"  | `._.'    `,_            ;  /         ,'          ."<<endl;
    cout <<" .'          /| `-.        . ,'         ,           ,"<<endl;
    cout <<" '-.__ __ _,','    '`-..___;-...__   ,.'\\ ____.___.'"<<endl;
    cout <<" `\"^--'..'   '-`-^-'\"--    `-^-'`.''\"\"\"\"\"`.,^.`.--' "<<endl;
	}
    
	else if (index == 7) {
	cout<<"                   _,........_"<<endl;
    cout<<"               _.-'    ___    `-._"<<endl;
    cout<<"            ,-'      ,'   \\       `."<<endl;
    cout<<" _,...    ,'      ,-'     |  ,\"\"\":`._."<<endl;
    cout<<"/     `--+.   _,.'      _.',',|\"|  ` \\`"<<endl;
    cout<<"\\_         `\"'     _,-\"'  | / `-'   l L\\"<<endl;
    cout<<"  `\"---.._      ,-\"       | l       | | |"<<endl;
    cout<<"      /   `.   |          ' `.     ,' ; |"<<endl;
    cout<<"     j     |   |           `._`\"\"\"' ,'  |__"<<endl;
    cout<<"     |      `--'____          `----'    .' `."<<endl;
    cout<<"     |    _,-\"\"\"    `-.                 |    \\"<<endl;
    cout<<"     l   /             `.               F     l"<<endl;
    cout<<"      `./     __..._     `.           ,'      |"<<endl;
    cout<<"        |  ,-\"      `.    | ._     _.'        |"<<endl;
    cout<<"        . j           \\   j   /`\"\"\"      __   |          ,\"`."<<endl;
    cout<<"         `|           | _,.__ |        ,'  `. |          |   |"<<endl;
    cout<<"          `-._       /-'     `L       .     , '          |   |"<<endl;
    cout<<"              F-...-'          `      |    , /           |   |"<<endl;
    cout<<"              |            ,----.     `...' /            |   |"<<endl;
    cout<<"              .--.        j      l        ,'             |   j"<<endl;
    cout<<"             j    L       |      |'-...--<               .  /"<<endl;
    cout<<"             `     |       . __,,_    ..  |               \\/"<<endl;
    cout<<"              `-..'.._  __,-'     \\  |  |/`._           ,'`"<<endl;
    cout<<"                  |   \"\"       .--`. `--,  ,-`..____..,'   |"<<endl;
    cout<<"                   L          /     \\ _.  |   | \\  .-.\\    j"<<endl;
    cout<<"                  .'._        l     .\\    `---' |  |  || ,'"<<endl;
    cout<<"                   .  `..____,-.._.'  `._       |  `--;\"I'"<<endl;
    cout<<"                    `--\"' `.            ,`-..._/__,.-1,'"<<endl;
    cout<<"                            `-.__  __,.'     ,' ,' _-'"<<endl;
    cout<<"                                 `'...___..`'--^--' "<<endl;
	}

	else if (index == 8) {
 	cout << "                 .\"-,.__"<<endl;
    cout << "                 `.     `.  ,"<<endl;
    cout << "              .--'  .._,'\"-' `."<<endl;
    cout << "             .    .'         `'"<<endl;
    cout << "             `.   /          ,'"<<endl;
    cout << "               `  '--.   ,-\"'"<<endl;
    cout << "                `\"`   |  \\"<<endl;
    cout << "                   -. \\, |"<<endl;
    cout << "                    `--Y.'      ___."<<endl;
    cout << "                         \\     L._, \\"<<endl;
    cout << "               _.,        `.   <  <\\                _"<<endl;
    cout << "             ,' '           `, `.   | \\            ( `"<<endl;
    cout << "          ../, `.            `  |    .\\`.           \\ \\_"<<endl;
    cout << "         ,' ,..  .           _.,'    ||\\l            )  '\"."<<endl;
    cout << "        , ,'   \\           ,'.-.`-._,'  |           .  _._`."<<endl;
    cout << "      ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\"<<endl;
    cout << "    .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`."<<endl;
    cout << "    |  '          ..         `-...-\"  |  `-'      / /        . `."<<endl;
    cout << "    | /           |L__           |    |          / /          `. `."<<endl;
    cout << "   , /            .   .          |    |         / /             ` `"<<endl;
    cout << "  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\"<<endl;
    cout << " / .           \\\"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`."<<endl;
    cout << ".  '         .-f    ,'   `    '.       \\__.---'     _   .'   '     \\ \\"<<endl;
    cout << "' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L`"<<endl;
    cout << "|'      _.-\"\"` `.    \\ _,'  `            \\ `.___`.'\"`-.  , |   |    | \\"<<endl;
    cout << "||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|"<<endl;
    cout << "||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||"<<endl;
    cout << "|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||"<<endl;
    cout << "||/            _,-------7 '              . |  `-'    l         /    `||"<<endl;
    cout << ". |          ,' .-   ,' ||               | .-.        `.      .'     ||"<<endl;
    cout << " `'        ,'    `\".'    |               |    `.        '. -.'       `'"<<endl;
    cout << "          /      ,'      |               |,'    \\-.._,.'/'"<<endl;
    cout << "          .     /        .               .       \\    .''"<<endl;
    cout << "        .`.    |         `.             /         :_,'.'"<<endl;
    cout << "          \\ `...\\   _     ,'-.        .'         /_.-'"<<endl;
    cout << "           `-.__ `,  `'   .  _.>----''.  _  __  /"<<endl;
    cout << "                .'        /\"'          |  \"'   '_"<<endl;
    cout << "               /_|.-'\\ ,\".             '.'`__'-( \\"<<endl;
    cout << "                 / ,\"'\"\\,'               `/  `-.|\" "<<endl;
	}

	else if (index == 9) {
    cout << "                                      ,\\'\\`--."<< endl;
    cout << "                                     |     __ `-."<< endl;
    cout << "                                     |    /  `.  `."<< endl;
    cout << "                                      \\        ,   `."<< endl;
    cout << "                                       `.      \\_    `."<< endl;
    cout << "                                         `.    | `.    \\"<< endl;
    cout << "                                           `--\"    `.   `"<< endl;
    cout << "                                                     `.  `"<< endl;
    cout << "                 ,.._                                  \\  `"<< endl;
    cout << "               /_,.  `.                                 \\  `"<< endl;
    cout << "              j/   .   \\                  ___            \\  \\"<< endl;
    cout << "              |    |   `____         _,--'   `.           .  L"<< endl;
    cout << "               L  /`--\"'    `'--._ ,'   ,-`'\\ |            . |"<< endl;
    cout << "                |-                /  ,''     ||            | |"<< endl;
    cout << "     -v._      /                   ,'        ||            | |"<< endl;
    cout << "       `.`-._,'               _     \\        |j    _,...   | |"<< endl;
    cout << "         `,.'             _,-. \\     |      /,---\"\"     `- | |"<< endl;
    cout << "        .'              ,\".   ||     `..___/,'            `' |"<< endl;
    cout << "        |   ,         _/`-'  /,'                            `|"<< endl;
    cout << "        |-.__.-'\"''\"\"' \"\"\"\"\"\"\"\"--`_,...-----''''--...--      `."<< endl;
    cout << "         `.____,..              \"\"   __,..---\"\"\"              |"<< endl;
    cout << "          |       `              --\"'.                        `"<< endl;
    cout << "          |     ,' `._                \\'                       `"<< endl;
    cout << "          | |  .^.    `.             /                          `."<< endl;
    cout << "         ,'_]__|  \\   / `.          /          /____._            `._"<< endl;
    cout << "       ,'          \\ j    '        /          /       `.             `."<< endl;
    cout << " ___,.' `._       __L/    |     __'          /     _, / \\             |"<< endl;
    cout << "`-._       L,.-\"\"\"  .    ,' _.-','          /-----'-./   `--.         |"<< endl;
    cout << "   '   / ,'         '..'\"_,'    /         F /  .\"'_,'        |.__     '"<< endl;
    cout << "  / ,.\\,'              \"\"      /         / (,'\\ .'        ,.-\"'  `.  j"<< endl;
    cout << "  -'   '                      /        ,'     `\"         / __/' .- ,'"<< endl;
    cout << "                           __.'\"`.    /                 `-' | _,L,'"<< endl;
    cout << "                         .',      `\"\"'                      '/,--"<< endl;
    cout << "                          / _..' _,,'"<< endl;
    cout << "                          ,' `-\"' "<< endl;
	}

	else if (index == 10) {
    cout << "                           _            _"<<endl;
    cout << "                          / )  _  _,.-\"\" )"<<endl;
    cout << "                        ,' /..' /\"   _,+'--\"`."<<endl;
    cout << "                       /     / j_.-\"'     ,-\""<<endl;
    cout << "                     ,'    ,'       _____  `"<<endl;
    cout << "                   _+__   .     _.-'     \\  `...._"<<endl;
    cout << "              ,'\"\"\"    \"\"/  _.-'          .       \\"<<endl;
    cout << "            ,'          '  ',--'\"\"`-.      L   ,-\""<<endl;
    cout << "          .\"              .'         \\     |  /"<<endl;
    cout << "        ,' _                          \\    | j      _"<<endl;
    cout << "       / ,'   _,+-'                 _,'   ,' /_,.-\"\" |"<<endl;
    cout << "    _.' '  .+'.  \\               ,-\"___..\"  -'      ,'"<<endl;
    cout << " ,-\"     ,'-' |  |           .,-\"\"''___,..-'       /"<<endl;
    cout << "j        `\"\"\"\"---'             '\"'\"\"       ._    , _.--\"."<<endl;
    cout << "\\   ,                                        `- ' `._  ,'"<<endl;
    cout << " \\                            _.-'            .\"`.   `-. ____...----\"\"`"<<endl;
    cout << "  `.-\"-._,..---+ +          ,'       `         `.'      `.             |"<<endl;
    cout << "      `.        \\/        ,'          |            ,.---. \\           ."<<endl;
    cout << "        `._               +__,...__   |     ,     |     |  L        .'"<<endl;
    cout << "           `--...-\"\"`-._   /       `,\"    ,'      `     |  |      ,'"<<endl;
    cout << "                     /  `./        /    ,'         \\    j  '    .'"<<endl;
    cout << "                    /    j        /    .       _    `._'     ,-'"<<endl;
    cout << "                   j     '       /     |     .\" `         ,-'"<<endl;
    cout << "                   |, .<(       '      `      \\_/       ,'"<<endl;
    cout << "                   |-...+.___,./`.______\\             ,'"<<endl;
    cout << "                   `.'`.' \\/  V /_/.___  `.  _     _,'"<<endl;
    cout << "                                `....\\_`,-\",' |,-./"<<endl;
    cout << "                                        `\"\"..-'---` "<<endl;
	}

	else if (index == 11) {
    cout << "        ,-\"\"'-.._"<<endl;
    cout << "   .---'\"\" \">` - `--"<<endl;
    cout << "   `.      `-._  .`-."<<endl;
    cout << "     `-.       \\ .` : -."<<endl;
    cout << "      _.>._     / ` `:..,"<<endl;
    cout << " ,.../...._`\"-./    '.|, `"<<endl;
    cout << "`---.._\"'-.`-._    |    \"'--."<<endl;
    cout << "       `--.\\`. `._,'         `.---------------.._"<<endl;
    cout << "            \"-'--.___          \\`'\"-..__         `-._"<<endl;
    cout << "                     `.\"`-\\     ` `\"--..\"`-.-..__    `\"."<<endl;
    cout << "                       `.  `.     |``._ `--. `-..`\"-._`.\\-."<<endl;
    cout << "                         \\   -....' `-.`-.  `-._ `-.  `-.\\ `."<<endl;
    cout << "                          `-.__  `.`-. `. `._   `._ `-.  `.  `."<<endl;
    cout << "                               `-..`` `. `.  `.    `.  `-.     \\"<<endl;
    cout << "                                   \\`.` `  `.  `.    `.   `-.   `."<<endl;
    cout << "                                    `.`-'`.  \\   .     `.    `.   \\"<<endl;
    cout << "                                      `..  \\  \\   \\      `.    `.,_`."<<endl;
    cout << "                                         \\` \\  .   `.     '\\     `.`.`._"<<endl;
    cout << "                                          \\``.  \\    \\     \\`.    |"<<endl;
    cout << "                                           ' '.  \\    \\     \\ \\   L"<<endl;
    cout << "                                             \\ \\  '    `    '. `.  \\"<<endl;
    cout << "                                              ` `. \\    `    '.  `. `."<<endl;
    cout << "                                               `. `,`.   `.   `.   `._."<<endl;
    cout << "                                                 `-  \\._   `.  `.     \"`"<<endl;
    cout << "                                                      ` `.   `.  ."<<endl;
    cout << "                                                          `-. ``-.:-."<<endl;
    cout << "                                                              -.`. '\"-'"<<endl;
    cout << "                                                                 `\"-. "<<endl;
	}

	else if (index == 12) {
    cout << "________                  ,d888888888b,                  ________ " << endl;
    cout << "     _.-;`               ,dP'         `Qb,           _.-`.`         " << endl;
    cout << "   .`  <           ,d88buP               ud88b,    <  .` " << endl;
    cout << "    `.  `.        dP   8`   ..       ..   `8   Qb    \\  `. " << endl;
    cout << "      `>  `,     dP .::8 _ :.@;  _  ;@.: _ 8::. Qb    `,  `> " << endl;
    cout << "     /`   /     ,8` .::dP        `.`        Qb::. `8,  /`  /` " << endl;
    cout << "   /`    `\\     dP .:::8(      `--^--`      )8:::. Qb `\\ /` " << endl;
    cout << "  `-,_     `\\   8` :::: Qba,..,       ,..,adP:::: `8   `-,_ " << endl;
    cout << "      ~-.  /`  ,8  ::::::,p`""         ""`q,::::::  8,   /` ~-. " << endl;
    cout << "      _-`/`   ,d` .:::::,d`               `b,:::::. `b,/`   _-` " << endl;
    cout << "  ,-`  `\\   ,d` .::::::d`                 `b::::::. `b\\ .-` " << endl;
    cout << "  `-,_    `\\,d` q888q8b,8    ,p       q,    8,d8p888p `b,\\`-. " << endl;
    cout << "      `-,.  d` d,  ;  `b,   8,       ,8   ,d`  ;  ,b `b `. `-,. " << endl;
    cout << "        .` ,8  8 `  `   `b,  `b,     ,d`  ,d`   `  ` 8  8 ,`  .` " << endl;
    cout << "       ,` / q, `b,       `b  a88a. .a88a  d`       ,d` ,p/  ,` " << endl;
    cout << "      <  `. `q,  `b,      8      8.8      8      ,d  ,p`. < " << endl;
    cout << "       `.  ; `Q888`b,    `Q8888P" "Q8888P`    ,d`888P`  ; `. " << endl;
    cout << "_____    `_`          Q888P              Q888P          `._;   ____ " << endl;
    cout << "                                                                   " << endl;
	}
	else if (index == 13) {
	cout << "	    .eec.              .e$ " << endl;
	cout << "   z$**$$eec..       zP  .3$c    " << endl;
	cout << "  .$`  d$`  ```****bee*=*`` *$ " << endl;
	cout << "  $%  d$$                   ^$% " << endl;
	cout << " .$  z$%$bc.                 $% " << endl;
	cout << " 4F 4$` $`^$*ec..  .ee.    ./` b " << endl;
	cout << " dF $P  P  F   `````3F````   4 " << endl;
	cout << "  4$$               $F         F " << endl;
	cout << "  ^$F   .......     $F        .F " << endl;
	cout << "   $`  z`     ^`````$F`````````%. " << endl;
	cout << "  4$  4F     e      $L          `. " << endl;
	cout << "  4F  ^L    4$     z%`c    *.    b " << endl;
	cout << "  d    ^$*=e$$eer=$`  `be..JL..ee* " << endl;
	cout << "  $     $   $F    $   zP   4P   F " << endl;
	cout << "  F     F   $F    4. .P    d%  J " << endl;
	cout << " 4%     F   $F     F $`   zP   P " << endl;
	cout << " J      F   '%     Fd`   4P   4` " << endl;
	cout << " $      F          $F         P " << endl;
	cout << " $      L         .$         4% " << endl;
	cout << " *      '.       .$$.       .$ " << endl;
	cout << " `       ^`****```  `*******$` " << endl;
	cout << "  %                        .P " << endl;
	cout << "   *c                     .@ " << endl;
	cout << "    ^`%            ...zed*  " << endl;
	cout << "       ^``````````` " << endl;
	}
	else if (index == 14) {
	cout << "  _ /\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/|  " << endl;
	cout << "| |/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/ | " << endl;
	cout << "| |   PLAYER                                                              | | " << endl;
	cout << "| |      Hello my lovely, ____                                            | | " << endl;
	cout << "| |      1. How are you? May I see your status?                           | | " << endl;
	cout << "| |      2. I will give you a new name                                    | | " << endl;
	cout << "| |      3. Let's go find wild engimon together                           | | " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/| " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/  " << endl;
	}
	else if (index == 15) {
	cout << "  _ /\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/|  " << endl;
	cout << "| |/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/ | " << endl;
	cout << "| |   ENGIMON                                                             | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |        Hmmm, I'm fine. Yeah Master, I will show my status             | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/| " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/  " << endl;
	}
	else if (index == 16) {
	cout << "  _ /\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/|  " << endl;
	cout << "| |/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/ | " << endl;
	cout << "| |   ENGIMON                                                             | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |        Yeayyyy, with pleasure Master                                  | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/| " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/  " << endl;
	}
	else if (index == 17) {
	cout << "  _ /\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/|  " << endl;
	cout << "| |/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/ | " << endl;
	cout << "| |   ENGIMON                                                             | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |        Yosh, Lets GOOO!!!!                                            | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/| " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/  " << endl;
	}
	else if (index == 18) {
	cout << "  _ /\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/|  " << endl;
	cout << "| |/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/ | " << endl;
	cout << "| |   ENGIMON                                                             | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |       Master, let's win this match together                           | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/| " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/  " << endl;
	}
	else if (index == 19) {
	cout << "  _ /\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/|  " << endl;
	cout << "| |/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/ | " << endl;
	cout << "| |   ENGIMON                                                             | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |       Oh shit, the enemy damage was massive.                          | | " << endl;
	cout << "| |       Sorry sir, I can't survive anymore                              | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/| " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/  " << endl;
	}
	else if (index == 20) {
	cout << "  _ /\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/|  " << endl;
	cout << "| |/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/ | " << endl;
	cout << "| |   ENGIMON                                                             | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |       Yeyey yeyey, we did it master                                   | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/| " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/  " << endl;
	}
	else if (index == 21) {
	cout << "  _ /\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/|  " << endl;
	cout << "| |/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/ | " << endl;
	cout << "| |   PLAYER                                                              | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |       Oww wow, we found wild engimon! Let's catch it!                 | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/| " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/  " << endl;
	}
	else if (index == 22) {
	cout << "  _ /\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/|  " << endl;
	cout << "| |/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/ | " << endl;
	cout << "| |   WILD ENGIMON                                                        | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |       What? If you want to have me, you have to beat me first         | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "| |                                                                       | | " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/| " << endl;
	cout << "|/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\/  " << endl;
	}
}