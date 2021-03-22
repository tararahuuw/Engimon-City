#ifndef ENGIMON_H
#define ENGIMON_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <map>
#include "Skill.h"
#include "Species.h"

using namespace std;

class Engimon{
    private:
        Species* species;
        string name;
        pair<pair<string, string>, pair<string, string>> parent;
        int level; 
        int EXP; 
        int cumulativeEXP;
        bool status;
        bool wild;
        const int maxCumulative = 1500;

    public:
        // default ctor
        Engimon();

        // untuk engimon dengan 1 elemen
        Engimon(Species* _species, string _name, 
        pair<pair<string, string>, pair<string, string>> _parent, int _level, int _EXP, int _cumulativeEXP, bool _status, bool wild);
        
        // dtor
        ~Engimon();
        
        //operator overload
        bool operator==(const Engimon& engi);
        Engimon& operator=(const Engimon& engi);
        friend ostream& operator<<(ostream& os, const Engimon& engimon);

        // getter
        int getLevel() const;
        int getEXP() const;
        int getCumulativeEXP() const;
        pair<pair<string, string>, pair<string, string>> getParent() const;
        Species* getSpecies() const;
        // vector<Skill> getSkills() const;
		// vector<Element> getElement() const;
        // bool getStatus() const;
        
        // setter
        // void setName(string _name);
        // void setParent(pair<int, string> _parent1, pair<int, string> _parent2);
        // void setSkills(vector<Skill> _skills);
        // void setElements(vector<Element> _elements);
        // void setLevel(int _level);
        // void setEXP(int _EXP);
        // void setCumulativeEXP(int _cumulativeEXP);
        // void setStatus(bool _status);
        // void setHealth(int _health);
				
        // fungsi lain
        void upLevel(int incr); // Menaikan level sebesar naik
        void downLevel(int decr); // Menurunkan level sebesar
        void addEXP(int exp); // Menambahkan EXP sebesar exp sekaligus mengecek :
        // 1. Apabila EXP > 100 maka naik level dan reset EXP
        // 2. Apabila cumulativeEXP > maxCumulativeEXP maka status mati

        void addSkills(Skill skill); // Menambahkan skill engimon dengan pengecekan supaya tidak ada skill yang sama
        void dropSkills(Skill skill); // Menghapus skill engimon dengan asumsi Skill skill dimiliki engimon 
        bool checkNumOfElements() const; // kalau 1 itu false, kalau 2 true
};

// Class untuk inisiasi daftar species engimon
// Anggota class hanya diinisiasi diawal, selama program berjalan tidak diubah-ubah
class KatalogEngimon{
    private:
    public:
        KatalogEngimon();
        // void initKatalogEngimon();
        Engimon& operator[](int i);
        void printKatalogEngimon(); //for testing purpose
        static map<int, Engimon> katalogEngimon;
};

#endif