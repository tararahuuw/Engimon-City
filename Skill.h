#ifndef SKILL_H
#define SKILL_H

#include <vector>
#include <iostream>
#include <string>
#include "Engimon.h"

using namespace std;

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
    Skill(string _name, int _basePower, int _masteryLevel, Element elm); // 1 elemen
    Skill(string _name, int _basePower, int _masteryLevel, Element elm1, Element elm2); // 2 elemen
    
    //dtor
    ~Skill(){}

    //operator overload
    bool operator==(const Skill& otherSkill);
    friend ostream& operator<<(ostream& os, const Skill& skill);

    // getter
    string getName() const;
    int getBasePower() const;
    int getMasteryLevel() const;
    vector<Element> getElement() const;
    
    // setter
    void setName(string _name);
    void setBasePower(string _basePower);
    void setMasteryLevel(int _masteryLevel);
    void setElement(Element elm);
    void setElement(Element elm1, Element elm2);
    
    // fungsi lain
    // void printSkillInfo();
    void incrMasteryLevel();
};

// Daftar skill yang ada
class KatalogSkill {
    private:
        vector<Skill> katalogSkill;
    public:
        KatalogSkill();
};

#endif // !