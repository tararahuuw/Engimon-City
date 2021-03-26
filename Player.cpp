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
				int ele2 = enemy.getElement().at(0); //yang dipake elemen enemy pertama
				int x = rand() % sf.getSkills().size();
				Skill s = sf[x];

				while(count(s.getElement().begin(),s.getElement().end(),ele2) == 0) { //skill randomnya beda elemen
					x = (x + 1) % sf.getSkills().size();
					s = Skill(sf[x]);
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
			cin >> answer;
		}

	}
	return hasil;
}

void Player:: initBattle(){
	if (this->isThereActiveEngimon and this->isEnemyAround()){
		pair<int,int> coorEnemy = this->getEnemyAround();
		Engimon enemy = this->peta.GetEngimonLiar(coorEnemy.first,coorEnemy.second);
		cout << enemy << endl;
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