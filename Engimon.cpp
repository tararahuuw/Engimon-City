#include "Engimon.h"

// wild engimon
Engimon::Engimon(string _name, Skill _skill, vector<Element> _elements, int _level, int _EXP, int _cumulativeEXP, int _status, int _health)
{
    this->name = _name;
    this->skills = vector<Skill> (4);
    this->skills[0] = _skill;
    this->elements = _elements;
    this->level = _level;
    this->EXP = _EXP;
    this->cumulativeEXP = _cumulativeEXP;
    this->status = _status;
    this->health = _health;
}

Engimon::Engimon(string _name, list<string> _parent, Skill _skills, Element elm, int _level, int _EXP, int _cumulativeEXP, int _status, int _health){
    this->name = _name;
    this->parent = _parent;
    this->level = _level;
    this->EXP = _EXP;
    this->cumulativeEXP = _cumulativeEXP;
    this->status = _status;
    this->health = _health;

    this->skills = vector<Skill> (4);
    this->skills[0] = _skills;
    this->elements = vector<Element> ();
    elements.push_back(elm);

}

Engimon::Engimon(string _name, list<string> _parent, Skill _skills, Element elm1, Element elm2, int _level, int _EXP, int _cumulativeEXP, int _status, int _health) : Engimon(_name, _parent, _skills, elm1, _level, _EXP, _cumulativeEXP, _status, _health){
    elements.push_back(elm2);
}

Engimon::~Engimon(){}

bool Engimon::operator==(const Engimon& otherEngimon){
    return 
    this->name == otherEngimon.name &&
    this->name == otherEngimon.name &&
    this->parent == otherEngimon.parent && 
    this->level == otherEngimon.level &&
    this->EXP == otherEngimon.EXP &&
    this->cumulativeEXP == otherEngimon.cumulativeEXP &&
    this->status == otherEngimon.status &&
    this->health == otherEngimon.health &&
    this->skills == otherEngimon.skills &&
    this->elements == otherEngimon.elements;
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
    this->elements.clear();

    for (int i = 0; i < otherEngimon.elements.size(); i++){
        this->elements.push_back(otherEngimon.elements[i]);
    }

    return *this;
}