#include "Species.h"

/** CLASS SPECIES **/
// ctor
Species::Species() : Species(""){}
Species::Species(string _name){ this->name = _name;}
// cctor
Species::Species(const Species& sp) : Species(sp.name){}
// operator overload
Species& Species::operator=(const Species& sp)
{
    name = sp.name;
    return *this;
}
ostream& operator<<(ostream& os, const Species& sp) { return sp.print(os); }
ostream& Species::print(ostream& os) const { return os; }
bool Species::operator==(const Species& sp) { return name == sp.name; }
// dtor
Species::~Species(){}
string Species::getName() const { return name; }

/** CLASS SINGLE TYPE **/
// ctor
SingleType::SingleType() : Species("")
{
    elm = new Element[nElm];
    elm[0] = none;
}
SingleType::SingleType(string _name, Element _elm, Skill _baseSkill) : Species(_name)
{  
    elm = new Element[nElm];
    elm[0] = _elm;
    baseSkill = _baseSkill;
}
// cctor
SingleType::SingleType(const SingleType& sp) : SingleType(sp.name, sp.elm[0], sp.baseSkill){}

// dtor
SingleType::~SingleType() { delete[] elm; }

// operator overload
SingleType& SingleType::operator=(const SingleType& sp)
{
    delete[] elm;
    elm = new Element[nElm];
    elm[0] = sp.elm[0];
    name = sp.name;
    baseSkill = sp.baseSkill;

    return *this;
}
bool SingleType::operator==(const SingleType& sp)
{ 
    return (elm[0] == sp.elm[0] && baseSkill == sp.baseSkill && name == sp.name); 
}
ostream& SingleType::print(ostream& os) const
{
    os << " | Species : " << this->name << endl;
    os << " | Elemen  : " << this->elm[0] << endl;
    // os << " | Skill   : " << endl << baseSkill << endl;
    // os << " --==--==--==--" << endl;
    return os;
}

// Getter
Element* SingleType::getElement() const { return elm; }
Element SingleType::getElement(int idx) const
{
    if (idx > 0) throw "InvalidIndexException()";
    else return elm[0];
}
int SingleType::getNumElement() const { return nElm; }
Skill SingleType::getBaseSkill() const { return this->baseSkill; }

// fungsi lain
bool SingleType::isSingleElement() const { return true; }
bool SingleType::hasElement(Element elm) const { return elm == this->elm[0]; }

/** CLASS DOUBLE TYPE **/
DoubleType::DoubleType() : elm( NULL ), Species("") {}
DoubleType::DoubleType(string _name, Element* _elm, Skill _baseSkill) : Species(_name)
{
    elm = new Element[2];
    elm[0] = _elm[0];
    elm[1] = _elm[1];
    baseSkill = _baseSkill; 
}

DoubleType::DoubleType(const DoubleType& sp) :Species(sp)
{
    elm = new Element[2];
    elm[0] = sp.elm[0];
    elm[1] = sp.elm[1];
    baseSkill = sp.baseSkill;
}

DoubleType::~DoubleType() { delete[] elm; }

// operator overload
DoubleType& DoubleType::operator=(const DoubleType& sp)
{
    name = sp.name;
    delete[] elm;
    elm = new Element[2];
    elm[0] = sp.elm[0];
    elm[1] = sp.elm[1];
    baseSkill = sp.baseSkill;

    return *this;
}

bool DoubleType::operator==(const DoubleType& sp)
{
    return (sp.baseSkill == baseSkill && elm[0] == sp.elm[0] && elm[1] == sp.elm[1]
    && name == sp.name);
}

ostream& DoubleType::print(ostream& os) const
{
    os << " | Species : " << this->name << endl;
    os << " | Elemen  : " << this->elm[0] << "/" << this->elm[1] << endl;
    // os << " | Skill   : " << endl << baseSkill << endl;
    // os << " --==--==--==--" << endl;
    return os;
}

