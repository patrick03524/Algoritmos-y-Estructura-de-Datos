#include "Lista_enlazada_circular.h"

Lista_enlazada_circular::Lista_enlazada_circular()
{
    this->first = NULL;
}

void Lista_enlazada_circular::append(int value){
    nodo *element = new nodo;
    element->val = value;
    if (first == NULL){
        this->first = element;
        element->next = this->first;
    } else {
        nodo *n_1;
        n_1 = this->first;
        n_1 = n_1->next;
        while (n_1->next != this->first && n_1->next->val < value){
            n_1 = n_1->next;
        }
        if (n_1->next == this->first && n_1->val < value){
            n_1->next = element;
            element->next = this->first;
        } else if (n_1->val > value){
            element->next = n_1;
            n_1 = n_1->next;
            while(n_1->next != this->first)
                n_1 = n_1->next;
                n_1->next = element;
                this->first = element;
        } else {
            element->next = n_1->next;
            n_1->next = element;
        }
    }
}
void Lista_enlazada_circular::del(int i){
		nodo* n_1;
		nodo* prev;
		n_1 = this->first;
		prev = n_1;
		n_1 = n_1->next;
		if (i == 0){
			while (n_1->next != this->first){
				n_1 = n_1->next;
			}
			prev = prev->next;
			n_1->next = prev;
			this->first->next = NULL;
			this->first = prev;
		} else {
			for(int j = 1; j < i; j++){
				n_1 = n_1->next;
				prev = prev->next;
			}
			prev->next = n_1->next;
			n_1->next = NULL;
			this->first = prev->next;

		}
	}
void Lista_enlazada_circular::print(){
		nodo *n_1;
		n_1 = this->first;
		cout << n_1->val << " ";
		n_1 = n_1->next;
		while (n_1 != this->first){
			cout << n_1->val << " ";
			n_1 = n_1->next;
		}
		cout << endl;
	}
