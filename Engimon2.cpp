#include "Engimon2.h"

Engimon::Engimon()
{
    species = NULL;
    name = "";
    level = 0;
    EXP = 0;
    cumulativeEXP = 0;
    status = true;
    wild = true;
}

// ctor biasa
Engimon::Engimon(Species* _species, string _name, 
pair<pair<string, string>, pair<string, string>> _parent, 
int _level, int _EXP, int _cumulativeEXP, bool _status, bool _wild)
{
    // species = _species;
    Species** newInstance = new Species*(_species);
    species = *newInstance;
    name = _name;
    parent = _parent;
    level = _level;
    EXP = _EXP;
    cumulativeEXP = _cumulativeEXP;
    status = _status;
    wild = _wild;
    skills = vector<Skill> ();
    skills.push_back(_species->getBaseSkill());
}

// ctor dengan argument parent = string dan skill engimon diambil dari skill bawaan
Engimon::Engimon(Species* _species, string _name, string specParA, string nameParA, 
string specParB, string nameParB, int _level, int _EXP, int _cumulativeEXP, 
bool _status, bool _wild)
{
    // species = _species;
    Species** newInstance = new Species*(_species);
    species = *newInstance;
    name = _name;
    level = _level;
    EXP = _EXP;
    cumulativeEXP = _cumulativeEXP;
    status = _status;
    wild = _wild;
    parent = pair<pair<string, string>, pair<string, string>> ();
    setParent(specParA, nameParA, specParB, nameParB);
    skills = vector<Skill> ();
    skills.push_back(_species->getBaseSkill());
}

// ctor dengan argument parent = string dan skill engimon diambil dari argumen _skills
Engimon::Engimon(Species* _species, string _name, string specParA, string nameParA, 
string specParB, string nameParB, vector<Skill> _skills, int _level, int _EXP,
int _cumulativeEXP, bool _status, bool _wild)
{
    // species = _species;
    Species** newInstance = new Species*(_species);
    species = *newInstance;
    name = _name;
    level = _level;
    EXP = _EXP;
    cumulativeEXP = _cumulativeEXP;
    status = _status;
    wild = _wild;
    parent = pair<pair<string, string>, pair<string, string>> ();
    setParent(specParA, nameParA, specParB, nameParB);
    skills = _skills;
}

// ctor untuk wild engimon
Engimon::Engimon(Species* _species, int _level, int _EXP, int _cumulativeEXP, bool _status, bool _wild) : Engimon(_species, "", "", "", "", "", _level, _EXP, _cumulativeEXP, _status, _wild)
{

}

// ctor untuk wild engimon dengan skill > 1 jika mungkin (tanpa skill bawaan)
Engimon::Engimon(Species* _species, vector<Skill> _skills, int _level, int _EXP, int _cumulativeEXP, 
bool _status, bool _wild) : Engimon(_species, "", "", "", "", "", _skills, _level, _EXP, _cumulativeEXP, _status, _wild)
{

}

//dtor
Engimon::~Engimon(){
}

// operator overload
bool Engimon::operator==(const Engimon& engi)
{
    // cek apakah jumlah kedua elemen spesies sama
    if ((this->species->isSingleElement() && engi.species->isSingleElement()) || 
    (!this->species->isSingleElement() && !engi.species->isSingleElement()))
    {
        return (*(species) == *(engi.species) &&
        name == engi.name &&
        parent == engi.parent &&
        level == engi.level &&
        EXP == engi.EXP &&
        cumulativeEXP == engi.cumulativeEXP &&
        status == engi.status &&
        wild == engi.wild &&
        skills == engi.skills
        );
    }
    return false;

}
Engimon& Engimon::operator=(const Engimon& engi)
{
    // cout << "YEET" << endl;
    Species** newInstance = new Species*(engi.species);
    species = *newInstance;
    // species = engi.species;
    name = engi.name;
    parent = engi.parent;
    level = engi.level;
    EXP = engi.EXP;
    cumulativeEXP = engi.cumulativeEXP;
    status = engi.status;
    wild = engi.wild;
    skills = engi.skills;

    return *this;
}

void printSpace(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " ";
    }
}
ostream& operator<<(ostream& os, const Engimon& engi)
{
    os << "------------------------" << endl;
    os << "";
    if(engi.wild){
        os << " Wild " << engi.species->getName();
    }
    else{
        if (engi.name == "") { 
            os << " - "; 
        }
        else { 
            os << "| Name : " << engi.name;
        }
    } 
    os << endl;

    os << "" << " Spesies : " << engi.species->getName() << endl;
    os << "------------------------" << endl;

    return os;
}

