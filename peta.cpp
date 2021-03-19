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
}

Peta::Peta(const Peta& P){
	this->baris = P.baris;
	this->kolom = P.kolom;
	this->nElmt = P.nElmt;
	this->isiPeta = new char[this->nElmt];
	for(int i=0; i<this->nElmt; i++){
		this->isiPeta[i] = P.isiPeta[i];
	}
}

Peta::~Peta(){
	delete[] this->isiPeta;
}

Peta& Peta::operator=(const Peta& P){
	delete[] this->isiPeta;
	this->baris = P.baris;
	this->kolom = P.kolom;
	this->nElmt = P.nElmt;
	this->isiPeta = new char[this->nElmt];
	for(int i=0; i<this->nElmt; i++){
		this->isiPeta[i] = P.isiPeta[i];
	}
}

char Peta::GetElementPeta(int b, int k){
	if(b > SIZE_ROW || b < 0 || k > SIZE_COL || k < 0){
		throw ("Index Out of Range");
	} else {
		return this->isiPeta[(b*SIZE_COL)+k];
	}
}

void Peta::SetElementPeta(int b, int k, char element){
	if(b > SIZE_ROW || b < 0 || k > SIZE_COL || k < 0){
		throw ("Index Out of Range");
	} else {
		this->isiPeta[(b*SIZE_COL)+k] = element;
	}
}

void Peta::SetElementPeta(int index, char element){
	if(index < 0 || index >= this->nElmt){
		throw ("Index Out of Range");
	} else {
		this->isiPeta[index] = element;
	}
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
				index++;
			}
		}
		
	} else {
		cout << "File map tidak dapat dibuka" << endl;
	}
}

void Peta::PrintPeta(){
	for(int i = 0; i < SIZE_ROW; i++){
		for(int j =0; j < SIZE_COL; j++){
			cout << GetElementPeta(i,j) << " ";
		}
		cout << endl;
	}
}

//kalo engimonnya sudah berhasil dijinakkan hapus dari DaftarEngimon
void Peta::DeleteEngimon(){
	//SetElementPeta
	//delete element vector engimon
// 	myvector= {1, 2, 3, 4, 5}, iterator= 2
//          myvector.erase(iterator);
	// for (auto i = DaftarEngimon.begin(); i != DaftarEngimon.end(); ++i)
	//std::vector<int> a={1,2,3};
   //a.erase(std::find(a.begin(),a.end(),2));
}

void Peta::SelectNama(char Engimon, string *nama, int *cumexp, int *health){
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
		*cumexp = 1200;
		*health = 300;
	} else if(Engimon == 'F'){
		random = fire2[rand() % 3]; 
		*cumexp = 1200;
		*health = 400;
	} else if(Engimon == 'g'){
		random = ground1[rand() % 3];
		*cumexp = 1300;
		*health = 300;
	} else if(Engimon == 'G'){
		random = ground2[rand() % 3];
		*cumexp = 1300;
		*health = 400;
	} else if(Engimon == 'e'){
		random = electric1[rand() % 3];
		*cumexp = 1400;
		*health = 300;
	} else if(Engimon == 'E'){
		random = electric2[rand() % 3]; 
		*cumexp = 1400;
		*health = 400;
	} else if(Engimon == 'w'){
		random = water1[rand() % 3];
		*cumexp = 1300;
		*health = 450;
	} else if(Engimon == 'W'){
		random = water2[rand() % 3];
		*cumexp = 1300;
		*health = 500;
	} else if(Engimon == 'i'){
		random = ice1[rand() % 3];
		*cumexp = 1200;
		*health = 500;
	} else if(Engimon == 'I'){
		random = ice2[rand() % 3];
		*cumexp = 1200;
		*health = 550;
	}
	*nama = random;
	 
}

