#ifndef CustEx_H
#define CustEx_H

using namespace std;
class InventoryPenuhException : public exception{
	public:
	virtual char const * what() const noexcept { return "Inventory penuh"; } 
};

class InvalidIndexException : public exception{
	public:
	virtual char const * what() const noexcept { return "Invalid index";}
};

class InventoryKosongException : public exception{
	public:
	virtual char const * what() const  noexcept { return "Inventory yang diminta kosong";}
};

class EmptySkillsItemException : public exception{
	public:
	virtual char const * what() const noexcept { return "Item skill yang diminta tidak ada";}
};

class InvalidEngimonException : public exception{
	public:
	virtual char const * what() const noexcept {return "Engimon yang dipilih tidak valid";}
};

class InvalidElement : public exception {
	public:
	virtual char const * what() const noexcept {return "Skill yang dipilih tidak sesuai dengan elemen Engimon";}
};

class SkillPenuh : public exception {
	public:
	virtual char const * what() const noexcept {return "Engimon sudah memiliki 4 skill";}
};

class SudahPunyaSkill : public exception {
	public:
	virtual char const * what() const noexcept {return "Engimon sudah memiliki skill ini";}
};

class TidakMemilikiSkill : public exception {
	public:
	virtual char const * what() const noexcept {return "Engimon tidak memiliki skill ini";}
};

class ActiveEngimonKosong : public exception {
	public:
	virtual char const * what() const noexcept {return "Tidak ada active engimon";}
};

class InvalidMove : public exception {
	public:
	virtual char const * what() const noexcept {return "Invalid move";}
};

class InvalidMoveEngimon : public InvalidMove{
	public:
	virtual char const * what() const noexcept {return "Invalid move active engimon\nRelocating...";};
};

#endif