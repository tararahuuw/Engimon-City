#include "peta.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int Peta::engimonId = 0;

Peta::Peta(int b, int k){
	this->baris = b;
	this->kolom = k;
	this->nElmt = b*k;
	this->isiPeta = new char[this->nElmt];
	for(int i=0; i<this->nElmt; i++){
		this->isiPeta[i] = 'x';
	}
	this->PetaTetap = new char[this->nElmt];
	for(int i=0; i<this->nElmt; i++){
		this->PetaTetap[i] = 'x';
	}
	this->BykEngimonLiar = 0;
	this->PosisiEngimon = vector<int> ();
	this->DaftarEngimon = vector<pair<int, Engimon> > ();
}

Peta::Peta(const Peta& P){
	this->baris = P.baris;
	this->kolom = P.kolom;
	this->nElmt = P.nElmt;
	this->isiPeta = new char[this->nElmt];
	for(int i=0; i<this->nElmt; i++){
		this->isiPeta[i] = P.isiPeta[i];
	}
	this->PetaTetap = new char[this->nElmt];
	for(int i=0; i<this->nElmt; i++){
		this->PetaTetap[i] = P.isiPeta[i];
	}
	this->PosisiEngimon = vector<int> ();
	for (int i = 0; i < this->PosisiEngimon.size(); i++){
        this->PosisiEngimon[i] == P.PosisiEngimon[i];
    }
	// this->DaftarEngimon = vector<pair<int, Engimon> > ();
	// for (int i = 0; i < this->PosisiEngimon.size(); i++){
    //     this->DaftarEngimon[i] == P.DaftarEngimon[i];
    // }
	this->BykEngimonLiar = P.BykEngimonLiar;
	//this->DaftarEngimon = new Engimon[20];
}

Peta::~Peta(){
	delete[] this->isiPeta;
	delete[] this->PetaTetap;
}

Peta& Peta::operator=(const Peta& P){
	delete[] this->isiPeta;
	delete[] this->PetaTetap;
	this->baris = P.baris;
	this->kolom = P.kolom;
	this->nElmt = P.nElmt;
	this->isiPeta = new char[this->nElmt];
	for(int i=0; i<this->nElmt; i++){
		this->isiPeta[i] = P.isiPeta[i];
	}
	this->PetaTetap = new char[this->nElmt];
	for(int i=0; i<this->nElmt; i++){
		this->PetaTetap[i] = P.isiPeta[i];
	}
	this->PosisiEngimon = vector<int> ();
	for (int i = 0; i < this->PosisiEngimon.size(); i++){
        this->PosisiEngimon[i] == P.PosisiEngimon[i];
    }
	// this->DaftarEngimon = vector<pair<int, Engimon> > ();
	// for (int i = 0; i < this->PosisiEngimon.size(); i++){
    //     this->DaftarEngimon[i] == P.DaftarEngimon[i];
    // }

}

char Peta::GetElementPeta(int b, int k){
	if(b > this->baris || b < 0 || k > this->kolom || k < 0){
		throw ("Index Out of Range");
	} else {
		return this->isiPeta[(b*this->kolom)+k];
	}
}

char Peta::GetElementPeta(int posisi){
	if(posisi < 0 || posisi >= this->nElmt){
		throw ("Index Out of Range");
	} else {
		return this->isiPeta[posisi];
	}

}

char Peta::GetElementPetaTetap(int b, int k){
	if(b > this->baris || b < 0 || k > this->kolom || k < 0){
		throw ("Index Out of Range");
	} else {
		return this->PetaTetap[(b*this->kolom)+k];
	}
}

char Peta::GetElementPetaTetap(int posisi){
	if(posisi < 0 || posisi >= this->nElmt){
		throw ("Index Out of Range");
	} else {
		return this->PetaTetap[posisi];
	}

}

void Peta::SetElementPeta(int b, int k, char element){
	if(b > this->baris || b < 0 || k > this->kolom || k < 0){
		throw ("Index Out of Range");
	} else {
		this->isiPeta[(b*this->kolom)+k] = element;
	}
}

void Peta::SetElementPeta(int index, char element){
	if(index < 0 || index >= this->nElmt){
		throw ("Index Out of Range");
	} else {
		this->isiPeta[index] = element;
	}
}

int Peta::GetEngimonId(){
	return engimonId;
}

void Peta::BacaFile(){
	ifstream obj("map.txt");
	char element;
	int index = 0;
	if(obj.is_open()){
		while (!obj.eof()){
			obj.get(element);
			if(!isspace(element)){
				this->isiPeta[index] = element;
				this->PetaTetap[index] = element;
				index++;
			}
		}
		
	} else {
		cout << "File map tidak dapat dibuka" << endl;
	}
}

void Peta::PrintPeta(){
	for(int i = 0; i < this->baris; i++){
		for(int j =0; j < this->kolom; j++){
			cout << GetElementPeta(i,j) << " ";
		}
		cout << endl;
	}
}

void Peta::PrintDaftarEngimon(){
	for(int i = 0; i < this->BykEngimonLiar; i++){
		cout << this->DaftarEngimon[i].first << endl;
	}
}

void Peta::PrintPosisiEngimon(){
	for(int i = 0; i < this->BykEngimonLiar; i++){
		cout << this->PosisiEngimon[i] << endl;
	}
}

void Peta::AddEngimon(pair<int, Engimon> e, int posisi){
	this->DaftarEngimon.push_back(e);
	this->PosisiEngimon.push_back(posisi);
	this->BykEngimonLiar++;
	engimonId++;
}

