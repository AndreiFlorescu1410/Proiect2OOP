#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include "CoadaDePrioritati.h"
using namespace std;

#define antet {system("CLS");cout<<"       Proiect 1 OOP -- liste circulare(alocate dinamic) -- Florescu Andrei Gr. 212         "<<endl<<endl;}


void insert_final(ListaSimpluInlantuita * &c, ListaSimpluInlantuita* new_element)
{
	if (c == NULL)
		c = new_element;
	else if (c->GetNext() == NULL)      //cazul in care nodul cap este singurul din lista si trebuie formata lista circulara
	{
		c->SetNext(new_element->GetCurrentNod);
		c = new_element;                //noul element devine capul listei
	}
}

void insert_after_x(ListaSimpluInlantuita* c, ListaSimpluInlantuita* new_element, int x)
{
	while (c->GetI() != x)								//caut nodul cu valorea x
		c->SetCurrentNod(c->GetNext());
	Nod* after_new = c->GetNext();						//initializez nodul ce urmeaza sa fie precedentul noului nod
	c->SetNext(new_element->GetCurrentNod());			//inlocuiesc nodul urmator(al nodului curent) cu noul nod
	new_element->SetNext(after_new);
}

void remove_x(ListaSimpluInlantuita* &first, ListaSimpluInlantuita* c, int x) //'first' este primul nod, 'c' este nodul de unde vrem sa incepem cautarea si 'x' valoarea pe care vrem sa o stergem
{
	if (first == c)                   //cazul in care vrem sa stergem primul nod
		first->SetCurrentNod(c->GetNext());
	else
	{
		while (c->GetNext()->GetI() != x)            //caut nodul cu valorea x
			c->SetCurrentNod(c->GetNext());
		c->SetNext(c->GetNext()->GetNext());
		delete c->GetNext;
	}
}

void remove_k(ListaSimpluInlantuita* &first, ListaSimpluInlantuita* c, int& n, int k) //argumente similare cu 'remove_x', insa, in loc de valoarea x, avem distanta dintre elemente si numarul de elemente din lista
{
	while (n > 1) //cat timp mai sunt noduri de sters
	{
		ListaSimpluInlantuita* temp;
		temp->SetCurrentNod(c->GetNext());
		if (c == first)
			first->SetCurrentNod(c->GetNext());
		remove_x(first, c, c->GetI()); //sterg nodul curent
		c = temp;
		n--;
		for (int i = 0; i < k-1; i++)  //avansez k noduri
			c->SetCurrentNod(c->GetNext());
	}

}
int read(int& n, int reading_list) //meniul de citire. Foloesesc reading_list sa stiu daca citesc lista sau elementul 'k'
{								   //1-lista simpla 2-lista dubla 3- coada de prioritati 0-'k'
	int k;
	antet

		cout << "Alegeti metoda de citire a" << ((reading_list == 0) ? " a lui k " : " listei:") << endl; //afisare in functie de ce citesc
	cout << "1. Fisier" << endl;
	cout << "2. Tastatura" << endl;
	int caz;
	cin >> caz;
	switch (caz)
	{
	case 1:  //fisier
	{
		while (1)
		{
			antet
				cout << "Dati numele fisierului: ";
			char txt_name[100];
			cin >> txt_name;          //citesc numele fisierului
			ifstream f(txt_name);
			if (f.is_open() == 0)    //testez daca exista fisierul citit
			{
				antet
					cout << "Nu am putut deschide fisierul." << endl;
				cout << "Apasa orice tasta pentru a te intoarce..." << endl;
				_getch();
			}
			else                    //am putut sa deschid fisierul
			{
				if (reading_list >= 1)
				{
					if (reading_list == 1)
						ListaSimpluInlantuita * new_element = c;
					else if (reading_list == 2)
						ListaDubluInlantuita * new_element = c;
					c = NULL;
					while (f >> new_element)             //citesc valoarea nodului
					{
						insert_final(c, new_element);  //il adaug la "finalul" listei
						new_element = new lista;      //reinitializez noul element
						n++;                          //incrementez numarul nodurilor din lista
					}
				}
				else
					f >> k;
				break;

			}
		}
		break;
	}
	case 2: //tastatura
	{
		while (1)
		{
			antet
				if (reading_list == 1)
				{
					cout << "Dati numarul de elemente din lista: ";
					cin >> n;
					cout << "Dati elementele listei: ";
					lista* new_element = c;
					c = NULL;
					for (int i = 0; i < n; i++)
					{
						cin >> new_element;           //citesc valoarea nodului
						insert_final(c, new_element);  //il adaug la "finalul" listei
						new_element = new lista;      //reinitializez noul element
					}
				}
				else
				{
					cout << "Dati valoarea lui k: ";
					cin >> k;
				}
			break;

		}

		break;
	}
	default:
	{
		antet
			cout << "Optiune inexistenta." << endl;
		cout << "Apasa orice tasta pentru a te intoarce..." << endl;
		_getch();
		read(c, n, (reading_list == 1) ? 1 : 0); //ma reintorc la meniul principal
		break;
	}
	}
	if (reading_list == 1)
		return 0;
	else
		return k;
}

