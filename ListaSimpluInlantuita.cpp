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


ListaSimpluInlantuita* ListaSimpluInlantuita::operator=(ListaSimpluInlantuita* c)
{
	this->SetCurrentNod(c->GetCurrentNod());
	this->SetI(c->GetI);
	this->SetNext(c->GetNext);
}

bool ListaSimpluInlantuita::operator==(ListaSimpluInlantuita* c)
{
	if (this->GetCurrentNod() == c->GetCurrentNod())
		return true;
	else
		return false;
}

ListaSimpluInlantuita* ListaSimpluInlantuita::operator +(ListaSimpluInlantuita* first2)
{
	ListaSimpluInlantuita* c = this;
	while (!(c == first2))
		c->SetCurrentNod(c->GetNext());
	c->SetNext(first2->GetCurrentNod());
	return this;
}
ListaSimpluInlantuita::ListaSimpluInlantuita()
{
}


ListaSimpluInlantuita::~ListaSimpluInlantuita()
{
}
