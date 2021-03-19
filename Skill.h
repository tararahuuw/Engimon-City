#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

enum Element {fire, water, electric, ground, ice};
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
    Skill(string _name, int _basePower, int _masteryLevel, Element elm); // 1 elemen
    Skill(string _name, int _basePower, int _masteryLevel, Element elm1, Element elm2); // 2 elemen
    
    //dtor
    ~Skill();

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
    void setBasePower(int _basePower);
    void setMasteryLevel(int _masteryLevel);
    void setElement(Element elm);
    void setElement(Element elm1, Element elm2);
    
    // fungsi lain
    // void printSkillInfo();
    void incrMasteryLevel();
};

// Berisi daftar skill yang ada
class KatalogSkill {
    private:
        vector<Skill> katalogSkill;
        // vector<Skill> fireSkills;
        // vector<Skill> waterSkills;
        // vector<Skill> electricSkills;
        // vector<Skill> groundSkills;
        // vector<Skill> iceSkills;
        // vector<Skill> fire_electricSkills;
        // vector<Skill> water_iceSkills;
        // vector<Skill> water_groundSkills;
    public:
        KatalogSkill();
        ~KatalogSkill();
        // void addSkill();
        // void addSkill();
        // operator overload
        Skill& operator[](int i);
        // vector<Skill>& operator[](string elm){
        //     if (elm == "fire") return fireSkills;
        //     else if(elm == "water") return waterSkills;
        //     else if(elm == "electric") return electricSkills;
        //     else if(elm == "ground") return groundSkills;
        //     else if(elm == "ice") return iceSkills;
        //     else if(elm == "fire_electric") return fire_electricSkills;
        //     else if(elm == )
        // }
        void printtKatalogSkill(); //for testing purpose
};

#endif // !