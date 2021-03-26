#include "peta.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

Peta::Peta(){
	//ukaran default 14x14
	this->baris = 14;
	this->kolom = 14;
	this->nElmt = this->baris * this->kolom;
	this->isiPeta = new char[this->nElmt];
	for(int i=0; i<this->nElmt; i++){
		this->isiPeta[i] = 'x';
	}
	this->PetaTetap = new char[this->nElmt];
	for(int i=0; i<this->nElmt; i++){
		this->PetaTetap[i] = 'x';
	}
	this->DaftarEngimon = vector<pair<int, Engimon> > ();
}

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
	return *this;
}

int Peta::GetBaris(){
	return this->baris;
}

int Peta::GetKolom(){
	return this->kolom;
}

int Peta::GetBarisObjek(int posisi){
	return (posisi / this->kolom);
}

int Peta::GetKolomObjek(int posisi){
	//int temp = posisi / this->kolom;
	return (posisi % this->kolom);
}

pair<int, Engimon> Peta::GetDaftarEngimon(int index){
	return this->DaftarEngimon[index];
}

char Peta::GetElementPeta(int b, int k){
	if(b > this->baris || b < 0 || k > this->kolom || k < 0){
		throw InvalidIndexException();
	} else {
		return this->isiPeta[(b*this->kolom)+k];
	}
}

char Peta::GetElementPeta(int posisi){
	if(posisi < 0 || posisi >= this->nElmt){
		throw InvalidIndexException();
	} else {
		return this->isiPeta[posisi];
	}

}

char Peta::GetElementPetaTetap(int b, int k){
	if(b > this->baris || b < 0 || k > this->kolom || k < 0){
		throw InvalidIndexException();
	} else {
		return this->PetaTetap[(b*this->kolom)+k];
	}
}

char Peta::GetElementPetaTetap(int posisi){
	if(posisi < 0 || posisi >= this->nElmt){
		throw InvalidIndexException();
	} else {
		return this->PetaTetap[posisi];
	}

}

void Peta::SetElementPeta(int b, int k, char element){
	if(b > this->baris || b < 0 || k > this->kolom || k < 0){
		throw InvalidIndexException();
	} else {
		this->isiPeta[(b*this->kolom)+k] = element;
	}
}

void Peta::SetElementPeta(int index, char element){
	if(index < 0 || index >= this->nElmt){
		throw InvalidIndexException();
	} else {
		this->isiPeta[index] = element;
	}
}

