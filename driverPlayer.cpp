#include "Player.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	Inventory<int> test;
	// try{

	// }catch(exception& e){
	// 	e.what();
	// }
	try{
		test.delElementIndexX(2);
	}catch(const char* e){
		cout << e<<endl;
	}

	try{
		test.getElementX(5);
	}catch(exception& e){
		cout << e.what() << endl;
	}
	for (int i = 0 ; i < 6; i++){
		test.addElement(i);
	}
	int elementLast;
	try{
		elementLast = test.delElementIndexX(5);
	}catch (const char* e){
		cout << e << endl;
	}
}