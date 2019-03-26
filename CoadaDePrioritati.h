#include "ListaDubluInlantuita.h"

class Nod_Prioritate : public Nod_Dublu{
	int prio;
public:
	friend class CoadaDePrioritati;
};


class CoadaDePrioritati : public ListaDubluInlantuita
{
	Nod_Prioritate* current_nod;
public:
	int GetPrio() { return current_nod->prio; }
	void SetPrio(int Prio) { current_nod->prio = Prio; }

	CoadaDePrioritati* operator+(CoadaDePrioritati*);

	CoadaDePrioritati();
	~CoadaDePrioritati();;
};

