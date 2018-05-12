#ifndef CBINNODE_H
#define CBINNODE_H

template<class T>
class CBinNode
{
    public:
        CBinNode(T x)
        {
            C_Value = x;
            C_Nodes[0] = C_Nodes[1] = 0;
        }
        CBinNode(T x, CBinNode<T> *CBinA, CBinNode<T> *CBinB)
        {
            C_Value = x;
            C_Nodes[0] = CBinA;
            C_Nodes[1] = CBinB;
        }
        CBinNode(CBinNode<T> &new_Node)
        {
            C_Value = new_Node->C_Value;
            C_Nodes[0] = new_Node->C_Nodes[0];
            C_Nodes[1] = new_Node->C_Nodes[1];
        }

        T C_Value;
        CBinNode<T> *C_Nodes[2];

};

#endif // CBINNODE_H
