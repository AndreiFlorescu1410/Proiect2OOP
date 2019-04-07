#include <iostream>
#include <stddef.h>
using namespace std;

class Nod {
	int i;
	Nod* next;

public:
	virtual Nod* GetNext() { return next; }
	virtual void SetNext(Nod* Next) { next = Next; }
	int GetI() { return i; };
	void SetI(int x) { i = x; };

	friend ostream& operator <<(ostream&, Nod*);
	friend istream& operator >>(istream&, Nod*);

	Nod();
	friend class ListaSimpluInlantuita;

};

class ListaSimpluInlantuita {
	Nod* current_nod, *first, *last;
public:
	virtual Nod* GetCurrentNod() { return current_nod; }
	virtual void SetCurrentNod(Nod* current) { current_nod = current; }
	virtual Nod* GetFirst() { return first; }
	virtual void SetFirst(Nod* First) { first = First; }
	virtual Nod* GetLast() { return last; }
	virtual void SetLast(Nod* Last) { last = Last; }

	virtual bool remove_x(int);
	virtual void insert_after_x(Nod*, int);
	ListaSimpluInlantuita();

	ListaSimpluInlantuita* operator+(ListaSimpluInlantuita*);
};
