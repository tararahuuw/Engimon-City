#ifndef ENGIMON_HPP
#define ENGIMON_HPP

#include <iostream>
#include <string>
#include <list>
#include "Skill.h"

enum Element {fire, water, electric, ground, ice};

class Engimon{
    private:
        string name;
        list<string> parent; // nama parent ada 2
        vector<Skill> skills; // skill maksimal 4
    	vector<Element> elements; //perlu dijadikan derived class atau ngga
        int level;
        int EXP;
        int cumulativeEXP;
        int status; // indikator mati atau ngga | ini apa gak perlu dicek health == 0 atau cumulativeEXP meleb
        int health;

    public:
        // Engimon(string _name, Skill _skill, vector<Element> _elements, int _level, int _EXP, int _cumulativeEXP, int _status, int _health);
        
        // // kalo parameternya mau pakai vector
        // Engimon(string _name, list<string> _parent, Skill _skill, vector<Element> _elements, int _level, int _EXP, int _cumulativeEXP, int _status, int _health);
        // ctor
        Engimon();

        // user defined
        // 1 elemen
        Engimon(string _name, list<string> _parent, Skill _skills, Element elm, int _level, int _EXP, int _cumulativeEXP, int _status, int _health);
        // 2 elemen
        Engimon(string _name, list<string> _parent, Skill _skills, Element elm1, Element elm2, int _level, int _EXP, int _cumulativeEXP, int _status, int _health);
        
        // dtor
        ~Engimon();
        
        //operator overload
        bool operator==(const Engimon& otherEngimon);
        Engimon& operator=(const Engimon& otherEngimon);
        friend ostream& operator<<(ostream& os, const Engimon& engimon);
        friend ostream& operator<<(ostream& os, const Element& element);

        // getter
        int getLevel() const;
        int getEXP() const;
        int getCumulativeEXP() const;
        list<string> getParent() const;
        list<Skill> getSkills() const;
		vector<Element> getElement() const;
        int getStatus() const;
        int getHealth() const;
        
        // setter
        void setName(string _name);
        void setParent(string _parent1, string _parent2);
        void setSkills(vector<Skill> skills);
        void setElements(vector<Element> elements);
        void setLevel(int _level);
        void setEXP(int _EXP);
        void setCumulativeEXP(int _cumulativeEXP);
        void setStatus(int _status);
        void setHealth(int _health);
				
        // fungsi lain
        void upLevel(); // menaikan sebesar 1 level
        void downLevel(int decr); // menurunkan sebesar decr level
        void addEXP(int exp); // menambah exp
        // void printInfo(); pakai overload
        void addSkills(Skill skill); //menambahkan skill engimon
        bool checkNumOfElements() const; // kalau 1 itu false, kalau 2 true
        
        // print nama elemen
        // static void printElement(Element elm); pakai overload
};

// buat daftar engimon liar(?)
class KatalogEngimon{
    private:
        vector<Engimon> katalogEngimon;
    public:
        KatalogEngimon();
        // void initKatalogEngimon();
        static void printKatalogEngimon();
};


#endif