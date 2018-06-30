#ifndef CNODE_H
#define CNODE_H
///#include "Lista.h"
#include "Func.h"
template<class G>
class CNode
{
    public:
        typedef typename G :: Edge Edge;
        typedef typename G :: N N;
        typedef typename G :: E E;

        CNode(N data){
            m_data = data;
            m_dist = -1;
            m_vist = false;
            m_prev = NULL;
        }

        N m_data;
        ///Lista<int,CLess<int> > m_edges;
        vector<Edge *> m_edges;
        E m_dist;
        bool m_vist;
        CNode<G> m_prev;

};

#endif // CNODE_H