//kalo engimonnya sudah berhasil dijinakkan hapus dari DaftarEngimon
void Peta::DeleteEngimon(pair<int, Engimon> e){
	for (int i = 0; i != this->BykEngimonLiar; i++){
		if(DaftarEngimon[i].first == e.first){
			DaftarEngimon.erase(DaftarEngimon.begin() + i);
			PosisiEngimon.erase(PosisiEngimon.begin() + i);
			this->BykEngimonLiar--;
			break;
		}
	}
}

void Peta::SelectNama(char Engimon, string *nama, int *health){
	string fire1[3] = {"Snorlax", "Porygon", "Eevee"};
	string fire2[3] = {"Chansey", "Kangaskhan", "Meowth"};
	string ground1[3] = {"Bulbasaur", "Venusaur", "Weepinbell"};
	string ground2[3] = {"Tangela", "Exeggutor", "Victreebel"};
	string electric1[3] = {"Zapdos", "Magnemite", "Voltorb"};
	string electric2[3] = {"Pikachu", "Electabuzz", "Electrode"};
	string water1[3] = {"Wartortle", "Blastoise", "Poliwhirl"};
	string water2[3] = {"Dewgong", "Vaporeon", "Cloyster"};
	string ice1[3] = {"Articuno", "Jynx", "Lapras"};
	string ice2[3] = {"Cloyster", "Dewgong", "Seel"};
	string random;
	if(Engimon == 'f'){
		random = fire1[rand() % 3];
		*health = 300;
	} else if(Engimon == 'F'){
		random = fire2[rand() % 3]; 
		*health = 400;
	} else if(Engimon == 'g'){
		random = ground1[rand() % 3];
		*health = 300;
	} else if(Engimon == 'G'){
		random = ground2[rand() % 3];
		*health = 400;
	} else if(Engimon == 'e'){
		random = electric1[rand() % 3];
		*health = 300;
	} else if(Engimon == 'E'){
		random = electric2[rand() % 3]; 
		*health = 400;
	} else if(Engimon == 'w'){
		random = water1[rand() % 3];
		*health = 450;
	} else if(Engimon == 'W'){
		random = water2[rand() % 3];
		*health = 500;
	} else if(Engimon == 'i'){
		random = ice1[rand() % 3];
		*health = 500;
	} else if(Engimon == 'I'){
		random = ice2[rand() % 3];
		*health = 550;
	}
	*nama = random;
	 
}

void Peta::SpawnEngimon(int BanyakSpawn){
	int posisi, level;
	//int BanyakSpawn = 10;
	posisi = rand() % (this->nElmt);
	level = rand(); //mod dengan max level dari engimon
	char grass[] = "fFgGeE";
	char sea[] = "wiWI";
	char engimonTerpilih;
	KatalogEngimon katalogengimon;
	string namaEngimon;
	int health;
	for(int i = 0; i < BanyakSpawn; i++){
		while(this->isiPeta[posisi] != '-' && this->isiPeta[posisi] != 'o'){
			posisi = rand() % (this->nElmt);
		}
		//random level
		if(engimonTerpilih == 'f' || engimonTerpilih == 'g' || engimonTerpilih == 'e' || engimonTerpilih == 'w' || engimonTerpilih == 'i'){
			level = rand() % MIN_LEVEL;
		} else {
			level = (rand() % (MIN_LEVEL + 1)) + MIN_LEVEL;
		}
		//construc engimon
		if(this->isiPeta[posisi] == '-'){
			engimonTerpilih = grass[rand() % 6];
			//set di peta
			SetElementPeta(posisi, engimonTerpilih);
			//SelectNama(engimonTerpilih,&namaEngimon, &health);
			//cout << namaEngimon << endl;
			//create obj engimon
			// pair<int, char> PAIR1; 
			// PAIR1.first = 100; 
			// PAIR1.second = 'G';

			cout << engimonTerpilih << endl;
			cout << posisi << endl;

			//masukin ke daftar engimon
		} else if(this->isiPeta[posisi] == 'o'){
			engimonTerpilih = sea[rand() % 4];
			//set di peta
			SetElementPeta(posisi, engimonTerpilih);
			// SelectNama(engimonTerpilih,&namaEngimon, &health);
			// cout << namaEngimon << endl;
			cout << engimonTerpilih << endl;
			cout << posisi << endl;
			//create engimon
			//masukin ke daftar engimon
		}
		//dtor engimon
	}
}



void Peta::TukarPosisi(int posisibaru, int posisisekarang){
	if(GetElementPeta(posisibaru) == 'P'){
		throw false;
	} else {
		SetElementPeta(posisibaru, GetElementPeta(posisisekarang));
		SetElementPeta(posisisekarang, GetElementPetaTetap(posisisekarang));
	}
}

void Peta::GerakinSemuaEngimon(){
	//iterasi tiap element pada pada daftar engimon
	//untuk geraknya di random
	for (int i = 0; i != this->BykEngimonLiar; i++){
		int posisi = rand() % (this->nElmt);
		while(GetElementPeta(posisi) != GetElementPetaTetap(PosisiEngimon[i]) || GetElementPeta(posisi) == 'X'){
			posisi = rand() % (this->nElmt);
		}
		try{
			//ubah element pada isipeta
			TukarPosisi(posisi, PosisiEngimon[i]);
			PosisiEngimon[i] = posisi;
		} catch(bool f){
			//tetap ditempat engimon yang diacu
		}
	}
}

int main(){
	Peta P(14, 14);
	P.BacaFile();
	//P.PrintPeta();
	//P.SpawnEngimon(10);
	//P.PrintPeta();
	P.SpawnEngimon(5);
	P.PrintPeta();
	int g = P.GetEngimonId();
	cout << g << endl;
	return 0;
}

