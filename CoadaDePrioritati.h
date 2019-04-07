#include "ListaDubluInlantuita.h"

class Nod_Prioritate : public Nod_Dublu{
	Nod_Prioritate* prev, * next;
	int prio;
public:
	int GetPrio() { return prio; }
	void SetPrio(int Prio) { prio = Prio; }
	auto GetNext() { return next; }
	void SetNext(Nod* Next) { next = (Nod_Prioritate*)Next; }
	auto GetPrev() { return prev; }
	void SetPrev(Nod_Dublu* Prev) { prev = (Nod_Prioritate*)Prev; }

	friend ostream& operator <<(ostream&, Nod_Prioritate*);
	friend istream& operator >>(istream&, Nod_Prioritate*);

	Nod_Prioritate();
	friend class CoadaDePrioritati;
};


class CoadaDePrioritati : public ListaDubluInlantuita
{
	Nod_Prioritate* current_nod, *last, *first;
public:
	auto GetCurrentNod() { return current_nod; };
	void SetCurrentNod(Nod* current) { current_nod = dynamic_cast<Nod_Prioritate*>(current); };
	auto GetFirst() { return first; }
	void SetFirst(Nod* First) { first = dynamic_cast<Nod_Prioritate*>(First); }
	auto GetLast() { return last; }
	void SetLast(Nod* Last) { last = dynamic_cast<Nod_Prioritate*>(Last); }

	//void remove_x(int);
	void insert_after_x(Nod*, int);
	CoadaDePrioritati();
};

