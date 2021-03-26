#include "peta.cpp"
#include <bits/stdc++.h>
using namespace std;

int main(){
	Peta P(14, 14);
	string filename;
	cout << "masukkan nama file : ";
	cin >> filename;
	if(P.BacaFile(filename) != true) {
		exit(1);
	}
	//P.PrintPeta();
	//P.SpawnEngimon(10);
	//P.PrintPeta();
	P.SpawnEngimon();
	P.PrintPeta();
	//pair<int, Engimon> tmp = P.GetDaftarEngimon(0);
	// int b = P.GetBarisObjek(P.GetDaftarEngimon(2).first);
	// int k = P.GetKolomObjek(P.GetDaftarEngimon(2).first);
	// cout << b << endl;
	// cout << k << endl;
	//int g = P.GetEngimonId();
	//cout << g << endl;
	P.PrintDaftarEngimon();
	// P.GerakinSemuaEngimon();
	// P.PrintPeta();
	// P.PrintDaftarEngimon();
	//pair<int, Engimon> deleted = P.GetEngimonforDelete(2,13);
	//P.DeleteEngimon2(2,13);
	//P.PrintDaftarEngimon();
	//P.PrintPeta();
	// P.DeleteEngimon(P.DaftarEngimon[3]);
	// P.PrintDaftarEngimon();
	return 0;
}