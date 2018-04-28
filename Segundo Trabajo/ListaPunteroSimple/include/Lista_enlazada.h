#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H
#include <nodo.h>


class Lista_enlazada
{
    public:
        nodo *first;
        Lista_enlazada();
        void append(int);
        void borrar(int);
        void print();
        //Lista_enlazada operator+(const Lista_enlazada &B); operador +
        void concatenar(Lista_enlazada B);
};

#endif // LISTA_ENLAZADA_H
