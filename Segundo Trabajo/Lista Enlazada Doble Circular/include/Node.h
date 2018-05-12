#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    public:
        Node(T value)
        {
            N_Value = value;
            N_Next = N_Prev = 0;
        }
        Node(T value, Node<T> *n, Node<T> *p)
        {
            N_Value = value;
            N_Next = n;
            N_Prev = p;
        }
        Node(Node<T> &new_Node)
        {
            N_Value = new_Node->N_Value;
            N_Next = new_Node->N_Next;
            N_Prev = new_Node->N_Prev;
        }
        Node<T> *N_Next;
        Node<T> *N_Prev;
        T N_Value;
};

#endif // NODE_H
