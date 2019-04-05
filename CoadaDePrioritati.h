#include "ListaDubluInlantuita.h"

class Nod_Prioritate : public Nod_Dublu{
	Nod_Prioritate* prev, * next;
	int prio;
public:
	int GetPrio() { return prio; }
	void SetPrio(int Prio) { prio = Prio; }
	Nod_Prioritate* GetNext() { return next; }
	void SetNext(Nod_Prioritate* Next) { next = Next; }
	Nod_Prioritate* GetPrev() { return prev; }
	void SetPrev(Nod_Prioritate* Prev) { prev = Prev; }

	friend ostream& operator <<(ostream&, Nod_Prioritate*);
	friend istream& operator >>(istream&, Nod_Prioritate*);

	//Nod_Prioritate* operator=(Nod*);
	bool operator==(Nod_Prioritate*);

	friend class CoadaDePrioritati;
};


class CoadaDePrioritati : public ListaDubluInlantuita
{
	Nod_Prioritate* current_nod, *last, *first;
public:
	Nod_Prioritate* GetCurrentNod() { return current_nod; }
	void SetCurrentNod(Nod_Prioritate* current) { current_nod = current; }
	Nod_Prioritate* GetFirst() { return first; }
	void SetFirst(Nod_Prioritate* First) { first = First; }
	Nod_Prioritate* GetLast() { return last; }
	void SetLast(Nod_Prioritate* Last) { last = Last; }

	void remove_x(CoadaDePrioritati*&, int);
	void insert_after_x(CoadaDePrioritati*, Nod_Prioritate*, int);
	CoadaDePrioritati* operator+(CoadaDePrioritati*);

	CoadaDePrioritati();
};

