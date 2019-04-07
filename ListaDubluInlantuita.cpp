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

bool ListaDubluInlantuita::remove_x(int x)
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
		while (nod->GetI() != x)            //caut nodul cu valorea x
		{
			nod = nod->GetNext();
			if (nod == NULL)
				return 0;
		}
		if (this->GetLast() == nod)
		{
			this->SetLast(nod->GetPrev());
			delete nod;
			return 1;
		}
		Nod_Dublu* temp = nod->GetNext();
		temp->SetPrev(nod->GetPrev());
		nod->GetPrev()->SetNext(temp);
		delete nod;
	}
	return 1;
}

void ListaDubluInlantuita::insert_after_x(Nod* new_Nod, int x)
{
	Nod_Dublu* new_element = dynamic_cast<Nod_Dublu*>(new_Nod);
	if (this->GetFirst() == NULL)
	{
		this->SetFirst(new_element);
		return;
	}
	Nod_Dublu* c = this->GetFirst();
	while (c->GetI() != x && c != this->GetLast())								//caut nodul cu valorea x
	{
		c = c->GetNext();
	}
	//initializez nodul ce urmeaza sa fie precedentul noului nod
	c->SetNext(new_element);							//inlocuiesc nodul urmator(al nodului curent) cu noul nod
	new_element->SetPrev(c);
}

ListaDubluInlantuita* operator +(ListaDubluInlantuita& first, ListaDubluInlantuita* first2)
{
	first.GetLast()->SetNext(first2->GetCurrentNod());
	first.SetLast(first2->GetLast());
	first2->GetFirst()->SetPrev(first.GetLast());
	return &first;
}

Nod_Dublu::Nod_Dublu()
{
	prev = NULL;
	next = NULL;
}
