#include "Lista_enlazada.h"

Lista_enlazada::Lista_enlazada()
{
    this->first = NULL;
}
void Lista_enlazada::append(int value)
{
    nodo *element = new nodo;
	element->val = value;
	if (first == NULL){
        first = element;
        element->next = NULL;
	} else {
        nodo *n_1;
        n_1 = first;
        while (n_1->next != NULL && n_1->next->val < value){
            n_1 = n_1->next;
        }
        if (n_1->next == NULL && n_1->val < value){
            n_1->next = element;
            element->next = NULL;
        } else if (n_1->val > value){
            element->next = n_1;
            this->first = element;
        } else {
            element->next = n_1->next;
            n_1->next = element;
        }
	}
}
void Lista_enlazada::borrar(int i)
{
    nodo* n_1;
	nodo* prev;
	n_1 = this->first;
	prev = n_1;
	n_1 = n_1->next;
	int j = 1;
	if (i == NULL){
        prev->next = NULL;
        this->first = n_1;
        cout << "Borrado: " << prev->val << endl;
	} else {
        while(j < i && n_1->next != NULL){
            n_1 = n_1->next;
            prev = prev->next;
            j++;
        }
        if (n_1->next == NULL){
            prev->next = NULL;
        } else {
            prev->next = n_1->next;
            n_1->next = NULL;
        }
        cout << "Borrado: " << n_1->val << endl;
        delete n_1;
        }
}
void Lista_enlazada::print()
{
    nodo *n_1;
	n_1 = this->first;
	while (n_1 != NULL){
        cout << n_1->val << " ";
        n_1 = n_1->next;
	}
	cout << endl;
}
/*
Lista_enlazada:: operator+(const Lista_enlazada &B)  //Borrar
{
    Lista_enlazada C;
	nodo *n_1;
	n_1 = this->first;
	while (n_1->next != NULL){
	C.append(n_1->val);
	n_1 = n_1->next;
	}
	C.append(n_1->val);
	n_1 = B.first;
	while (n_1->next != NULL){
	C.append(n_1->val);
	n_1 = n_1->next;
	}
	C.append(n_1->val);
	return C;
}*/
void Lista_enlazada::concatenar(Lista_enlazada B)
{
    nodo *n_1;
	nodo *n_2;
	nodo *temp; //apunta a n_2 para guardar el nodo y no perder el enlace
	nodo *temp2; //apunta a n_1 para guarda el nodo y no perder el enlace
	n_1 = this->first;
	n_2 = B.first;
	if (n_1->val > n_2->val){ //si n_2 es menor, el primer nodo de n_2 se vuelve el primero de la lista
        this->first = n_2;
        temp = n_2->next;
        n_2->next = n_1;
        n_2 = temp; //anterior next antes de apuntar al anterior
	} else temp = n_2;
        while(n_1->next != NULL && n_2->next != NULL){
            if (n_1->val < n_2-> val){
                temp2 = n_1->next;
                if(n_1->next->val < n_2->val){
                    n_1 = n_1->next;
                } else {
                    n_1->next = n_2;
                    n_1 = temp2;
                }
            } else {
                temp = temp->next;
                if(n_2->next->val < n_1->val){
                    n_2 = n_2->next;
                } else {
                    n_2->next = n_1;
                    n_2 = temp;
                }
            }
        }
	//Completando la lista antes de llegar a Nulo
	if(n_1->next == NULL){
        n_1->next = n_2;
    } else {
        n_2->next = n_1;
	}
    while(n_1 != NULL){
        n_1 = n_1->next;
    }
    while(n_2 != NULL){
        n_2 = n_2->next;
    }
}
