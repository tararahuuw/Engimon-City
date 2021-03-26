#ifndef CustEx_H
#define CustEx_H

using namespace std;
class InventoryPenuhException : public exception{
	public:
	virtual char const * what() const noexcept { return "Inventory is full"; } 
};

class InvalidIndexException : public exception{
	public:
	virtual char const * what() const noexcept { return "Invalid index";}
};

class InventoryKosongException : public exception{
	public:
	virtual char const * what() const  noexcept { return "Inventory is empty";}
};

class EmptySkillsItemException : public exception{
	public:
	virtual char const * what() const noexcept { return "There is no item skill";}
};

class InvalidEngimonException : public exception{
	public:
	virtual char const * what() const noexcept {return "Invalid engimon choice";}
};

class InvalidElement : public exception {
	public:
	virtual char const * what() const noexcept {return "Choosen skill doesnt compatible with engimon's element(s)";}
};

class SkillPenuh : public exception {
	public:
	virtual char const * what() const noexcept {return "Engimon already has 4 skills";}
};

class SudahPunyaSkill : public exception {
	public:
	virtual char const * what() const noexcept {return "Engimon already has this skill";}
};

class TidakMemilikiSkill : public exception {
	public:
	virtual char const * what() const noexcept {return "Engimon doesnt have this skill";}
};

class ActiveEngimonKosong : public exception {
	public:
	virtual char const * what() const noexcept {return "There is no active engimon";}
};

class InvalidMove : public exception {
	public:
	virtual char const * what() const noexcept {return "Invalid move";}
};

class InvalidMoveEngimon : public InvalidMove{
	public:
	virtual char const * what() const noexcept {return "Invalid move active engimon\nRelocating...";}
};

class EnemyKosong : public exception{
	public:
	virtual char const * what() const noexcept {return "There is no enemy around";}
};

class NotEnoughEngiBreed : public exception{
	public:
	virtual char const * what() const noexcept {return "Not enough Engimon in inventory to breed";}
};

class NotEnoughLevel : public exception{
	public:
	virtual char const * what() const noexcept {return "Not enough level to breed";}
};

#endif