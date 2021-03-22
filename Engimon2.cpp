#include "Engimon2.h"

Engimon::Engimon(){}

Engimon::Engimon(Species* _species, string _name, 
pair<pair<string, string>, pair<string, string>> _parent, 
int _level, int _EXP, int _cumulativeEXP, bool _status, bool _wild)
{
    species = _species;
    name = _name;
    parent = _parent;
    level = _level;
    EXP = _EXP;
    cumulativeEXP = _cumulativeEXP;
    status = _status;
    wild = _wild;
}

Engimon::~Engimon(){}

bool Engimon::operator==(const Engimon& engi)
{
    if ((this->species->isSingleElement() && engi.species->isSingleElement()) || 
    (!this->species->isSingleElement() && !engi.species->isSingleElement()))
    {
        return (species == engi.species &&
        name == engi.name &&
        parent == engi.parent &&
        level == engi.level &&
        EXP == engi.EXP &&
        cumulativeEXP == engi.cumulativeEXP &&
        status == engi.status &&
        wild == engi.wild
        );
    }
    return false;

}

Engimon& Engimon::operator=(const Engimon& engi)
{
    species = engi.species;
    name = engi.name;
    parent = engi.parent;
    level = engi.level;
    EXP = engi.EXP;
    cumulativeEXP = engi.cumulativeEXP;
    status = engi.status;
    wild = engi.wild;
}

ostream& operator<<(ostream& os, const Engimon& engi)
{
    os << engi.species << endl;
    os << engi.name << endl;
    os << engi.parent.first.first << endl;
    os << engi.parent.first.second << endl;
    os << engi.level << endl;
}

int Engimon::getLevel() const { return level; }
int Engimon::getEXP() const { return EXP; }
int Engimon::getCumulativeEXP() const { return cumulativeEXP; }
Species* Engimon::getSpecies() const { return species; }
pair<pair<string, string>, pair<string, string>> Engimon::getParent() const
{ return parent; }

void Engimon::upLevel(int incr)
{
    level+=incr;
    for (auto i = species->getSkill().begin(); i != species->getSkill().end(); ++i)
    {
        (*i).incrMasteryLevel();
    }
}

void Engimon::downLevel(int decr)
{
    level-=decr;
    cumulativeEXP-=(decr*100);
}

void Engimon::addEXP(int exp)
{
    EXP += exp;
    cumulativeEXP += exp;

    if (cumulativeEXP > maxCumulative) { status = false; }
    else
    {
        if (EXP/100 >= 1)
        {
            upLevel(EXP/100);
            if (EXP % 100 == 0) { EXP = 0; }
            else { EXP = EXP%100; }
        }
    }
}

bool Engimon::checkNumOfElements() const
{
    return species->isSingleElement();
}