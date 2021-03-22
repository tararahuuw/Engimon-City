#ifndef SPECIES_H
#define SPECIES_H 

#include <iostream>
#include <ostream>
#include <string>
#include <map>
#include <utility>
#include "Skill.h"

using namespace std;

class Species{
    protected:
        string name;
    public:
        Species();
        Species(string _name);
        Species(const Species& sp);

        ~Species();

        Species& operator=(const Species& sp);
        bool operator==(const Species& sp);
        // friend ostream& operator<<(const ostream& os, const Species& sp);
        
        string getName() const;

        virtual bool isSingleElement() const = 0;
        virtual vector<Skill> getSkill() const = 0;
        virtual Element* getElement() const = 0;
        virtual Element getElement(int idx) const = 0;
        virtual bool hasElement(Element elm) const = 0;

        virtual void addSkill(Skill _skill)=0;
        virtual void dropSkill(Skill _skill)=0;
};

class SingleType : public Species{
    private:
        Element* elm;
        vector<Skill> skills;
        const int nElm = 1;
        const int maxSkill = 4; 

    public:
        SingleType();
        SingleType(string _name, Element _elm, Skill _baseSkill);
        SingleType(string _name, Element _elm, vector<Skill> _skills);
        SingleType(Element _elm, Skill _baseSkill);
        SingleType(const SingleType& sp);

        ~SingleType();

        SingleType& operator=(const SingleType& sp);
        bool operator==(const SingleType& sp);
        friend ostream& operator<<(ostream& os, const SingleType& sp);

        Element* getElement() const;
        Element getElement(int idx) const;

        void addSkill(Skill _skill);
        void dropSkill(Skill _skill);
        
        Element getElement(int idx);
        Element* getElement();
        
        int getNumElement() const;
        bool isSingleElement() const;
        bool hasElement(Element elm) const;
        vector<Skill> getSkill() const;
};

class DoubleType : public Species{
    private:
        Element* elm;
        vector<Skill> skills;
        const int nElm = 2;
        const int maxSkill = 4;
    public:
        DoubleType();
        DoubleType(string _name, Element* _elm, Skill _baseSkill);
        DoubleType(Element* _elm, Skill _baseSkill);
        DoubleType(string _name, Element* _elm, vector<Skill> _skills);
        DoubleType(const DoubleType& sp);

        ~DoubleType();

        DoubleType& operator=(const DoubleType& sp);
        bool operator==(const DoubleType& sp);
        friend ostream& operator<<(ostream& os, const DoubleType& sp);

        Element* getElement() const;
        Element getElement(int idx) const;

        void addSkill(Skill _skill);
        void dropSkill(Skill _skill);
        
        Element getElement(int idx);
        Element* getElement();
        
        int getNumElement() const;
        bool isSingleElement() const;
        bool hasElement(Element elm) const;
        vector<Skill> getSkill() const;
};

class SpeciesCollection{
    private:
        // Aturan penomoran
        // 0 mod 8 : fire
        // 1 mod 8 : water
        // 2 mod 8 : electric
        // 3 mod 8 : ground
        // 4 mod 8 : ice
        // 5 mod 8 : fire electric
        // 6 mod 8 : water ground
        // 7 mod 8 : water ice
        map<int, Species*> collection; // string nama species
    public:
        SpeciesCollection();
        void initSpecies(); 
};

#endif