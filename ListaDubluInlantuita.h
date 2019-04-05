#include "ListaSimpluInlantuita.h"
#include <iostream>
using namespace std;

class Nod_Dublu : public Nod {
	Nod_Dublu *prev,*next;
public:
	Nod_Dublu* GetNext() { return next; }
	void SetNext(Nod_Dublu* Next) { next = Next; } 
	Nod_Dublu* GetPrev() { return prev; }
	void SetPrev(Nod_Dublu* Prev) { prev = Prev; }

	friend ostream& operator <<(ostream&, Nod_Dublu*);
	friend istream& operator >>(istream&, Nod_Dublu*);

	friend class ListaDubluInlantuita;
};

class ListaDubluInlantuita : public ListaSimpluInlantuita {
	Nod_Dublu* current_nod, *first, *last;
public:
	Nod_Dublu* GetCurrentNod() { return current_nod; }
	void SetCurrentNod(Nod_Dublu* current) { current_nod = current; }
	Nod_Dublu* GetFirst() { return first; }
	void SetFirst(Nod_Dublu* First) { first = First; }
	Nod_Dublu* GetLast() { return last; }
	void SetLast(Nod_Dublu* Last) { last = Last; }

	void remove_x(int);
	void insert_after_x(Nod_Dublu*, int);

	ListaDubluInlantuita* operator+(ListaDubluInlantuita*);
};
