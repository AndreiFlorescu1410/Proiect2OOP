#include "CoadaDePrioritati.h"

istream& operator >>(istream& i, CoadaDePrioritati* c)
{
	int x, prio;
	i >> x >> prio;
	c->SetI(x);
	c->SetPrio(prio);
	return i;
}

ostream& operator <<(ostream& o, CoadaDePrioritati* c)
{
	o << c->GetI() << "(" << c->GetPrio() << ") ";
	return o;
}

CoadaDePrioritati* CoadaDePrioritati::operator +(CoadaDePrioritati* first2)
{
	CoadaDePrioritati* c1 = this;
	while (c1 != this)
		c1->SetCurrentNod(c1->GetNext());
	CoadaDePrioritati * c2 = first2;
	while (c2 != first2)
		c2->SetCurrentNod(c2->GetNext());
	c1->SetNext(first2->current_nod);
	first2->SetPrev(c1->current_nod);

	return this;
}

CoadaDePrioritati* CoadaDePrioritati::operator=(CoadaDePrioritati*)
{
	return nullptr;
}

CoadaDePrioritati::CoadaDePrioritati()
{
}


CoadaDePrioritati::~CoadaDePrioritati()
{
}