// getter
int Engimon::getLevel() const { return level; }
int Engimon::getEXP() const { return EXP; }
int Engimon::getCumulativeEXP() const { return cumulativeEXP; }
Species* Engimon::getSpecies() const { return species; }
pair<pair<string, string>, pair<string, string>> Engimon::getParent() const
{ return parent; }
vector<Skill> Engimon::getSkills() const { return skills; }
bool Engimon::isWild() const { return wild; }
bool Engimon::getStatus() const { return status; }
string Engimon::getName() const { return name; }
vector<Element> Engimon::getElement() const
{
    vector<Element> elmnts;
    elmnts.push_back(species->getElement(0));

    if (!species->isSingleElement()) { elmnts.push_back(species->getElement(1)); }

    return elmnts;
}
float Engimon::getAdvantageElement(Element _elm2) const{
    return table[species->getElement(0)][_elm2];
}

vector<vector<float>> Engimon::getAdvElementTable() const{
    vector<vector<float>> tabel = vector<vector<float>>();
    for (int i = 0; i < 5; i++){
        vector<float> row;
        for (int j = 0; j < 5; j++){
            row.push_back(table[i][j]);
        }
        tabel.push_back(row);
    }
    return tabel;
}

float Engimon::countPower(Element elemenLawan) const{
    float sum = 0;
    for (auto i = skills.begin(); i != skills.end(); ++i)
    {
        sum+=((*i).getBasePower()*(*i).getMasteryLevel());
    }
    return level*(getAdvantageElement(elemenLawan)) + sum;
}

// setter
void Engimon::setWild(bool _wild){ this->wild = _wild; }
void Engimon::setParent(string speciesA, string parentA, string speciesB, string parentB)
{
    parent = pair<pair<string, string>, pair<string, string>> ();
    parent.first.first = speciesA;
    parent.first.second = parentA;
    parent.second.first = speciesB;
    parent.second.second = parentB;
}

void Engimon::setStatus(bool _status) { status = _status; }

void Engimon::addSkill(Skill _skill)
{
    
    //ini ngapa thrownya string WWKWKKWKWWKkWW
    if (skills.size() == 4) throw SkillPenuh(); // dicek apakah full
    else
    {
        
        // cek apa udah punya skill
        for (auto i = skills.begin(); i != skills.end(); ++i)
        {
            if ((*i) == _skill) throw SudahPunyaSkill();
        }
        
        // dicek apakah element sesuai, atau harusnya cek ini dulu ya diawal haha
        // SingleType Engimon
        if (species != NULL){
            
            if ( species->isSingleElement())
            {
                
                if (_skill.hasElement(species->getElement(0))) {skills.push_back(_skill);} 
                else {throw InvalidElement();} 
            }
            // Double type engimon
            else
            {
                if (_skill.hasElement(species->getElement(0)) || 
                _skill.hasElement(species->getElement(1))) {skills.push_back(_skill);} 
                else {throw InvalidElement(); }
            }
        }
        
        
    }
}

void Engimon::printDetail()
{
    cout <<  "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
    cout << "							       " << endl;
    if (!wild) cout << "     " << name;
    else { cout << "Wild" << species->getName();}
    cout << endl;
    cout << "	[ " << species->getName() << " ] [ " << species->getElement(0);
    if (!species->isSingleElement()){ cout << "/" << species->getElement(1); }
    cout << " ]" << endl;
    cout << "	[ Lvl : " << level << " ]";
    if (!wild){
        cout << " [ EXP : " << EXP << "/100 ] [";
        cout << "Total EXP : " << cumulativeEXP << " ]" << endl;
        cout << "	== Parent ==" << endl;
        cout << " 	";
        //print parent
        cout << "[ " << parent.first.first << " | " << parent.first.second << " ] X [ ";
        cout << " " << parent.second.first << " | " << parent.second.second << " ]" << endl;
    }
    cout << "    	== Skills ==" << endl;
    // print skills
    for (auto i = skills.begin(); i != skills.end(); ++i){
        cout << *i << endl;
    }
    cout <<  endl << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
}
void Engimon::dropSkill(Skill _skill)
{
    for (int i = 0; i < skills.size(); i++){
        if (skills[i] == _skill){
            skills.erase(skills.begin() + i);
            return;
        }
    }
    throw TidakMemilikiSkill();
}

// Menaikkan level engimon sebesar incr
// Skill yang sedang di equip ikut bertambah mastery levelnya
void Engimon::upLevel(int incr)
{
    level+=incr;
    for (auto i = skills.begin(); i != skills.end(); ++i)
    {
        (*i).incrMasteryLevel();
    }
}

// Menurunkan level engimon sebesar decr
// Cumulative EXP berkurang sebesar decr * 100 (EXP/Level)
void Engimon::downLevel(int decr)
{
    level-=decr;
    cumulativeEXP-=(decr*100);
}

// Menambahkan EXP sebesar exp
// Cumulative EXP ikut bertambah
// Apabila cumulativeEXP > 1500, engimon dihapus dari program
// Apabila EXP >= kelipatan seratus, engimon naik level
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
            if (EXP % 100 == 0) { EXP = 0; } // kondisi ini kayaknya dihapus aja
            else { EXP = EXP%100; }
        }
    }
}

// Mengembalikan jumlah elemen spesies engimon
bool Engimon::checkNumOfElements() const
{
    return species->isSingleElement();
}
