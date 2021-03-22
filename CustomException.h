using namespace std;
class InventoryPenuhException : public exception{
	public:
	virtual char const * what() const { return "Inventory penuh"; } 
};

class InvalidIndexException : public exception{
	public:
	virtual char const * what() const { return "Invalid index";}
};

class InventoryKosongException : public exception{
	public:
	virtual char const * what() const { return "Inventory yang diminta kosong";}
};

class EmptySkillsItemException : public exception{
	public:
	virtual char const * what() const { return "Item skill yang diminta tidak ada";}
};

class InvalidEngimonException : public exception{
	public:
	virtual char const * what() const {return "Engimon yang dipilih tidak valid";}
};

class InvalidElement : public exception {
	public:
	virtual char const * what() const {return "Skill yang dipilih tidak sesuai dengan elemen Engimon";}
};

class SkillPenuh : public exception {
	public:
	virtual char const * what() const {return "Engimon sudah memiliki 4 skill";}
};

class SudahPunyaSkill : public exception {
	public:
	virtual char const * what() const {return "Engimon sudah memiliki skill ini";}
};

class TidakMemilikiSkill : public exception {
	public:
	virtual char const * what() const {return "Engimon tidak memiliki skill ini";}
};