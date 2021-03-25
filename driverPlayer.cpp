#include <bits/stdc++.h>
#include "Player.h"
#include "Species.h"
using namespace std;

int main(){
	Peta peta(14,14);
	peta.BacaFile();
	Player player1(make_pair(13,13), peta);
	

	// player1.viewListEngimon();
	// cout << "Yeet" << endl;
	player1.lihatPeta();	
	player1.moveW();
	player1.lihatPeta();
	int x;
	cin >> x;
	// player1.viewListSkill();
	try{
		player1.activateEngimon(x);
	}catch (exception e){
		cout << e.what() << endl;
	}
	player1.lihatPeta();
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