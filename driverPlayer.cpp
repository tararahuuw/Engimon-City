#include <bits/stdc++.h>
#include "Player.h"
#include "Species.h"
using namespace std;

int main(){
	// Inventory<Engimon> tes;
	// SpeciesFactory katalogspecies;
	// katalogspecies.initSpecies();
	// Species* A = katalogspecies[0];
	// Species* L = katalogspecies[2];
	// Species* T = katalogspecies[1];
	// Engimon Alam(A, "Alam", "", "", "", "", 1, 0, 0, false, false);
	// Engimon Chelsie(L, "Chelsie", "", "", "", "", 1,0,0,false, false);
	// Engimon Monica(T, "Monica", "", "", "", "", 1, 0, 0, false, false);
	// tes.addElement(Alam);
	// tes.addElement(Chelsie);
	// tes.addElement(Monica);
	// tes.viewList();
	// tes.delElementIndexX(1);
	// tes.viewList();
	Player player1(make_pair(0,0));
	// SkillsFactory katalogskill;
	// SpeciesFactory katalogengimon;

	// Engimon a;
	// Engimon b;
	// Engimon c;
	// Engimon d;
	// Skill e = katalogskill[0];
	// try{
	// 	player1.addEngimonToInven(a);
	// 	player1.addSkillItemToInven(e);
	// 	player1.addEngimonToInven(d);

	// }catch (const char* e){
	// 	cout << e<< endl;
	// }catch (exception& e){
	// 	cout << e.what() << endl;
	// }
	// SingleType tes;
	// Species* cuy = new SingleType();
	// if (cuy->isSingleElement()) cout << "Hmm" << endl;

	player1.viewListEngimon();
	// cout << "Yeet" << endl;
	
	int x;
	cin >> x;
	// player1.viewListSkill();
	try{
		player1.activateEngimon(x);
	}catch (exception e){
		cout << e.what() << endl;
	}
	cout << "bruh" <<endl;
	cout << player1.getListEng().getSize() << endl;
	if (player1.getListEng().getElementX(1).getSpecies()->isSingleElement()) cout <<"salahku apa?" << endl;
	if (player1.getActiveEngimon().getSpecies()->isSingleElement()) cout <<"salahku apa?" << endl;
	player1.viewListEngimon();
	player1.viewListSkill();
	cin >> x;
	try{
		player1.learnSkill(x);
	}catch (exception e){
		cout << e.what() << endl;
	}
	player1.viewListSkill();
	try{
		cout << player1.getActiveEngimon() << endl;
	}catch (exception e){
		cout << e.what() << endl;
	}
	
}