#ifndef LISTA_ENLAZADA_CIRCULAR_H
#define LISTA_ENLAZADA_CIRCULAR_H
#include "Node.h"
#include "Operator.h"

template <class T, class Op>
class Lista_Enlazada_Circular
{
    public:
        Lista_Enlazada_Circular()
        {
            L_Head = 0;
        }
        Node<T> *L_Head;
        Node<T> *L_Tail;
        Op o;
        bool find(T x, Node<T> *&p)
        {
            p = L_Head;
            if(L_Head ->N_Value == x) return 1; ///Case Head
            for(p = L_Head->N_Next; p != L_Head && o(p->N_Value, x);p = p->N_Next);
            return (p->N_Value==x);
            /*for(p = &L_Head; (*p)->L_Head != (*p)->L_Head && o((*p)->N_Value,x); p = &((*p)->N_Next));
            return (*p)&&(*p)->N_Value==x;*/
        }
        bool insert(T x)
        {
            if(!L_Head){
                L_Head = new Node<T>(x);
                L_Head -> N_Next = L_Head->N_Prev = L_Head;
                return 1;
            }
            if(o(x,L_Head->N_Value)){
                Node<T> *t = new Node<T> (x,L_Head,L_Head->N_Prev);
                L_Head->N_Prev->N_Next = t;
                L_Head = t;
                return 1;
            }
            Node<T> *p;
            if(find(x,p))return 0;
            Node<T> *t = new Node<T> (x,p, p->N_Prev);
            p->N_Prev->N_Next = t;
            p->N_Prev = t;
            return 1;
            /*Node<T> **p;
            if(find(x,p))return 0;
            Node<T>*t = new Node<T>(x);
            t -> N_Next = *p;
            t -> N_Prev = (*p) ->N_Prev;
            *p = t;
            return 1;*/
        }
        bool remove(T x)
        {
            Node<T> *p;
            ///if(!L_Head)return 0;
            if(!find(x,p))return 0;
            if(p == L_Head){
                L_Head->N_Prev->N_Next = L_Head -> N_Next;
                L_Head->N_Next->N_Prev = L_Head->N_Prev;
                L_Head = L_Head->N_Next;
                delete p;
                return 1;
            }
            Node<T> *t = p;
            p->N_Prev->N_Next = p->N_Next;
            t->N_Next->N_Prev = p->N_Prev;
            delete t;
            return 1;
        }
        bool print()
        {
            Node<T> *p = L_Head;
            cout <<p->N_Value<<" ";
            p = p->N_Next;
            while(p !=L_Head){
                cout <<p->N_Value<<" ";
                p = p->N_Next;
            }
        }
};

#endif // LISTA_ENLAZADA_CIRCULAR_H
