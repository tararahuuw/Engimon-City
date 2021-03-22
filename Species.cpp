#include "Species.h"

/** CLASS SPECIES **/
// CTOR
Species::Species() : Species(""){}
Species::Species(string _name){ this->name = _name;}

// CCTOR
Species::Species(const Species& sp) : Species(sp.name){}

// OPERATOR OVERLOAD
Species& Species::operator=(const Species& sp)
{
    name = sp.name;
    return *this;
}
bool Species::operator==(const Species& sp) { return name == sp.name; }

// DTOR
Species::~Species(){}

/** CLASS SINGLE TYPE **/
// CTOR
SingleType::SingleType() : Species("")
{
    elm = new Element[nElm];
    elm[0] = none;
    skills = vector<Skill> ();
}

SingleType::SingleType(string _name, Element _elm, Skill _baseSkill) : Species(_name)
{   
    elm = new Element[nElm];
    skills = vector<Skill> ();
    skills.push_back(_baseSkill);
}

// CCTOR
SingleType::SingleType(const SingleType& sp) : SingleType(sp.name, sp.elm[0], sp.skills[0]){}

// DTOR
SingleType::~SingleType() { delete[] elm; }

// OPERATOR OVERLOAD
SingleType& SingleType::operator=(const SingleType& sp)
{
    name = sp.name;
    elm = sp.elm;
    skills = sp.skills;

    return *this;
}

bool SingleType::operator==(const SingleType& sp)
{ return (elm == sp.elm && skills == sp.skills && name == sp.name); }

// Getter
Element* SingleType::getElement() const { return elm; }
Element SingleType::getElement(int idx) const
{
    if (idx > 0) throw "IndexOutOfRange";
    else return elm[0];
}
int SingleType::getNumElement() const { return nElm; }

// Mengembalikan true
bool SingleType::isSingleElement() const { return true; }
bool SingleType::hasElement(Element elm) const { return elm == this->elm[0]; }
vector<Skill> SingleType::getSkill() const { return skills; }

void SingleType::addSkill(Skill _skill)
{
    if (skills.capacity() == 4) throw "SKILL IS FULL";
    else
    {
        if (_skill.hasElement(elm[0])) skills.push_back(_skill);
        else throw "INCOMPATIBLE ELEMENT";
    }
}

void SingleType::dropSkill(Skill _skill)
{
    for (int i = 0; i < skills.size(); i++){
        if (skills[i] == _skill){
            skills.erase(skills.begin() + i);
            return;
        }
    }
}

/** CLASS DOUBLE TYPE **/
DoubleType::DoubleType() : elm( NULL ), Species("")
{
    skills = vector<Skill> ();
}
DoubleType::DoubleType(string _name, Element* _elm, Skill _baseSkill) : Species(_name), elm(_elm)
{
    skills = vector<Skill> ();
    skills.push_back(_baseSkill); 
}

// DoubleType::DoubleType()
DoubleType::~DoubleType() { delete[] elm; }

DoubleType::DoubleType(const DoubleType& sp) : elm(sp.elm), Species(sp)
{
    skills = vector<Skill> ();
    skills = sp.skills;
}

DoubleType& DoubleType::operator=(const DoubleType& sp)
{
    name = sp.name;
    elm = sp.elm;
    skills = sp.skills;
}

bool DoubleType::operator==(const DoubleType& sp)
{
    return (sp.skills == skills && elm[0] == sp.elm[0] && elm[1] == sp.elm[1]
    && name == sp.name);
}

Element* DoubleType::getElement() const { return elm; }
Element DoubleType::getElement(int idx) const 
{ 
    if (idx==0) return elm[0];
    if (idx==1) return elm[1];
    if (idx > 1) throw "IndexOutOfRange";
}

void DoubleType::addSkill(Skill _skill)
{
    if (skills.capacity() == 4) throw "Full";
    else
    { 
        if (_skill.hasElement(elm[0]) || _skill.hasElement(elm[1]))
            skills.push_back(_skill);
        else throw "INCOMPATIBLE ELEMENT"; 
    }
}

int DoubleType::getNumElement() const { return nElm; }
bool DoubleType::isSingleElement() const { return true; }
bool DoubleType::hasElement(Element elm) const 
{ return elm == this->elm[0] || elm == this->elm[1]; }
vector<Skill> DoubleType::getSkill() const { return skills; }

// ostream overload
ostream& operator<<(ostream& os, const SingleType& sp)
{
    os << " | Spesies   : " << sp.name << endl;
    os << " | Element   : " << sp.elm[0] << endl;
}

ostream& operator<<(ostream& os, const DoubleType& sp)
{
    os << " | Spesies   : " << sp.name << endl;
    os << " | Element   : " << sp.elm[0];
    os << "/" << sp.elm[1] << endl;  
}

/** CLASS SPECIES COLLECTION **/
SpeciesCollection::SpeciesCollection()
{
    collection = map<int, Species*> ();
}

void SpeciesCollection::initSpecies()
{
    KatalogSkill skill;
    SingleType species1("Gemogorgon", fire, skill[0]);
    SingleType species1("Pikacu", electric, skill[1]);
}