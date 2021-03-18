#ifndef ENGIMON_HPP
#define ENGIMON_HPP

#include <iostream>
#include <string>
#include <list>
#include "Skill.hpp"

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
        Engimon();
        // user defined ctor
        Engimon(string _name, list<string> _parent, vector<string> _skills, vector<Element> _elements, int _level, int _EXP, int _cumulativeEXP, int _status, int _health);
        // dtor
        ~Engimon();
        // cctor
        //operator overload
        bool operator==(const Engimon& otherEngimon);
        Engimon& operator=(const Engimon& otherEngimon);

        // getter
        int getLevel() const;
        int getEXP() const;
        int getCumulativeEXP() const;
        list<string> getParent() const;
        list<Skill> getSkills() const;
		vector<Element> getElement() const;
        int status() const;
        int getHealth() const;
        
        // setter
        void setName(string _name);
        void setParent(string _parent1, string _parent2);
        void setSkills(vector<Skills> skills);
        void setElements(vector<Element> elements);
        void setLevel(int _level);
        void setEXP(int _EXP);
        void setCumulativeEXP(int _cumulativeEXP);
        void setStatus(int _status);
        void setHealth(int _health);
				
        // fungsi lain
        void upLevel();
        void downLevel(int decr);
        void addEXP();
        void printInfo();
        void addSkills();
        bool checkNumOfElements() const; // kalau 1 itu false, kalau 2 true
        
        // print nama elemen
        static void printElement(Element elm);
};

class KatalogEngimon{
    private:
        vector<Engimon> katalogEngimon;
    public:
        KatalogEngimon();
        // void initKatalogEngimon();
        static void printKatalogEngimon();
};


#endif