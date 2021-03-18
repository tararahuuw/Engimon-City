#include "Skill.h"

Skill::Skill(){
    this->name = "Nama";
    this->basePower = 0;
    this->masteryLevel = 0;
    this->element = vector<Element>();
}

Skill::Skill(string _name, int _basePower, int _masteryLevel, Element elm){
        this->name = _name;
        this->basePower = _basePower;
        this->masteryLevel = _masteryLevel;

        this->element = vector<Element>(1);
        this->element[0] = elm;
    }
Skill::Skill(string _name, int _basePower, int _masteryLevel, Element elm1, Element elm2){
        this->name = _name;
        this->basePower = _basePower;
        this->masteryLevel = _masteryLevel;

        this->element = vector<Element>(2);
        this->element[0] = elm1;
        this->element[1] = elm2;
    }

// getter
string Skill::getName() const{
    return this->name;
}
    int getBasePower() const;
    int getMasteryLevel() const;
    vector<Element> getElement() const;

// void Skill::printSkillInfo(){
//         cout << "Nama skill : " << this->name << endl;
//         cout << "Base power : " << this->basePower << endl;
//         cout << "Mastery level : " << this->masteryLevel << endl;
//         cout << "Associated elemenet : " << endl;
//         for (int i = 0; i<element.capacity(); i++){
//             printElement(element[i]);
//         }
//         cout << endl;
//     }
Skill::~Skill(){}

// static void printElement(Element elm){
//         if (elm==0) cout << "| Fire |";
//         else if (elm==1) cout << "| Water |";
//         else if (elm==2) cout << "| Electric |";
//         else if (elm==3) cout << "| Ground |";
//         else if (elm==4) cout << "| Ice |";
// }