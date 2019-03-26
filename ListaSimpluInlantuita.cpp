#include "ListaSimpluInlantuita.h"

istream& operator >>(istream& i, ListaSimpluInlantuita* c)
{
	int x;
	i >> x;
	c->SetI(x);
	return i;
}

ostream& operator <<(ostream& o, ListaSimpluInlantuita* c)
{
	o << c->GetI() << " ";
	return o;
}

ListaSimpluInlantuita* ListaSimpluInlantuita::operator +(ListaSimpluInlantuita* first2)
{
	ListaSimpluInlantuita* c1 = this;
	while (c1 != this)
		c1->SetCurrentNod(c1->GetNext());
	c1->SetNext(first2->GetCurrentNod());
	return this;
}

ListaSimpluInlantuita::ListaSimpluInlantuita()
{
}


ListaSimpluInlantuita::~ListaSimpluInlantuita()
{
}
