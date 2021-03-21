#include "Engimon.h"
#include "Skill.h"
// wild engimon
// Engimon::Engimon(string _name, Skill _skill, vector<Element> _elements, int _level, int _EXP, int _cumulativeEXP, int _status, int _health)
// {
    // this->name = _name;
    // this->skills = vector<Skill> (4);
    // this->skills[0] = _skill;
    // this->elements = _elements;
    // this->level = _level;
    // this->EXP = _EXP;
    // this->cumulativeEXP = _cumulativeEXP;
    // this->status = _status;
    // this->health = _health;
// }

map<int, Engimon> KatalogEngimon::katalogEngimon = map<int, Engimon> ();

Engimon::Engimon(){
    this->name = "";
    this->species = "";
    this->skills = vector<Skill> ();
    this->elements = vector<Element> ();
    this->level = 0;
    this->EXP = 0;
    this->cumulativeEXP = 0;
    this->status = true;
    this->health = 0;
}

// Single element engimon
Engimon::Engimon(string _species, string _name, list<pair<int, string>> _parent, Skill _skills, 
Element elm, int _level, int _EXP, 
int _cumulativeEXP, bool _status, int _health)
{
    this->species = _species;
    this->name = _name;
    // this->parent = _parent;
    this->level = _level;
    this->EXP = _EXP;
    this->cumulativeEXP = _cumulativeEXP;
    this->status = _status;
    this->health = _health;

    // cout << "Test 1" << endl;
    this->skills = vector<Skill> ();
    this->skills.push_back(_skills);

    this->elements = vector<Element> ();
    elements.push_back(elm);

    // cout << "Test 1" << endl;

    if (!_parent.empty()){
        parent.push_back(_parent.front());
        parent.push_back(_parent.back());
    }
    else{
        this->parent = list<pair<int, string>> ();
    }

    // cout << "Test 2" << endl;

}

Engimon::Engimon(string _species, string _name, list<pair<int, string>> _parent, Skill _skills, 
Element elm1, Element elm2, int _level, int _EXP, 
int _cumulativeEXP, bool _status, int _health) : 
Engimon(_species, _name, _parent, _skills, elm1, _level, 
_EXP, _cumulativeEXP, _status, _health){
    elements.push_back(elm2);
}

Engimon::~Engimon(){}

bool Engimon::operator==(const Engimon& otherEngimon){

    if (otherEngimon.skills.size() != skills.size() || 
    otherEngimon.parent.size() != parent.size() ||
    otherEngimon.elements.size() != elements.size()) return false;

    else{
        if (parent.front() != otherEngimon.parent.front() || 
        parent.back() != otherEngimon.parent.back()) return false;
        
        for (int i = 0; i < skills.size(); i++){
            if (skills[i] == otherEngimon.skills[i]);
            else return false;
        }
        for (int i = 0; i < elements.size(); i++){
            if (elements[i] == otherEngimon.elements[i]);
            else return false;
        }
    }
    return 
    (this->name == otherEngimon.name) &&
    (this->level == otherEngimon.level) &&
    (this->EXP == otherEngimon.EXP) &&
    (this->cumulativeEXP == otherEngimon.cumulativeEXP) &&
    (this->status == otherEngimon.status) &&
    (this->health == otherEngimon.health);
}

Engimon& Engimon::operator=(const Engimon& otherEngimon){
    this->name = otherEngimon.name;
    this->parent = otherEngimon.parent;
    this->level = otherEngimon.level;
    this->EXP = otherEngimon.EXP;
    this->cumulativeEXP = otherEngimon.cumulativeEXP;
    this->status = otherEngimon.status;
    this->health = otherEngimon.health;

    this->elements.clear();
    this->skills.clear();

    for (auto i = otherEngimon.elements.begin(); i != otherEngimon.elements.end(); ++i){
        elements.push_back(*i);
    }
    for (auto i = otherEngimon.skills.begin(); i != otherEngimon.skills.end(); ++i){
        skills.push_back(*i);
    }

    return *this;
}

ostream& operator<<(ostream& os, const Engimon& engimon){
    KatalogEngimon k;
    os << "+++++++++++++++++++++++++++++++" << endl;
    os << "| " << engimon.name << endl;
    os << "| Spesies      : " << engimon.species << endl;
    os << "| Parent       : ";

    if (engimon.parent.empty()) cout << "-" << endl;
    else{
        os << "(" << k[engimon.parent.front().first] << ")";
        os << engimon.parent.front().second << "/";
        os << "(" << k[engimon.parent.back().first] << ")";
        os << engimon.parent.back().second << endl;
    }

    os << "| Elements     : ";
    for (int i = 0; i < engimon.elements.size(); i++){
        if (i != 0) {cout << "/";}
        os << engimon.elements[i];
    }
    os << endl;
    os << "| Level        : " << engimon.level << endl; 
    os << "| EXP          : " << engimon.EXP << "/100" << endl;
    os << "| Total EXP    : " << engimon.cumulativeEXP << endl;
    os << "| Skills       : " << endl ;
    
    for (int i = 0; i < engimon.skills.size(); i++){
        os << engimon.skills[i] << endl;
    }
    os << "===============================" << endl;
    os << "+++++++++++++++++++++++++++++++" << endl;
    return os;
}

