#include "ListaSimpluInlantuita.h"
#include <iostream>
using namespace std;

class Nod_Dublu : public Nod {
	Nod* prev;
public:
	friend class ListaDubluInlantuita;
};

class ListaDubluInlantuita : public ListaSimpluInlantuita {
	Nod_Dublu* current_nod;
public:
	Nod* GetPrev() { return current_nod->prev; }
	void SetPrev(Nod* Prev) { current_nod->prev = Prev; }

	friend ostream& operator <<(istream& i, ListaDubluInlantuita* c);
	friend istream& operator >>(istream& i, ListaDubluInlantuita* c);
	ListaDubluInlantuita* operator+(ListaDubluInlantuita*);

	ListaDubluInlantuita();
	~ListaDubluInlantuita();
};
