#include "ListaDubluInlantuita.h"

istream& operator >>(istream& i, Nod_Dublu* c)
{
	int x;
	i >> x;
	c->SetI(x);
	return i;
}

ostream& operator <<(ostream& o, Nod_Dublu* c)
{
	o << c->GetI() << " ";
	return o;
}

void ListaDubluInlantuita::remove_x(int x)
{
	Nod_Dublu* nod = this->GetFirst();
	if (nod->GetI() == x)                   //cazul in care vrem sa stergem primul nod
	{
		Nod_Dublu* temp = nod->GetNext();
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
		Nod_Dublu* temp = nod->GetNext()->GetNext();
		temp->SetPrev(nod);
		delete nod->GetNext();
		nod->SetNext(temp);
	}
}

void ListaDubluInlantuita::insert_after_x(Nod_Dublu* new_element, int x)
{
	Nod_Dublu* c = this->GetCurrentNod();
	while (c->GetI() != x)								//caut nodul cu valorea x
	{
		c = c->GetNext();
		if (c == NULL)
			return;
	}
	Nod_Dublu* after_new = c->GetNext();						//initializez nodul ce urmeaza sa fie precedentul noului nod
	c->SetNext(new_element);							//inlocuiesc nodul urmator(al nodului curent) cu noul nod
	new_element->SetNext(after_new);
	new_element->SetNext(c);
	after_new->SetPrev(new_element);
}

ListaDubluInlantuita* ListaDubluInlantuita::operator +(ListaDubluInlantuita* first2)
{
	this->GetLast()->SetNext(first2->GetCurrentNod());
	this->SetLast(first2->GetLast());
	first2->GetFirst()->SetPrev(this->GetLast());
	return this;
}