// getter
int Engimon::getLevel() const{
    return this->level;
}

int Engimon::getEXP() const{
    return this->EXP;
}

list<pair<int, string>> Engimon::getParent() const{
    return this->parent;
}

vector<Skill> Engimon::getSkills() const{
    return this->skills;
}

vector<Element> Engimon::getElement() const{
    return this->elements;
}

bool Engimon::getStatus() const{
    return this->status;
}

int Engimon::getHealth() const{
    return this->health;
}

void Engimon::setName(string _name){
    name = _name;
}
void Engimon::setParent(pair<int, string> _parent1, pair<int, string> _parent2){
    parent.clear();
    parent.push_back(_parent1);
    parent.push_back(_parent2);
}
void Engimon::setSkills(vector<Skill> _skills){
    skills.clear();
    
    for (auto i = _skills.begin(); i != _skills.end(); ++i){
        skills.push_back(*i);
    }
}

void Engimon::setElements(vector<Element> _elements){
    elements.clear();

    for (auto i = _elements.begin(); i != _elements.end(); ++i){
        elements.push_back(*i);
    }
}
void Engimon::setLevel(int _level){
    level = _level;
}

void Engimon::setEXP(int _EXP){
    EXP = _EXP;
}

void Engimon::setCumulativeEXP(int _cumulativeEXP){
    cumulativeEXP = _cumulativeEXP;
}
        
void Engimon::setStatus(bool _status){
    status = _status;
}

void Engimon::setHealth(int _health){
    health = _health;
}

// fungsi lain
void Engimon::upLevel(int naik){
    this->level+=naik;

    for (int i = 0; i < skills.size(); i++){
        skills[i].incrMasteryLevel();
    }
}

void Engimon::downLevel(int decr){
    if (this->level >= decr){
        this->level -= decr;
    }
    else{
        cout << "Level tidak cukup" << endl;
    }
}

void Engimon::addEXP(int exp){
    this->EXP += exp;
    this->cumulativeEXP += exp;

    if (cumulativeEXP > maxCumulative) {status = false;}
    else{
        if (EXP / 100 >= 1){
            upLevel(EXP/100);
            if (EXP % 100 == 0) {EXP = 0;}
            else {EXP = EXP%100;}
        }
    }
}

void Engimon::addSkills(Skill skill){
    if (this->skills.size() == maxSkill) { cout << "Slot skill penuh" << endl; }
    else{
        if (this->elements == skill.getElement()) {skills.push_back(skill);} //ini udah lolos error kalau misalnya elemennya cuman kebalik?
        //operator == vector itu harus urut kan ngeceknya? kalau kebalik gimana?
        else if (this->elements.size() == 2 && 
        (this->elements[0] == skill.getElement()[0] || this->elements[0] == skill.getElement()[1])) {skills.push_back(skill);}
        //kalau nambah skill yang sesuai elemen kedua gimana?
        else cout << "Elemen tidak sesuai" << endl;
    }
}

void Engimon::dropSkills(Skill skill){
    for (int i = 0; i < skills.size(); i++){
        if (skills[i] == skill){
            skills.erase(skills.begin() + i);
            return;
        }
    }
}

bool Engimon::checkNumOfElements() const{
    return elements.size() == 2;
}

// Kelas katalogEngimon
KatalogEngimon::KatalogEngimon(){
    katalogEngimon = map<int, Engimon> ();
    KatalogSkill skills;

    // skills.printtKatalogSkill();

    // list<string> parent1 = {"a", "b"};
    // cout << "Masuk sini?" << endl;
    Engimon e1("Spesies1","", {}, skills[0], fire, 1, 0, 0, true, 100);

    // list<string> parent2 = {"c", "d"};
    Engimon e2("Spesies2","", {}, skills[1], water, 1, 0, 0, true, 100);

    // list<string> parent3 = {"e", "f"};
    Engimon e3("Spesies3","", {}, skills[2], electric, 1, 0, 0, true, 100);

    // list<string> parent4;
    Engimon e4("Spesies4","", {}, skills[7], water, ground, 1, 0, 0, true, 100);


    katalogEngimon.insert(pair<int, Engimon>(0, e1));
    katalogEngimon.insert(pair<int, Engimon>(1, e2));
    katalogEngimon.insert(pair<int, Engimon>(2, e3));
    katalogEngimon.insert(pair<int, Engimon>(3, e4));

}

void KatalogEngimon::printKatalogEngimon(){
    for (int i = 0; i < katalogEngimon.size(); i++){
        cout << katalogEngimon[i];
    }
}

Engimon& KatalogEngimon::operator[](int i){
    return katalogEngimon[i];
}