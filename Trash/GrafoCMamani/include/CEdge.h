#ifndef CEDGE_H
#define CEDGE_H
#include "CNode.h"

template <class G>
class CEdge
{
    public:
        typedef typename G :: E E;
        typedef typename G :: N N;

        CEdge(N data, bool dir){
            e_data = data;
            e_dir = dir;
            e_nodes[0] = e_nodes[1] = 0;
            e_visit = false;
        }
        N e_data;
        CNode<N> e_nodes[2];
        bool e_dir;     ///0 bidirrecional; 1 derecha

        bool e_visit;


};

#endif // CEDGE_H
