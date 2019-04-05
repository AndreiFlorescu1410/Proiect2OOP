#include <iostream>
#include <stddef.h>
using namespace std;

class Nod {
	int i;
	Nod* next;

public:
	Nod* GetNext() { return next; }
	void SetNext(Nod* Next) { next = Next; }
	int GetI() { return i; };
	void SetI(int x) { i = x; };

	friend ostream& operator <<(ostream&, Nod*);
	friend istream& operator >>(istream&, Nod*);
	friend class ListaSimpluInlantuita;

};

class ListaSimpluInlantuita {
	Nod* current_nod, *first, *last;
public:
	Nod* GetCurrentNod() { return current_nod; }
	void SetCurrentNod(Nod* current) { current_nod = current; }
	Nod* GetFirst() { return first; }
	void SetFirst(Nod* First) { first = First; }
	Nod* GetLast() { return last; }
	void SetLast(Nod* Last) { last = Last; }

	void remove_x(int);
	void insert_after_x(Nod*, int);
	ListaSimpluInlantuita();

	ListaSimpluInlantuita* operator+(ListaSimpluInlantuita*);
};
