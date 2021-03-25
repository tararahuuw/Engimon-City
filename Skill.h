#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
// #include "CustomException.h"

using namespace std;

enum Element {none = -1, fire = 0, water, electric, ground, ice};
ostream& operator<<(ostream& os, const Element& elm); // untuk print element

class Skill{
private:
    string name;
    int basePower;
    int masteryLevel;
    vector<Element> element;
    
public:
	//ctor
    Skill();
    //user defined
    Skill(string _name, int _basePower, int _masteryLevel, vector<Element> elm); // 1 elemen
    
    //dtor
    ~Skill();

    //operator overload
    friend bool operator==(const Skill& left, const Skill& right);
    Skill& operator=(const Skill& otherSkill);
    friend ostream& operator<<(ostream& os, const Skill& skill);

    // getter, seperlunya
    string getName() const;
    int getBasePower() const;
    int getMasteryLevel() const;
    vector<Element> getElement() const;
    
    // setter, seperlunya
    void setName(string _name);
    void setBasePower(int _basePower);
    void setMasteryLevel(int _masteryLevel);
    void setElement(Element elm);
    void setElement(Element elm1, Element elm2);
    
    // fungsi lain
    void incrMasteryLevel();
    bool hasElement(Element elm);
};

// Berisi daftar skill yang ada
class SkillsFactory {
    private:
        vector<Skill> skills;
    public:
        SkillsFactory();
        ~SkillsFactory();
        Skill& operator[](int i);
        void printKatalogSkill();
        vector<Skill> getSkills();
};

#endif // !