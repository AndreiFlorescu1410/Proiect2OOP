#include "CoadaDePrioritati.h"

istream& operator >>(istream& i, Nod_Prioritate* c)
{
	int x, prio;
	i >> x >> prio;
	c->SetI(x);
	c->SetPrio(prio);
	return i;
}

CoadaDePrioritati* operator+(CoadaDePrioritati&, CoadaDePrioritati*)
{
	return nullptr;
}

ostream& operator <<(ostream& o, Nod_Prioritate* c)
{
	o << c->GetI() << "(" << c->GetPrio() << ") ";
	return o;
}


void CoadaDePrioritati::insert_after_x(Nod* new_Nod, int x)
{
	Nod_Prioritate* new_element = dynamic_cast<Nod_Prioritate*>(new_Nod);
	if (this->GetFirst() == NULL)
	{
		this->SetFirst(new_element);
		return;
	}
	Nod_Prioritate* c = this->GetFirst();
	while (c->GetI() != x && c != this->GetLast())								//caut nodul cu valorea x
	{
		c = c->GetNext();
	}
	//initializez nodul ce urmeaza sa fie precedentul noului nod
	c->SetNext(new_element);							//inlocuiesc nodul urmator(al nodului curent) cu noul nod
	new_element->SetPrev(c);
}

CoadaDePrioritati::CoadaDePrioritati()
{
	first = NULL;
	last = NULL;
	current_nod = NULL;
}


Nod_Prioritate::Nod_Prioritate()
{
	prev = NULL;
	next = NULL;
	prio = -2;
}