//untuk dapetin engimon pada posisi (x,y)
Engimon Peta::GetEngimonLiar(int x, int y){
	int posisi = (x*this->kolom)+y;
	Engimon e;
	for (int i = 0; i != this->DaftarEngimon.size(); i++){
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
	for (int i = 0; i != this->DaftarEngimon.size(); i++){
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
	for(int i = 0; i < this->DaftarEngimon.size(); i++){
		cout << "posisi : " << this->DaftarEngimon[i].first << endl;
		cout << this->DaftarEngimon[i].second << endl;
	}
}

//isi pair itu posisi dari engimon dan data engimon
void Peta::AddEngimon(pair<int, Engimon> e){ 
	this->DaftarEngimon.push_back(e);
	//cout << "berhasil" << endl;
}

//kalo engimonnya sudah berhasil dijinakkan hapus dari DaftarEngimon
void Peta::DeleteEngimon1(pair<int, Engimon> e){
	for (int i = 0; i != this->DaftarEngimon.size(); i++){
		if(DaftarEngimon[i].first == e.first){
			//cout << "berhasil delete1" << endl;
			//ubah isi peta
			SetElementPeta(e.first, GetElementPetaTetap(e.first));
			this->DaftarEngimon.erase(this->DaftarEngimon.begin() + i); 
			//cout << "berhasil delete" << endl;
			return;
		}
	}
}

void Peta::DeleteEngimon2(int x, int y){
	pair<int, Engimon> e = GetEngimonforDelete(x,y);
	DeleteEngimon1(e);
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
	} else if(e == 'i' || e == 'I') {
		if(random == 0){
			spesies = DaftarSpecies[4];
		} else {
			spesies = DaftarSpecies[12];
		}
	} else  if(e == 'l' || e == 'L') {
		if(random == 0){
			spesies = DaftarSpecies[5];
		} else {
			spesies = DaftarSpecies[13];
		}
	} else  if(e == 's' || e == 'S') {
		if(random == 0){
			spesies = DaftarSpecies[6];
		} else {
			spesies = DaftarSpecies[14];
		}
	} else  { //if(e == 'n' || e == 'N')
		if(random == 0){
			spesies = DaftarSpecies[7];
		} else {
			spesies = DaftarSpecies[15];
		}
	}

	Engimon engimon(spesies, level, 0, 0, true, true);
	*engi = engimon;
	cout << engi->getSpecies()->getName() << endl;
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


//0 : untuk yg  groud; 1 : untuk yg sea; 2 : untuk 
int Peta::CekElementEngimonRandom(char engimonTerpilih){
	if(engimonTerpilih == 'f' || engimonTerpilih == 'g' || engimonTerpilih == 'e' || engimonTerpilih == 'F' || engimonTerpilih == 'G' || engimonTerpilih == 'E'){
		return 0;
	} else if(engimonTerpilih == 'w' || engimonTerpilih == 'i' || engimonTerpilih == 'W' || engimonTerpilih == 'I'){
		return 1;
	}
	//untuk yg double element
	return 2;
}

int Peta::RandomPosisi(char engimonTerpilih, int cek){
	int posisi;
	if(cek == 0){
		posisi = rand() % (this->nElmt);
		while(this->isiPeta[posisi] != '-'){
			posisi = rand() % (this->nElmt);
		}
	} else if(cek == 1){
		posisi = rand() % (this->nElmt);
		while(this->isiPeta[posisi] != 'o'){
			posisi = rand() % (this->nElmt);
		}
	} else { //cek == 2
		posisi = rand() % (this->nElmt);
		while(this->isiPeta[posisi] != '-' && this->isiPeta[posisi] != 'o'){
			posisi = rand() % (this->nElmt);
		}
	}
	return posisi;
}

void Peta::SpawnEngimon(){
	int posisi, level;
	int BanyakSpawn = MAX_SPAWN - this->DaftarEngimon.size();
	posisi = rand() % (this->nElmt);
	char draft[] = "fFgGeEwiWIlLsSnN";
	char engimonTerpilih;
	for(int i = 0; i < BanyakSpawn; i++){
		engimonTerpilih = draft[rand() % 16];
		posisi = RandomPosisi(engimonTerpilih, CekElementEngimonRandom(engimonTerpilih));
		Engimon e;
		//set di peta
		SetElementPeta(posisi, engimonTerpilih);
		//random level
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
}


void Peta::TukarPosisi(int posisisekarang, int index){
	int posisibaru = rand() % (this->nElmt);
	char simbol = GetElementPeta(posisisekarang);
	if(GetElementPeta(posisibaru) == 'P'){
		throw false;
	} else {
		posisibaru = RandomPosisi(simbol, CekElementEngimonRandom(simbol));
		SetElementPeta(posisibaru, GetElementPeta(posisisekarang));
		SetElementPeta(posisisekarang, GetElementPetaTetap(posisisekarang));
		DaftarEngimon[index].first = posisibaru;
	}
}

//untuk geraknya di random
void Peta::GerakinSemuaEngimon(){
	//iterasi tiap element pada pada daftar engimon
	int posisi;
	for (int i = 0; i != this->DaftarEngimon.size(); i++){
		try{
			//ubah element pada isipeta
			TukarPosisi(DaftarEngimon[i].first, i);
		} catch(bool f){
			//tetap ditempat engimon yang diacu
		}
	}
}


