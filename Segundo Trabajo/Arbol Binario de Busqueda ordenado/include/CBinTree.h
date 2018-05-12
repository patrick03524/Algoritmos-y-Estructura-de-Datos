#ifndef CBINTREE_H
#define CBINTREE_H
#include "CBinNode.h"
#include "Operator.h"
template <class T, class Op>
class CBinTree
{
    public:
        CBinTree()
        {
            m_root = 0;
        }
        /*~CBinTree()
        {

        }*/
        bool find(T x, CBinNode<T> **&p)
        {
            for(p = &m_root; *p && (*p)->C_Value != x; p = &((*p)->C_Nodes[o((*p)->C_Value, x)]));
            return !!*p;
        }
        bool insert(T x)
        {
            CBinNode<T>** p;
            if(find(x, p)) return 0;
            *p = new CBinNode<T>(x);
            return 1;
        }
        bool remove(T x)
        {
            CBinNode<T>** p;
            if(!(find(x,p))) return 0;
            if ((*p)->C_Nodes[0] && (*p)->C_Nodes[1]){
                CBinNode<T> **q = Rep(p);
                (*p)->C_Value = (*q)->C_Value;
                p = q;
            }
            CBinNode<T> *t = *p;
            *p = (*p)->C_Nodes[!((*p)->C_Nodes[0])];
            delete t;
            return 1;
        }
        void InOrder(CBinNode<T>* p)
        {
            if (!p) return;
            InOrder(p->C_Nodes[0]);
            cout << p->C_Value << " ";
            InOrder(p->C_Nodes[1]);
        }
        CBinNode<T>** Rep(CBinNode<T>** p)
        {
            srand(time(NULL));
            int a=rand()%1;
            for(p = &(*p)->C_Nodes[0]; *p && (*p)->C_Nodes[1]; p = &(*p)->C_Nodes[a]);
            return p;
        }

        CBinNode<T>* m_root;
        Op o;
};

#endif // CBINTREE_H
