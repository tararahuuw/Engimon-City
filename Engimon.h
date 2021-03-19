#ifndef ENGIMON_H
#define ENGIMON_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <map>
#include "Skill.h"

using namespace std;

class Engimon{
    private:
        string species; // Nama spesies diambil dari katalogEngimon
        string name; // Nama individu engimon
        list<pair<int, string>> parent; // Berisi 2 nama parent, dinyatakan dalam pair. int menunjuk ke species key pada katalogEngimon dan string adalah nama parent
        vector<Skill> skills; // Skill engimon maksimal 4
    	vector<Element> elements; // Element bisa 1 atau 2
        int level; 
        int EXP; 
        int cumulativeEXP;
        bool status; // True apabila masih hidup, false bila sudah mati
        int health;
        const int maxCumulative = 1500; // Cumulative EXP maksimal
        const int maxSkill = 4; // Jumlah skill maksimal

    public:
        // Engimon(string _name, Skill _skill, vector<Element> _elements, int _level, int _EXP, int _cumulativeEXP, int _status, int _health);
        
        // // kalo parameternya mau pakai vector
        // Engimon(string _name, list<string> _parent, Skill _skill, vector<Element> _elements, int _level, int _EXP, int _cumulativeEXP, int _status, int _health);
        // default ctor
        Engimon();

        // user defined
        // untuk engimon dengan 1 elemen
        Engimon(string _species, string _name, list<pair<int, string>> _parent, Skill _skills, Element elm, int _level, int _EXP, int _cumulativeEXP, bool _status, int _health);
        
        // untuk engimon dengan 2 elemen
        Engimon(string _species, string _name, list<pair<int, string>> _parent, Skill _skills, Element elm1, Element elm2, int _level, int _EXP, int _cumulativeEXP, bool _status, int _health);
        
        // dtor
        ~Engimon();
        
        //operator overload
        bool operator==(const Engimon& otherEngimon);
        Engimon& operator=(const Engimon& otherEngimon);
        friend ostream& operator<<(ostream& os, const Engimon& engimon);

        // getter
        int getLevel() const;
        int getEXP() const;
        int getCumulativeEXP() const;
        list<pair<int, string>> getParent() const;
        vector<Skill> getSkills() const;
		vector<Element> getElement() const;
        bool getStatus() const;
        int getHealth() const;
        
        // setter
        void setName(string _name);
        void setParent(pair<int, string> _parent1, pair<int, string> _parent2);
        void setSkills(vector<Skill> _skills);
        void setElements(vector<Element> _elements);
        void setLevel(int _level);
        void setEXP(int _EXP);
        void setCumulativeEXP(int _cumulativeEXP);
        void setStatus(bool _status);
        void setHealth(int _health);
				
        // fungsi lain
        void upLevel(int naik); // Menaikan level sebesar naik
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