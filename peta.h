#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <map>
#include "Engimon2.h"
using namespace std;

#ifndef PETA_HPP
#define PETA_HPP
// #define SIZE_ROW 14
// #define SIZE_COL 14
#define MIN_LEVEL 5
#define MAX_LEVEL 10
#define MAX_SPAWN 20

class Peta {
    private :
        int baris;
        int kolom;
        int nElmt;
        char *isiPeta;
        char *PetaTetap;
        vector<pair<int, Engimon> > DaftarEngimon; //vector of engimon buat nyimpan engimon apa saja yang ada pada peta
        //^terdiri dari int yang merupakan posisi dari engimon liar dalam peta dan Engimon liar

    public :
        //default ctor
        //ukaran default 14x14
        Peta();

    	//ctor user defined
        Peta(int b, int k);
        
        //cctor
        Peta(const Peta& P);
        
        //dtor
        ~Peta();
        
        //operator assigment
        Peta& operator=(const Peta& P);
        
        //Get&Set
        int GetBaris();
        int GetKolom();
        int GetBarisObjek(int posisi);
        int GetKolomObjek(int posisi);
        pair<int, Engimon> GetDaftarEngimon(int index); //index dari vector daftar engimon
        char GetElementPeta(int b, int k);
        char GetElementPeta(int posisi);
        char GetElementPetaTetap(int b, int k);
        char GetElementPetaTetap(int posisi);
        void SetElementPeta(int b, int k, char element);
        void SetElementPeta(int index, char element);
        Engimon GetEngimonLiar(int x, int y); //untuk dapetin engimon pada posisi (x,y)
        pair<int, Engimon> GetEngimonforDelete(int x, int y);
        
        //Baca file dan isi element pada peta sesuai dengan isi file txt
        void BacaFile();
        
        //Print isi Peta
        void PrintPeta();
        void PrintDaftarEngimon();
        
        //Untuk masukin engimon yang telah dibuat ke daftarEngimon
        void AddEngimon(pair<int, Engimon> e);
        //untuk menghapus engimon liar yg sudah ditangkap
        void DeleteEngimon1(pair<int, Engimon> e); 
        void DeleteEngimon2(int x, int y); //(x,y) adalah posisi dari engimon

        int selectlevel(char engimonTerpilih);
        void CreateEngimon(char e, int level, Engimon *engi);
        void SpawnEngimon(int BanyakSpawn);
        void TukarPosisi(int posisi, int posisisekarang);
        void GerakinSemuaEngimon();
        
        //minta getter baris kolom dan pengecekan indeks map valid dong, terus kalau gak salah banyak
        //engimon liar bisa didapetin pake vector.size()
};

#endif