void Peta::SpawnEngimon(int BanyakSpawn){
	int posisi, level;
	//int BanyakSpawn = 10;
	posisi = rand() % (SIZE_ROW*SIZE_COL);
	level = rand(); //mod dengan max level dari engimon
	char grass[] = "fFgGeE";
	char sea[] = "wiWI";
	char engimonTerpilih;
	string namaEngimon;
	int cumexp, health;
	for(int i = 0; i < BanyakSpawn; i++){
		while(this->isiPeta[posisi] != '-' && this->isiPeta[posisi] != 'o'){
			posisi = rand() % (SIZE_ROW*SIZE_COL);
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
			SelectNama(engimonTerpilih,&namaEngimon, &cumexp, &health);
			cout << namaEngimon << endl;
			//create obj engimon
			// nama, parent=NULL, skill, element, level, exp, cumexp, status = 1, health
			// DaftarEngimon.push_back(engimon);
			//PosisiEngimon.push_back(posisi) 
			cout << engimonTerpilih << endl;
			cout << posisi << endl;
			//create engimon
			//masukin ke daftar engimon
		} else if(this->isiPeta[posisi] == 'o'){
			engimonTerpilih = sea[rand() % 4];
			//set di peta
			SetElementPeta(posisi, engimonTerpilih);
			SelectNama(engimonTerpilih,&namaEngimon, &cumexp, &health);
			cout << namaEngimon << endl;
			// DaftarEngimon.push_back(i);
			cout << engimonTerpilih << endl;
			cout << posisi << endl;
			//create engimon
			//masukin ke daftar engimon
		}
		//dtor engimon
	}
}

void Peta::GerakinEngimon(){
	//iterasi tiap element pada pada daftar engimon
	//untuk geraknya di random
	// for (auto i = DaftarEngimon.begin(); i != DaftarEngimon.end(); ++i){
	// 	cout << *i << " "; 
	int posisi = rand() % (SIZE_ROW*SIZE_COL);
	// } 
	//if else jenis engimon yang sedang dijalankan
	//SetElementPeta posisi engimon sekarang ganti jadi posisi sebelumnya
	
	//SetElementPeta //ganti jadi posisi yang baru
}

int main(){
	Peta P(14, 14);
	P.BacaFile();
	//P.PrintPeta();
	//P.SpawnEngimon(10);
	//P.PrintPeta();
	P.SpawnEngimon(5);
	P.PrintPeta();
	
	return 0;
}

/*
// Constructor for Given Matrix
Peta::Peta(const char * fileName){
    ifstream file_A(fileName); // input file stream to open the file A.txt

    // Task 1
    // Keeps track of the Column and row sizes
    int colSize = 0;
    int rowSize = 0;
    
    // read it as a vector
    string line_A;
    int idx = 0;
    double element_A;
    double *vector_A = nullptr;
    
    if (file_A.is_open() && file_A.good())
    {
        // cout << "File A.txt is open. \n";
        while (getline(file_A, line_A))
        {
            rowSize += 1;
            stringstream stream_A(line_A);
            colSize = 0;
            while (1)
            {
                stream_A >> element_A;
                if (!stream_A)
                    break;
                colSize += 1;
                double *tempArr = new double[idx + 1];
                copy(vector_A, vector_A + idx, tempArr);
                tempArr[idx] = element_A;
                vector_A = tempArr;
                idx += 1;
            }
        }
    }
    else
    {
        cout << " WTF! failed to open. \n";
    }
    
    int j;
    idx = 0;
    m_matrix.resize(rowSize);
    for (unsigned i = 0; i < m_matrix.size(); i++) {
        m_matrix[i].resize(colSize);
    }
    for (int i = 0; i < rowSize; i++)
    {
        for (j = 0; j < colSize; j++)
        {
            this->m_matrix[i][j] = vector_A[idx];
            idx++;
        }
    }
    m_colSize = colSize;
    m_rowSize = rowSize;
    delete [] vector_A; // Tying up loose ends
    

} */
