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
        // ctor
        Species();
        // user defines ctor
        Species(string _name);
        // cctor in case perlu
        Species(const Species& sp);
        // dtor
        ~Species();
        // operator overload
        // untuk ostream belum fix, masih jelek
        Species& operator=(const Species& sp); // kayaknya gaperlu tapi gatau deh
        bool operator==(const Species& sp); // harusnya ga perlu tapi jaga2 aja
        friend ostream& operator<<(ostream& os, const Species& sp);
        virtual ostream& print(ostream& os) const;
        
        // getter
        string getName() const;
        
        // pure virtual
        // true jika single element
        virtual bool isSingleElement() const = 0;
        // mengembalikan element dalam bentuk array
        // single element = 1, double element = 2
        virtual Element* getElement() const = 0;
        // mengembalikan element pada indeks ke idx, in case ada yang butuh
        // single element terima idx = 0, double element terima input idx = 0 dan idx = 1 
        // jadi kalau mau akses element lebih baik di cek dulu lewat isSingleElement()
        virtual Element getElement(int idx) const = 0; 
        // true apabila species punya element _elm
        virtual bool hasElement(Element elm) const = 0;
        // mengembalikan skill bawaan species
        virtual Skill getBaseSkill() const = 0;
};

class SingleType : public Species{
    private:
        Element* elm; // masih bingung mau tipe apa karena ternyata fungsi dari derived class nda bisa dipanggil lewat pointer base class kecuali ada pure virtual jadi getter nya harus punya return type yang sama
        Skill baseSkill;
        const int nElm = 1;

    public:
        // ctor
        SingleType();
        // user define
        SingleType(string _name, Element _elm, Skill _baseSkill); // argumen 1 skill saja karena species ini di define sekali saja di awal program
        // SingleType(Element _elm, Skill _baseSkill); // ini kayaknya ga butuh
        // cctor in case butuh
        SingleType(const SingleType& sp);
        // dtor
        ~SingleType();
        // operator overload
        SingleType& operator=(const SingleType& sp);
        bool operator==(const SingleType& sp);
        ostream& print(ostream& os) const; // masih jelek

        // getter
        Element* getElement() const;
        Element getElement(int idx) const;
        int getNumElement() const;
        Skill getBaseSkill() const;

        bool isSingleElement() const;
        bool hasElement(Element elm) const;
        // vector<Skill> getSkill() const;
};

class DoubleType : public Species{
    private:
        Element* elm;
        Skill baseSkill;
        const int nElm = 2;

    public:
        // ctor
        DoubleType();
        // user defined ctor
        DoubleType(string _name, Element* _elm, Skill _baseSkill);
        // DoubleType(Element* _elm, Skill _baseSkill); // ini kayaknya ga butuh
        // cctor
        DoubleType(const DoubleType& sp);   
        // dtor
        ~DoubleType();
        // operator overload
        DoubleType& operator=(const DoubleType& sp);
        bool operator==(const DoubleType& sp);
        ostream& print(ostream& os) const; // masih jelek
        // getter
        Element* getElement() const;
        Element getElement(int idx) const;
        int getNumElement() const;
        Skill getBaseSkill() const;

        bool isSingleElement() const;
        bool hasElement(Element elm) const;
};

// Buat init species
class SpeciesFactory{
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
        friend ostream& operator<<(ostream&os, const pair<int, Species*>& sp);
        SpeciesFactory();
        void initSpecies(); // perlu dijadiin 1 sama ctor atau ngga? kayanya perlu, kalau nanti dijadiin bilang ke grup ya
        Species*& operator[](int idx); // mengembalikan pointer to species di indeks ke idx
        void printAllSpecies();
};

#endif
