#include "Skill.h"

ostream& operator<<(ostream& os, const Element& elm){
    if (elm==fire) os << "F";
    else if(elm==water) os << "W";
    else if(elm==electric) os << "E";
    else if(elm==ground) os << "G";
    else if(elm==ice) os << "I";

    return os;
}

// ctor
Skill::Skill(){
    this->name = "";
    this->basePower = 0;
    this->masteryLevel = 0;
    this->element = vector<Element>();
}

Skill::Skill(string _name, int _basePower, int _masteryLevel, vector<Element> elm)
{
        this->name = _name;
        this->basePower = _basePower;
        this->masteryLevel = _masteryLevel;

        this->element = elm;
}
// dtor
Skill::~Skill(){}

// operator overload
bool operator==(const Skill& left, const Skill& right){
    return left.name == right.name &&
        left.basePower == right.basePower &&
        left.masteryLevel == right.masteryLevel &&
        left.element == right.element;
}

Skill& Skill::operator=(const Skill& otherSkill){
    this->name = otherSkill.name;
    this->basePower = otherSkill.basePower;
    this->masteryLevel = otherSkill.masteryLevel;
    this->element = otherSkill.element;

    return *this;
}

ostream& operator<<(ostream& os, const Skill& skill){
    os << "===============================" << endl;
    os << " | " << skill.name << endl;
    os << " | Base power    : " << skill.basePower << endl;
    os << " | Mastery level : " << skill.masteryLevel << endl;
    os << " | Element       : ";

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

bool Skill::hasElement(Element elm)
{
    for (auto i = element.begin(); i != element.end(); ++i) { if (*i == elm) return true; }
    return false;
}
/* Class KatalogSkill */

SkillsFactory::SkillsFactory(){
    skills = vector<Skill> ();

    vector<Element> fireV = {fire};
    vector<Element> waterV = {water};
    vector<Element> iceV = {ice};
    vector<Element> electricV = {electric};
    vector<Element> groundV = {ground};

    vector<Element> fire_electricV = {fire, electric};
    vector<Element> water_iceV = {water, ice};
    vector<Element> water_groundV = {water, ground};
    vector<Element> ground_iceV = {ground, ice};
    vector<Element> electric_ice_waterV = {water, electric, ice};
    vector<Element> allElement = {fire, water, electric, ground, ice};

    Skill s0("One Punch", 9999, 1, allElement);

    Skill s1("Inferno", 900, 1, {fire});
    Skill s2("Ragnarok Trisagon", 950, 1, fireV);
    Skill s3("Maralagidyne", 970, 1, fireV);
    Skill s4("Titanomachia", 1112, 1, fire_electricV);

    Skill s5("Aquary Tide", 895, 1, waterV);
    Skill s6("Water Blast", 980, 1, waterV);
    Skill s7("Blackwater Taint", 1010, 1, waterV);
    Skill s8("Depthsurge", 1100, 1, water_groundV);

    Skill s9("Earthbolt", 910, 1, groundV);
    Skill s10("Clearstone", 960, 1, groundV);
    Skill s11("Phantom Plow", 1000, 1, groundV);
    Skill s12("Rain of Spines", 1120, 1, ground_iceV);

    Skill s13("Thunderswarm", 920, 1, electricV);
    Skill s14("Stormrage", 980, 1, electricV);
    Skill s15("Presper Moonbow", 999, 1, electricV);
    Skill s16("Mystic Lash", 1200, 1, electric_ice_waterV);

    Skill s17("Arctic Haze", 920, 1, iceV);
    Skill s18("Glaze Lock", 980, 1, iceV);
    Skill s19("Heat Leech", 1100, 1, iceV);
    Skill s20("Blizzard", 1150, 1, iceV);

    Skill s21("Shatterstone", 1190, 1, water_groundV);

    skills.push_back(s0);
    skills.push_back(s1);
    skills.push_back(s2);
    skills.push_back(s3);
    skills.push_back(s4);
    skills.push_back(s5);
    skills.push_back(s6);
    skills.push_back(s7);
    skills.push_back(s8);
    skills.push_back(s9);
    skills.push_back(s10);
    skills.push_back(s11);
    skills.push_back(s12);
    skills.push_back(s13);
    skills.push_back(s14);
    skills.push_back(s15);
    skills.push_back(s16);
    skills.push_back(s17);
    skills.push_back(s18);
    skills.push_back(s19);
    skills.push_back(s20);
    skills.push_back(s21);
}

SkillsFactory::~SkillsFactory(){}

Skill& SkillsFactory::operator[](int i){
    return skills[i];
}

void SkillsFactory::printKatalogSkill(){
    for (auto i = skills.begin(); i != skills.end(); ++i){ cout << *i << endl; } 
}
vector<Skill> SkillsFactory::getSkills() {
    return skills;
}