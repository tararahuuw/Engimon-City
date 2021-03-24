#include "peta.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

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

	this->DaftarEngimon = P.DaftarEngimon;
	this->BykEngimonLiar = P.BykEngimonLiar;
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

	this->DaftarEngimon = P.DaftarEngimon;
	this->BykEngimonLiar = P.BykEngimonLiar;

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

//untuk dapetin engimon pada posisi (x,y)
Engimon Peta::GetEngimonLiar(int x, int y){
	int posisi = (x*this->kolom)+y;
	Engimon e;
	for (int i = 0; i != this->BykEngimonLiar; i++){
		if(DaftarEngimon[i].first == posisi){
			e = DaftarEngimon[i].second;
		}
	}
	return e;
}

pair<int, Engimon> Peta::GetEngimonforDelete(int x, int y){
	int posisi = (x*this->kolom)+y;
	pair<int, Engimon> result;
	Engimon e;
	for (int i = 0; i != this->BykEngimonLiar; i++){
		if(DaftarEngimon[i].first == posisi){
			result =  DaftarEngimon[i];
		}
	}
	//cout << "berhasil get" << endl;
	return result;
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
		cout << "posisi : " << this->DaftarEngimon[i].first << endl;
		cout << this->DaftarEngimon[i].second << endl;
	}
}

//isi pair itu posisi dari engimon dan data engimon
void Peta::AddEngimon(pair<int, Engimon> e){ 
	this->DaftarEngimon.push_back(e);
	this->BykEngimonLiar++;
	//cout << "berhasil" << endl;
}

//kalo engimonnya sudah berhasil dijinakkan hapus dari DaftarEngimon
void Peta::DeleteEngimon(pair<int, Engimon> e){
	for (int i = 0; i != this->BykEngimonLiar; i++){
		if(DaftarEngimon[i].first == e.first){
			//cout << "berhasil delete1" << endl;
			//ubah isi peta
			SetElementPeta(e.first, GetElementPetaTetap(e.first));
			this->DaftarEngimon.erase(this->DaftarEngimon.begin() + i); 
			this->BykEngimonLiar--;
			//cout << "berhasil delete" << endl;
			return;
		}
	}
}

void Peta::CreateEngimon(char e, int level, Engimon *engi){
	SpeciesFactory DaftarSpecies;
	SkillsFactory skills;
	DaftarSpecies.initSpecies();
	Species* spesies;
	int random = rand() % 2;
	if(e == 'f' || e == 'F'){
		if(random == 0){
			spesies = DaftarSpecies[0];
		} else {
			spesies = DaftarSpecies[8];
		}
	} else if(e == 'e' || e == 'E'){
		if(random == 0){
			spesies = DaftarSpecies[2];
		} else {
			spesies = DaftarSpecies[10];
		}
	} else if(e == 'g' || e == 'G'){
		if(random == 0){
			spesies = DaftarSpecies[3];
		} else {
			spesies = DaftarSpecies[11];
		}
	} else if(e == 'w' || e == 'W') {
		if(random == 0){
			spesies = DaftarSpecies[1];
		} else {
			spesies = DaftarSpecies[9];
		}
	} else  { //if(e == 'i' || e == 'I')
		if(random == 0){
			spesies = DaftarSpecies[4];
		} else {
			spesies = DaftarSpecies[12];
		}
	} 

	Engimon engimon(spesies, level, 0, 0, true, false);
	*engi = engimon;
}

int Peta::selectlevel(char engimonTerpilih){
	int level;
	//random level
	if(engimonTerpilih == 'f' || engimonTerpilih == 'g' || engimonTerpilih == 'e' || engimonTerpilih == 'w' || engimonTerpilih == 'i'){
		level = (rand() % MIN_LEVEL + 1);
	} else {
		level = (rand() % (MIN_LEVEL + 1)) + MIN_LEVEL;
	}
	//cout << level << endl;
	return level;
}

void Peta::SpawnEngimon(int BanyakSpawn){
	int posisi, level;
	//int BanyakSpawn = 10;
	posisi = rand() % (this->nElmt);
	char grass[] = "fFgGeE";
	char sea[] = "wiWI";
	char engimonTerpilih;
	for(int i = 0; i < BanyakSpawn; i++){
		//posisi = rand() % (this->nElmt);
		while(this->isiPeta[posisi] != '-' && this->isiPeta[posisi] != 'o'){
			posisi = rand() % (this->nElmt);
		}
		Engimon e;
		if(this->isiPeta[posisi] == '-'){
			engimonTerpilih = grass[rand() % 6];
			//set di peta
			SetElementPeta(posisi, engimonTerpilih);
			level = selectlevel(engimonTerpilih);
			//create obj engimon
			CreateEngimon(engimonTerpilih, level, &e);
			pair<int, Engimon> engimon; 
			engimon.first = posisi;
			engimon.second = e;

			//masukin ke daftar engimon
			AddEngimon(engimon);
			// cout << engimonTerpilih << endl;
			// cout << posisi << endl;

		} else if (this->isiPeta[posisi] == 'o'){
			engimonTerpilih = sea[rand() % 4];
			//set di peta
			SetElementPeta(posisi, engimonTerpilih);
			level = selectlevel(engimonTerpilih);
			//create obj engimon
			CreateEngimon(engimonTerpilih, level, &e);
			pair<int, Engimon> engimon; 
			engimon.first = posisi;
			engimon.second = e;

			//masukin ke daftar engimon
			AddEngimon(engimon);
			// cout << engimonTerpilih << endl;
			// cout << posisi << endl;
		}
		//cout << i << endl;
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
		while(GetElementPeta(posisi) != GetElementPetaTetap(DaftarEngimon[i].first) || GetElementPeta(posisi) == 'X'){
			posisi = rand() % (this->nElmt);
		}
		try{
			//ubah element pada isipeta
			TukarPosisi(posisi, DaftarEngimon[i].first);
			DaftarEngimon[i].first = posisi;
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
	//int g = P.GetEngimonId();
	//cout << g << endl;
	// P.PrintDaftarEngimon();
	// P.GerakinSemuaEngimon();
	// P.PrintPeta();
	// P.PrintDaftarEngimon();
	//pair<int, Engimon> deleted = P.GetEngimonforDelete(2,13);
	P.DeleteEngimon(P.GetEngimonforDelete(2,13));
	P.PrintDaftarEngimon();
	P.PrintPeta();
	// P.DeleteEngimon(P.DaftarEngimon[3]);
	// P.PrintDaftarEngimon();
	return 0;
}

