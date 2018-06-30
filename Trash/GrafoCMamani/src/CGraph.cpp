#include "CGraph.h"
template<class N, class E>
bool CGraph<N,E>::find(N dato, int &indice)
{
    for(indice = 0; indice < g_nodes.size(); indice++){
        if(g_nodes[indice]->m_data == dato){return 1;}
    }
    return 0;
}
template<class N, class E>
bool CGraph<N,E>::insertNode(N dato)
{
    int i;
    if(find(dato, i))return 0;
    CNode<Self>* temp = new CNode<Self>(dato);
    g_nodes.push_back(temp);
    return 1;

}
template<class N, class E>
bool CGraph<N,E>::insertEgde(Node *&A, Node *&B, E dato, bool dir)
{
    CEdge<Self>* temp = new CEdge<Self>(dato, dir);
    A->m_edges.push_back(temp);
    B->m_edges.push_back(temp);
    temp->e_nodes[0] = A;
    temp->e_nodes[1] = B;
    return 1;
}
template<class N, class E>
bool CGraph<N,E>::removeEdge(Node *A, Node *B, E dato)
{
    int ind1, ind2;
    if(!(find(A->m_data,ind1) && find(B->m_data,ind2))){
        cout <<"Error al parametrizar Aristas"<<endl;
        return 0;
    }

    /*for(iterator it = A.m_edges.begin(); it !=A.m_edges.end(); it++){
        for(iterator it2 = B.m_edges.begin(); it2 !=B.m_edges.end(); it2++){

        }
    }*/
    /*
    for(vector<Node*> iterator = A.m_edges.begin(); iterator != A.m_edges.end(); iterator++){
        if(*iterator == dato){
           A.m_edges.remove(*iterator);
           delete *iterator;
        }
    }
    for(vector<Node *> iterator = B.m_edges.begin(); iterator != B.m_edges.end(); iterator++){
        if(*iterator == dato){
           B.m_edges.remove(*iterator);
           delete *iterator;
        }
    }*/

    for(int i = 0; i<A.m_edges.size(); i++){
        if(*A.m_edges[i]->e_data == dato){
            delete *A.m_edges[i];
            break;
        }
    }
    for(int i = 0; i<B.m_edges.size(); i++){
        if(*B.m_edges[i]->e_data == dato){
            delete *B.m_edges[i];
            break;
            return 1;
        }
    }
    return 0;
}
template<class N, class E>
bool CGraph<N,E>::removeNode(Node *A)
{
    int ind1;
    if(!(find(A->m_data,ind1))){return 0;}
    CEdge<Self> *temp;
    while(!A->m_edges[ind1].empty()){
        ///temp = A->m_edges[ind1].front();
        (temp->e_nodes[0]->m_edges).remove(temp);
        (temp->e_nodes[1]->m_edges).remove(temp);
    }
    g_nodes.erase(g_nodes.begin()+ind1);
    delete g_nodes[ind1];
    return 1;
}
template<class N, class E>
void CGraph::printCGraph()
{
    cout <<"Grafo CMamani"<<endl;
    cout <<"Nodos"<<endl;
    for(int i = 0, i < g_nodes.size();i++){
        CNode<Self>* temp = g_nodes[i];
        cout <<"Node :"<<temp->m_data;
        /*for(typename vector<Edge *> iterator it = temp->m_edges.begin(); it != temp->m_edges.end(); it++){
            if(temp->m_data != (*it)->e_nodes[1]->e_data){
                cout <<" --> " << (*it)->e_data;
                cout <<" "<<endl;
            }
        }*/
    }
    cout <<" "<<endl;
    cout <<"Aristas"<<endl;
    for(int i = 0, i < g_nodes.size();i++){
        CNode<Self>* temp = g_nodes[i];
        for(int j = 0; j < temp->m_edges.size(); j++){
            cout <<temp->m_edges[j]->e_nodes[0]->m_data<<" -"<<temp->m_edges[j]->e_data<<"-> "<<temp->m_edges[j]->e_nodes[1]->m_data<<endl;
        }
    }
    cout <<" "<<endl;
}
/*
inline int distancia(CBigGraph::Node* a , CBigGraph::Node* b) {
    return pow(a->value.x() - b->value.x(), 2) + pow(a->value.y() - b->value.y(), 2);
}



inline bool MenorDestino(CBigGraph::Edge* &a, CBigGraph::Edge * &b) {
    //Rutina necesaria para sort de lista de Edge* Menor distancia euclid a nodo destino
    int dist_a, dist_b;

    CBigGraph::Node* nodo_a = (a->enodo[0] != ACTUAL) ? a->enodo[0] : a->enodo[1];
    CBigGraph::Node* nodo_b = (b->enodo[0] != ACTUAL) ? b->enodo[0] : b->enodo[1];

    dist_a = distancia(nodo_a, FINAL);
    dist_b = distancia(nodo_b, FINAL);

    if (dist_a < dist_b) {
        return true;
    }
    return false;
}
inline bool CBigGraph::dijkstra(Node* A, Node* B, list<Node*> &ruta) {
    Node* actual = A;
    //list<Node*> ruta;
    ruta.push_back(A);
    FINAL = B;

    int i = 0; //iteracion de busqueda
               //inicio->d_visitado = true;
    A->d_dist = 0;

    while (actual != B) {
        ACTUAL = actual;
        if (!actual->d_visitado) {
            actual->d_visitado = true;
            actual->EdgeNod.sort(MenorDestino);
            //actual->edges.sort();
        }
        //list<Edge*> busqueda; // busqueda de la menor arista no usada
        Node* next = nullptr; //siguiente nodo en la ruta
        list<Edge*>::iterator it = actual->EdgeNod.begin();

        while (it != actual->EdgeNod.end()) {
            if (!(*it)->utilizado) {
                //actualizar distancia a origen
                Node* check = ((*it)->enodo[0] != actual) ? (*it)->enodo[0] : (*it)->enodo[1];
                if (!check->d_visitado) {
                    if (!next) {// next es nullpointer aun no asignado
                        next = check;
                    }
                    if (check->d_dist < 0 || check->d_dist > actual->d_dist + (*it)->value) {
                        check->d_dist = actual->d_dist + (*it)->value;
                        check->nodo_ant = actual;
                    }

                }
                cout << "";
            }
            it++;
        }
        if (next)
        {
            actual = next;
            ruta.push_back(actual);
            //i++;// TODO si no existe next debemos corregir la ruta
        }
        else
        {
            if (ruta.size() > 1)
            {
                ruta.pop_back();
                actual = ruta.back();
                //i++;
            }
            else
            {
                return false;
            }
        }
        //i++;
    }

    return true;
}
*/
