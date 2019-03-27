Liste de numere întregi (implementate dinamic)  



Se dau urmatoarele clase:  
- Nod {char info, nod*next}  
- Nod_dublu:Nod {nod * ante;};  
- Nod_prioritate:Nod_dublu {int prio;}  
- ListaSimpluInlantuita  
- ListaDubluInlantuita : ListaSimpluInlantuita  
- CoadaDePrioritati : ListaDubluInlantuita  

ListaSimpluInlantuita trebuie sa foloseasca elemente de tip Nod.  
ListaDubluInlantuita trebuie sa foloseasca elemente de tip Nod_dublu si  
Clasa Coada_prioritati sa aibă elemente de tip Nod_prioritate.   
Clasele derivate trebuie sa contina cel puțin constructori parametrizati  
prin care sa se evidentieze transmiterea parametrilor către

Fiecare clasa trebuie sa aibe: 
 - metode de: introducere a unui element (unde alege programatorul)  
 - supraincarcare a operatorului >>, realizata prin introduceri succesive  
 - supraincarcare a operatorului <<; pentru afisarea listei;  
 - stergere a unui element (de unde alege programatorul)  
 - eliminare a elementelor din k in k, unde k este un numar natural nenul citit  
de la tastatura sau dintr-un fisier, pana ce in lista ramane un singur element  
 - supraincarcare a operatorului +, care sa efectueze concatenarea a doua liste circulare de intregi,  
prin ruperea cate unei legaturi a fiecareia si legarea celor doua liste in locurile  
legaturilor rupte  
