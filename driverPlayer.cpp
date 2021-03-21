#include <bits/stdc++.h>
#include "Player.h"
using namespace std;

int main(){
	// Inventory<int> test;
	// // try{

	// // }catch(exception& e){
	// // 	e.what();
	// // }
	// try{
	// 	test.delElementIndexX(2);
	// }catch(const char* e){
	// 	cout << e<<endl;
	// }

	// try{
	// 	test.getElementX(5);
	// }catch(exception& e){
	// 	cout << e.what() << endl;
	// }
	// for (int i = 0 ; i < 6; i++){
	// 	test.addElement(i);
	// }
	// int elementLast;
	// try{
	// 	elementLast = test.delElementIndexX(5);
	// }catch (const char* e){
	// 	cout << e << endl;
	// }
	Player player1;
	KatalogSkill katalogskill;
	KatalogEngimon katalogengimon;
	//katalogskill.printtKatalogSkill();
	// katalogengimon.printKatalogEngimon();
	Engimon a = katalogengimon[0];
	Engimon b = katalogengimon[1];
	Engimon c = katalogengimon[2];
	Engimon d = katalogengimon[3];
	Skill e = katalogskill[0];
	try{
		player1.addEngimonToInven(a);
		player1.addSkillItemToInven(e);
		player1.addSkillItemToInven(e);
		player1.addEngimonToInven(d);

	}catch (const char* e){
		cout << e<< endl;
	}
	player1.viewListEngimon();
	player1.viewListSkill();
}