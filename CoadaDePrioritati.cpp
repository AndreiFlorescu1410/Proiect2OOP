#include "CoadaDePrioritati.h"

istream& operator >>(istream& i, Nod_Prioritate* c)
{
	int x, prio;
	i >> x >> prio;
	c->SetI(x);
	c->SetPrio(prio);
	return i;
}

ostream& operator <<(ostream& o, Nod_Prioritate* c)
{
	o << c->GetI() << "(" << c->GetPrio() << ") ";
	return o;
}

void CoadaDePrioritati::remove_x(CoadaDePrioritati*& lista, int x)
{
	Nod_Prioritate* nod = lista->GetFirst();
	if (nod->GetI() == x)                   //cazul in care vrem sa stergem primul nod
	{
		Nod_Prioritate* temp = nod->GetNext();
		delete nod;
		nod = temp;
	}
	else
	{
		while (nod->GetNext()->GetI() != x)            //caut nodul cu valorea x
		{
			nod = nod->GetNext();
			if (nod == NULL)
				return;
		}
		nod->SetNext(nod->GetNext()->GetNext());
		if (nod->GetNext()->GetNext())
			nod->GetNext()->GetNext()->SetPrev(nod);
		delete nod->GetNext();
	}
}

void CoadaDePrioritati::insert_after_x(CoadaDePrioritati* lista, Nod_Prioritate* new_element , int x)
{

	Nod_Prioritate* c = lista->GetCurrentNod();
	while (c->GetI() != x)								//caut nodul cu valorea x
	{
		c = c->GetNext();
		if (c == NULL)
			return;
	}
	Nod_Prioritate* after_new = c->GetNext();						//initializez nodul ce urmeaza sa fie precedentul noului nod
	c->SetNext(new_element);							//inlocuiesc nodul urmator(al nodului curent) cu noul nod
	new_element->SetNext(after_new);
	new_element->SetNext(c);
	after_new->SetPrev(new_element);
}

CoadaDePrioritati* CoadaDePrioritati::operator +(CoadaDePrioritati* first2)
{
	this->GetLast()->SetNext(first2->GetCurrentNod());
	this->SetLast(first2->GetLast());
	first2->GetFirst()->SetPrev(this->GetLast());
	return this;
}

CoadaDePrioritati::CoadaDePrioritati()
{
	first = NULL;
	last = NULL;
	current_nod = NULL;
}

bool Nod_Prioritate::operator==(Nod_Prioritate* c)
{
	if (*this == c)
		return true;
	else
		return false;
}
