#include "ListaSimpluInlantuita.h"

void ListaSimpluInlantuita::remove_x( int x)
{
	Nod* nod = this->GetFirst();
	if (nod->GetI() == x)                   //cazul in care vrem sa stergem primul nod
	{
		Nod* temp = nod->GetNext();
		delete nod;
		this->SetFirst(temp);
	}
	else
	{
		while (nod->GetNext()->GetI() != x)            //caut nodul cu valorea x
		{
			nod = nod->GetNext();
			if (nod == NULL)
				return;
		}
		if (this->GetLast() == nod->GetNext())
		{
			this->SetLast(nod);
			delete nod->GetNext();
			return;
		}
		Nod* temp = nod->GetNext()->GetNext();
		delete nod->GetNext();
		nod->SetNext(temp);
	}
}

void ListaSimpluInlantuita::insert_after_x(Nod* new_element, int x)
{
	if (this->GetFirst() == NULL)
	{
		this->SetFirst(new_element);
		return;
	}
	Nod* c = this->GetFirst();
	while (c->GetI() != x && c != this->GetLast())								//caut nodul cu valorea x
	{
		c = c->GetNext();
	}
	Nod * after_new = c->GetNext();						//initializez nodul ce urmeaza sa fie precedentul noului nod
	c->SetNext(new_element);							//inlocuiesc nodul urmator(al nodului curent) cu noul nod
	new_element->SetNext(after_new);
}

ListaSimpluInlantuita::ListaSimpluInlantuita()
{
	first = NULL;
	last = NULL;
	current_nod = NULL;
}

istream& operator >>(istream& i, Nod* c)
{
	int x;
	i >> x;
	c->SetI(x);
	return i;
}

ostream& operator <<(ostream& o, Nod* c)
{
	o << c->GetI() << " ";
	return o;
}

ListaSimpluInlantuita* ListaSimpluInlantuita::operator +(ListaSimpluInlantuita* first2)
{
	this->GetLast()->SetNext(first2->GetCurrentNod());
	this->SetLast(first2->GetLast());
	return this;
}
