#include "ListaDubluInlantuita.h"

istream& operator >>(istream& i, ListaDubluInlantuita* c)
{
	int x;
	i >> x;
	c->SetI(x);
	return i;
}

ostream& operator <<(ostream& o, ListaDubluInlantuita* c)
{
	o << c->GetI() << " ";
	return o;
}

ListaDubluInlantuita* ListaDubluInlantuita::operator +(ListaDubluInlantuita* first2)
{
	ListaDubluInlantuita* c1 = this;
	while (c1 != this)
		c1->SetCurrentNod(c1->GetNext());
	ListaDubluInlantuita * c2 = first2;
	while (c2 != first2)
		c2->SetCurrentNod(c2->GetNext());
	c1->SetNext(first2->current_nod);
	first2->SetPrev(c1->current_nod);

	return this;
}

ListaDubluInlantuita::ListaDubluInlantuita()
{
}


ListaDubluInlantuita::~ListaDubluInlantuita()
{
}
