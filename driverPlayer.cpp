#include <bits/stdc++.h>
#include "Player.h"
#include "Species.h"
using namespace std;

int main(){
	
	Player player1(make_pair(0,0));
	SkillsFactory katalogskill;
	SpeciesFactory katalogengimon;

	Engimon a;
	Engimon b;
	Engimon c;
	Engimon d;
	Skill e = katalogskill[0];
	try{
		player1.addEngimonToInven(a);
		player1.addSkillItemToInven(e);
		player1.addEngimonToInven(d);

	}catch (const char* e){
		cout << e<< endl;
	}catch (exception& e){
		cout << e.what() << endl;
	}
	player1.viewListEngimon();
	// cout << "Yeet" << endl;
	player1.viewListSkill();
	player1.activateEngimon(0);
	player1.viewListEngimon();
}