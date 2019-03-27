#include <iostream>
using namespace std;

class Nod {
	int i;
	Nod* next;

public:
	Nod* GetNext() { return next; }
	void SetNext(Nod* Next) { next = Next; }
	int GetI() { return i; };
	void SetI(int x) { i = x; };
	friend class ListaSimpluInlantuita;
};

class ListaSimpluInlantuita {
	Nod* current_nod;
public:
	Nod* GetCurrentNod() { return current_nod; }
	void SetCurrentNod(Nod* current) { current_nod = current; }

	Nod* GetNext() { return current_nod->next; }
	void SetNext(Nod* Next) { current_nod->next = Next; }
	int GetI() { return current_nod->i; };
	void SetI(int x) { current_nod->i = x; };

	friend ostream& operator <<(istream& i, ListaSimpluInlantuita* c);
	friend istream& operator >>(istream& i, ListaSimpluInlantuita* c);
	ListaSimpluInlantuita* operator+(ListaSimpluInlantuita*);
	ListaSimpluInlantuita* operator=(ListaSimpluInlantuita*);
	bool operator==(ListaSimpluInlantuita*);

	ListaSimpluInlantuita();
	~ListaSimpluInlantuita();
};
