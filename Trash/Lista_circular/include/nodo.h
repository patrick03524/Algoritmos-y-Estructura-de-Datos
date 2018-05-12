#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;
template <class T>
class nodo
{
    public:
        nodo<T> *next;
        nodo<T> *prev;
        T N_Value;
        nodo(T value)
        {
            N_Value = value;
            next = prev = 0;
        }
        nodo(T value, nodo<T> *n, nodo<T> *p)
        {
            N_Value = value;
            next = n;
            prev = p;
        }
        nodo(nodo<T> new_nodo)
        {
            N_Value = new_nodo->N_Value;
            next = new_nodo->next;
            prev = new_nodo->prev;
        }

};

#endif // NODO_H