void afisare(lista * first, int n) //afiseaz lista care incepe de la nodul "first"
{
	antet
		cout << "Lista are " << n << " elemente: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << first;
		first = (first->GetNext());
	}
	cout << endl << "Apasa orice tasta pentru a te intoarce..." << endl;
	_getch();
}




void menu(lista * first, int n) //meniul principal al programului
{
	antet
		cout << "Meniu: " << endl;
	cout << "1. Afiseaza lista" << endl;
	cout << "2. Adauga un nou element" << endl;
	cout << "3. Sterge un element" << endl;
	cout << "4. Elimina elemente din k in k" << endl;
	cout << "5. Concateneaza lista curenta cu una noua" << endl;
	cout << "9. Iesi din program" << endl;

	int caz;
	cin >> caz;

	switch (caz)
	{
	case 1:
	{
		afisare(first, n);
		break;
	}
	case 2:
	{
		while (1) { //loop infinit pentru a trata cazul in care se introduce un numar ce nu face parte din meniu
			antet
				cout << "1. Adauga la finalul listei" << endl;
			cout << "2. Adauga dupa nodul 'x'" << endl;

			int caz2;
			cin >> caz2;

			antet
				lista* new_element = new lista;
			cout << "Dati valoarea noului nod: "; cin >> new_element; //citesc noul nod, inainte de a intra in switch, pentru a economisi memorie

			lista* ultim = first->GetPrev(); //first->GetPrev() este, in cazul de fata, ultimul element din couda
			switch (caz2)
			{
			case 1:
			{
				insert_final(ultim, new_element);
				n++;
				cout << endl << "Nod adaugat cu succes." << endl;
				cout << endl << "Apasa orice tasta pentru a te intoarce..." << endl;
				_getch();
				break;
			}
			case 2:
			{
				int x;
				cout << "Dati valoarea nodului 'x': "; cin >> x;
				insert_after_x(ultim, new_element, x);
				n++;
				cout << endl << "Nod adaugat cu succes." << endl;
				cout << endl << "Apasa orice tasta pentru a te intoarce..." << endl;
				_getch();
				break;
			}
			default:
			{
				antet
					cout << "Optiune inexistenta." << endl;
				cout << "Apasa orice tasta pentru a te intoarce..." << endl;
				_getch();
				break;
			}
			}
			if (caz2 == 1 || caz2 == 2) //conditie necesare pentru a iesii din loop-ul infinit
				break;
		}
		break;
	}
	case 3:
	{
		antet
			int x;
		cout << "Dati valoarea nodului pe care vreti sa-l stergeti: "; cin >> x;
		remove_x(first, first, x);  //primul first este inceputul liste, al doilea de unde vrem sa incepem cautarea
		n--;
		cout << endl << "Nod sters cu succes." << endl;
		cout << endl << "Apasa orice tasta pentru a te intoarce..." << endl;
		_getch();
		break;
	}
	case 4:
	{
		int k = read(first, n, 0);      //citim din cate in cate vrem sa facem stergerea
		remove_k(first, first, n, k);  //primul first este inceputul liste, al doilea de unde vrem sa incepem cautarea, n lungimea listei
		cout << endl << "Noduri sterse cu succes." << endl;
		cout << endl << "Apasa orice tasta pentru a te intoarce..." << endl;
		_getch();
		break;
	}
	case 5:
	{
		int n2 = 0;
		lista* c2 = new lista, * first2 = c2;
		read(c2, n2, 1);           //citesc a doua lista
		first = (*first + first2); //concatenez cele 2 liste, trimitand primele 2 noduri de la fiecare lista
		n += n2;                   //actualizez lungimea noii liste
		cout << endl << "Liste concatenate cu succes." << endl;
		cout << endl << "Apasa orice tasta pentru a te intoarce..." << endl;
		_getch();
		break;
	}
	case 9:
		exit(0);


	}
	menu(first, n); //revin la meniul principal
}

int main()
{
	ifstream f("input.in");
	int n = 0;                            //lungimea listei
	lista* c = new lista, * first = c;  //c = nod curent, first = primul nod din lista
	read(c, n, 1);
	menu(first, n);
	return 0;
}