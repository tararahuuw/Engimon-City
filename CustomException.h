
class InventoryPenuhException : public exception{
	public:
	virtual char const * what() const { return "Inventory penuh"; } 
}

class InvalidIndexException : public exception{
	public:
	virtual char const * what() const { return "Invalid index";}
}

class InventoryKosongException : public exception{
	public:
	virtual char const * what() const { return "Inventory yang diminta kosong";}
}

class EmptySkillsItemException : public exception{
	public:
	virtual char const * what() const { return "Item skill yang diminta tidak ada";}
}

class InvalidEngimonException : public exception{
	public:
	virtual char const * what() const {return "Engimon yang dipilih tidak valid";}
}