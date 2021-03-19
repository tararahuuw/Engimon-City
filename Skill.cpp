#include "Skill.h"

ostream& operator<<(ostream& os, const Element& elm){
    if (elm==fire) os << "Fire";
    else if(elm==water) os << "Water";
    else if(elm==electric) os << "Electric";
    else if(elm==ground) os << "Ground";
    else if(elm==ice) os << "Ice";

    return os;
}
// ctor
Skill::Skill(){
    this->name = "";
    this->basePower = 0;
    this->masteryLevel = 0;
    this->element = vector<Element>();
}

Skill::Skill(string _name, int _basePower, int _masteryLevel, Element elm){
        this->name = _name;
        this->basePower = _basePower;
        this->masteryLevel = _masteryLevel;

        this->element = vector<Element>();
        this->element.push_back(elm);
}
Skill::Skill(string _name, int _basePower, int _masteryLevel, Element elm1, Element elm2) : 
       Skill(_name, _basePower, _masteryLevel, elm1)
{
    this->element.push_back(elm2);
}

// dtor
Skill::~Skill(){}

// operator overload
bool Skill::operator==(const Skill& otherSkill){
    return this->name == otherSkill.name &&
        this->basePower == otherSkill.basePower &&
        this->masteryLevel == otherSkill.masteryLevel &&
        this->element == otherSkill.element;
}

ostream& operator<<(ostream& os, const Skill& skill){
    os << "===============================" << endl;
    os << "| " << skill.name << endl;
    os << "| Base power    : " << skill.basePower << endl;
    os << "| Mastery level : " << skill.masteryLevel << endl;
    os << "| Element       : ";

    for(int i = 0; i<skill.element.size(); i++){
        if (i != 0){
            os << "/";
        }
        os << skill.element[i];
    }
    
    return os;
}
// getter
string Skill::getName() const{
    return this->name;
}

int Skill::getBasePower() const{
    return this->basePower;
}

int Skill::getMasteryLevel() const{
    return this->masteryLevel;
}

vector<Element> Skill::getElement() const{
    return this->element;
}

// setter
void Skill::setName(string _name){
    this->name = _name;
}
void Skill::setBasePower(int _basePower){
    this->basePower = _basePower;
}
void Skill::setMasteryLevel(int _masteryLevel){
    this->masteryLevel = _masteryLevel;
}
void Skill::setElement(Element elm){
    this->element.clear();
    this->element.push_back(elm);
}
void Skill::setElement(Element elm1, Element elm2){
    this->element.clear();
    this->element.push_back(elm1);
    this->element.push_back(elm2);
}

void Skill::incrMasteryLevel(){
    this->masteryLevel++;
}

/* Class KatalogSkill */

KatalogSkill::KatalogSkill(){
    katalogSkill = vector<Skill> ();

    Skill s1("Skill1", 900, 1, fire);
    Skill s2("Skill2", 850, 1, water);
    Skill s3("Skill3", 920, 1, electric);
    Skill s4("Skill4", 940, 1, ground);
    Skill s5("Skill5", 960, 1, ice);
    Skill s6("Skill6", 1020, 1, fire, electric);
    Skill s7("Skill7", 1050, 1, water, ice);
    Skill s8("Skill8", 1030, 1, water, ground);
    Skill s9("Skill9", 1000, 1, fire);
    Skill s10("Skill10", 1012, 1, water);

    katalogSkill.push_back(s1);
    katalogSkill.push_back(s2);
    katalogSkill.push_back(s3);
    katalogSkill.push_back(s4);
    katalogSkill.push_back(s5);
    katalogSkill.push_back(s6);
    katalogSkill.push_back(s7);
    katalogSkill.push_back(s8);
    katalogSkill.push_back(s9);
    katalogSkill.push_back(s10);
}

KatalogSkill::~KatalogSkill(){}

Skill& KatalogSkill::operator[](int i){
    return katalogSkill[i];
}

void KatalogSkill::printtKatalogSkill(){
    for (auto i = katalogSkill.begin(); i != katalogSkill.end(); ++i){
        cout << *i << endl;
    } 
}