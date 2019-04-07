#include "ListaSimpluInlantuita.h"
#include <iostream>
using namespace std;

class Nod_Dublu : public Nod {
	Nod_Dublu *prev,*next;
public:
	auto GetNext() { return next; }
	void SetNext(Nod* Next) { next = dynamic_cast<Nod_Dublu*>(Next); }
	virtual Nod_Dublu* GetPrev() { return prev; }
	virtual void SetPrev(Nod_Dublu* Prev) { prev = Prev; }

	friend ostream& operator <<(ostream&, Nod_Dublu*);
	friend istream& operator >>(istream&, Nod_Dublu*);

	Nod_Dublu();
	friend class ListaDubluInlantuita;
};

class ListaDubluInlantuita : public ListaSimpluInlantuita {
	Nod_Dublu* current_nod, *first, *last;
public:
	auto GetCurrentNod() { return current_nod; };
	void SetCurrentNod(Nod* current) { current_nod = dynamic_cast<Nod_Dublu*>(current); };
	auto GetFirst() { return first; }
	void SetFirst(Nod* First) { first = dynamic_cast<Nod_Dublu*>(First); }
	auto GetLast() { return last; }
	void SetLast(Nod* Last) { last = dynamic_cast<Nod_Dublu*>(Last); }
	void f(Nod_Dublu* d) { cout << "NU"; };
	bool remove_x(int);
	void insert_after_x(Nod*, int);

	friend ListaDubluInlantuita* operator+(ListaDubluInlantuita&, ListaDubluInlantuita*);
};