// getter
Element* DoubleType::getElement() const { return elm; }
Element DoubleType::getElement(int idx) const 
{ 
    if (idx > 1) throw "InvalidIndexException()";
    if (idx==0) return elm[0];
    if (idx==1) return elm[1];
}
int DoubleType::getNumElement() const { return nElm; }

// fungsi abc
bool DoubleType::isSingleElement() const { return false; }
Skill DoubleType::getBaseSkill() const { return this->baseSkill; }
bool DoubleType::hasElement(Element elm) const 
{ return elm == this->elm[0] || elm == this->elm[1]; }

/** CLASS SPECIES FACTORY **/
SpeciesFactory::SpeciesFactory()
{
    collection = map<int, Species*> ();
}

ostream& operator<<(ostream&os, const pair<int, Species*>& sp)
{
    return sp.second->print(os);
}

void SpeciesFactory::initSpecies()
{
    // Aturan penomoran
        // 0 mod 8 : fire
        // 1 mod 8 : water
        // 2 mod 8 : electric
        // 3 mod 8 : ground
        // 4 mod 8 : ice
        // 5 mod 8 : fire electric
        // 6 mod 8 : water ice
        // 7 mod 8 : water ground
    SkillsFactory skill;
    Element fire_electric[] = {fire, electric};
    Element water_ground[] = {water, ground};
    Element water_ice[] = {water, ice};

    Species* fire1 = new SingleType ("Snorlax", fire, skill[1]);
    Species* water1 = new SingleType ("Dewgong", water, skill[5]);
    Species* electric1 = new SingleType ("Zapdos", electric, skill[13]);
    Species* ground1 = new SingleType ("Tangela", ground, skill[9]);
    Species* ice1 = new SingleType ("Articuno", ice, skill[17]);
    Species* fire_electric1 = new DoubleType("Exeggutor", fire_electric, skill[16]);
    Species* water_ice1 = new DoubleType("Cloyster", water_ice, skill[21]);
    Species* water_ground1 = new DoubleType("Venusaur", water_ground, skill[10]);
    Species* fire2 = new SingleType ("Kangaskhan", fire, skill[1]);
    Species* water2 = new SingleType ("Jynx", water, skill[5]);
    Species* electric2 = new SingleType ("Magnemite", electric, skill[13]);
    Species* ground2 = new SingleType ("Victreebel", ground, skill[9]);
    Species* ice2 = new SingleType ("Lapras", ice, skill[17]);
    Species* fire_electric2 = new DoubleType("Voltorb", fire_electric, skill[16]);
    Species* water_ice2 = new DoubleType("Vaporeon", water_ice, skill[21]);
    Species* water_ground2 = new DoubleType("Meowth", water_ground, skill[10]);
    
    collection.insert(pair<int, Species*>(0, fire1));
    collection.insert(pair<int, Species*>(1, water1));
    collection.insert(pair<int, Species*>(2, electric1));
    collection.insert(pair<int, Species*>(3, ground1));
    collection.insert(pair<int, Species*>(4, ice1));
    collection.insert(pair<int, Species*>(5, fire_electric1));
    collection.insert(pair<int, Species*>(6, water_ice1));
    collection.insert(pair<int, Species*>(7, water_ground1));
    collection.insert(pair<int, Species*>(8, fire2));
    collection.insert(pair<int, Species*>(9, water2));
    collection.insert(pair<int, Species*>(10, electric2));
    collection.insert(pair<int, Species*>(11, ground2));
    collection.insert(pair<int, Species*>(12, ice2));
    collection.insert(pair<int, Species*>(13, fire_electric2));
    collection.insert(pair<int, Species*>(14, water_ice2));
    collection.insert(pair<int, Species*>(15, water_ground2));
}

void SpeciesFactory::printAllSpecies()
{
    for (auto i = collection.begin(); i!=collection.end(); ++i) { cout << *i; }
}

Species*& SpeciesFactory::operator[](int idx)
{
    return collection.at(idx);
} 