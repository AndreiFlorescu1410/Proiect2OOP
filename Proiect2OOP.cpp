#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include "CoadaDePrioritati.h"
using namespace std;

#define antet {system("CLS");cout<<"       Proiect 1 OOP -- liste circulare(alocate dinamic) -- Florescu Andrei Gr. 212         "<<endl<<endl;}



void remove_k(ListaSimpluInlantuita* &lista, int& n, int k, int tip_lista) //argumente similare cu 'remove_x', insa, in loc de valoarea x, avem distanta dintre elemente si numarul de elemente din lista
{
	Nod* nod, *after_nod;
	if (tip_lista == 1)
	{
		nod = new Nod;
		after_nod = new Nod;
	}
	else if (tip_lista == 2)
	{
		nod = new Nod_Dublu;
		after_nod = new Nod_Dublu;
	}
	else
	{
		Nod_Prioritate* nod, *after_nod;
	}
	nod = lista->GetFirst();
	while (n > 1) //cat timp mai sunt noduri de sters
	{
		for (int i = 0; i < k - 1; i++)  //avansez k noduri
		{
			if (nod == lista->GetLast())
				nod = lista->GetFirst();
			else
				nod = nod->GetNext();
		}
		if (nod == lista->GetLast())
			after_nod = lista->GetFirst();
		else
			after_nod = nod->GetNext();
		lista->remove_x(nod->GetI()); //sterg nodul curent
		n--;
		nod = after_nod;
	}

}
int read(ListaSimpluInlantuita *& lista, int& n, int reading_list) //meniul de citire. Foloesesc reading_list sa stiu daca citesc lista sau elementul 'k'
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
					Nod* new_element;
					if (reading_list == 1)
					{
						lista = new ListaSimpluInlantuita;
						new_element = new Nod();
					}
					else if (reading_list == 2)
					{
						lista = new ListaDubluInlantuita;
						new_element = new Nod_Dublu();
					}
					else
					{
						lista = new CoadaDePrioritati;
						new_element = new Nod_Prioritate();
					}
					lista->SetCurrentNod(new_element);
					while (f >> new_element)					//citesc valoarea nodului
					{
						lista->insert_after_x(new_element, lista->GetCurrentNod()->GetI());
						lista->SetCurrentNod(new_element);		//il adaug la "finalul" listei      
						lista->SetLast(new_element);
						cout << lista->GetCurrentNod();
						Nod* temp = new Nod;
						new_element = temp;
						delete new_element;
						if (reading_list == 1)
							new_element = new Nod;
						else if (reading_list == 2)
							new_element = new Nod_Dublu;
						else
							new_element = new Nod_Prioritate;
						n++;									//incrementez numarul nodurilor din lista
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
				if (reading_list >= 1)
				{
					cout << "Dati numarul de elemente din lista: ";
					cin >> n;
					cout << "Dati elementele listei: ";
					Nod* new_element;
					if (reading_list == 1)
					{
						lista = new ListaSimpluInlantuita;
						new_element = new Nod;
					}
					else if (reading_list == 2)
					{
						lista = new ListaDubluInlantuita;
						new_element = new Nod_Dublu;
					}
					else
					{
						lista = new CoadaDePrioritati;
						new_element = new Nod_Prioritate;
					}
					for (int i = 0; i < n; i++)
					{
						cin >> new_element;           //citesc valoarea nodului
						lista->insert_after_x(new_element, lista->GetCurrentNod()->GetI());
						lista->SetCurrentNod(new_element);		//il adaug la "finalul" listei      
						lista->SetLast(new_element);
						cout << lista->GetCurrentNod();
						Nod* temp = new Nod;
						new_element = temp;
						delete new_element;
						if (reading_list == 1)
							new_element = new Nod;
						else if (reading_list == 2)
							new_element = new Nod_Dublu;
						else
							new_element = new Nod_Prioritate;
					}
					lista->SetLast(new_element);
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
		read(lista, n, (reading_list == 1) ? 1 : 0); //ma reintorc la meniul principal
		break;
	}
	}
	if (reading_list == 1)
		return 0;
	else
		return k;
}

void afisare(Nod* first, int n) //afiseaz lista care incepe de la nodul "first"
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




void menu(ListaSimpluInlantuita*& lista, int n, int tip_lista) //meniul principal al programului
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
		afisare(lista->GetFirst(), n);
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
			Nod* new_element = new Nod;
			if (tip_lista == 1)
				new_element == new Nod;
			else if (tip_lista == 2)
				new_element == new Nod_Dublu;
			else
				new_element = new Nod_Prioritate;

			antet
			cout << "Dati valoarea noului nod: "; 
			cin >> new_element; //citesc noul nod, inainte de a intra in switch, pentru a economisi memorie

			switch (caz2)
			{
			case 1:
			{
				lista->insert_after_x(new_element, -1);
				lista->SetLast(new_element);
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
				lista->insert_after_x(new_element, x);
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
		lista->remove_x(x);
		n--;
		cout << endl << "Nod sters cu succes." << endl;
		cout << endl << "Apasa orice tasta pentru a te intoarce..." << endl;
		_getch();
		break;
	}
	case 4:
	{
		int k = read(lista, n, 0);      //citim din cate in cate vrem sa facem stergerea
		remove_k(lista, n, k, tip_lista);  //primul first este inceputul liste, al doilea de unde vrem sa incepem cautarea, n lungimea listei
		cout << endl << "Noduri sterse cu succes." << endl;
		cout << endl << "Apasa orice tasta pentru a te intoarce..." << endl;
		_getch();
		break;
	}
	case 5:
	{
		int n2 = 0,tip_lista2;
		antet
		cout << "Dati tipul de lista(1-lista simpla, 2-lista dubla, 3-coada de prioritati): ";
		cin >> tip_lista2;
		ListaSimpluInlantuita* lista2;
		if (tip_lista2 == 1)
			lista2 = new ListaSimpluInlantuita;
		else if (tip_lista2 == 2)
			lista2 = new ListaDubluInlantuita;
		else
			lista2 = new CoadaDePrioritati;
		read(lista2, n2, tip_lista2);           //citesc a doua lista
		lista->GetLast()->SetNext(lista2->GetFirst());
		lista->SetLast(lista2->GetLast());
		n += n2;                   //actualizez lungimea noii liste
		cout << endl << "Liste concatenate cu succes." << endl;
		cout << endl << "Apasa orice tasta pentru a te intoarce..." << endl;
		_getch();
		break;
	}
	case 9:
		exit(0);


	}
	menu(lista, n,tip_lista); //revin la meniul principal
}

int main()
{
	ifstream f("input.in");
	int n = 0, tip_lista;                            //lungimea listei
	ListaSimpluInlantuita* lista;
	antet
	cout << "Dati tipul listei: "; cin >> tip_lista;
	read(lista, n, tip_lista);
	menu(lista,n,tip_lista);
	return 0;
}