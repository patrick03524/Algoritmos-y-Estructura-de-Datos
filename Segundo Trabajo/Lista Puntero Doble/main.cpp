#include <iostream>

using namespace std;

template <class T>
struct CLess{
    inline bool operator()(T a, T b){return a<b;}
} ;

template <class T>
struct CGreater{
    inline bool operator()(T a, T b){return a>b;}
} ;

template <class T>
struct Node{
	Node(T x)
	{
		m_x=x;
		m_next=0;
	};
	T m_x;
	Node<T>* m_next;
};

template<class T, class Op>
class Lista{
public:
	Lista(){
		m_head=0;
	}
	~Lista(){

	}
	bool find(T x, Node<T>**&p);
	bool insert(T x);
	bool remove(T x);
	bool print();

	Node<T>*m_head;
	Op m_op;
};

template<class T, class Op>
bool Lista<T,Op>::find(T x, Node<T>**&p){
    Op o;
	for(p=&m_head; *p && m_op((*p)->m_x, x); p=&((*p)->m_next));
		return (*p)&&(*p)->m_x==x;
}

template<class T,class Op>
bool Lista<T,Op>::insert(T x){
	Node<T>**p;
	if(find(x,p))return 0;
	Node<T>*t = new Node<T>(x);
	t->m_next=*p;
	*p=t;
	return 1;
}

template<class T,class Op>
bool Lista<T,Op>::remove(T x){
	Node<T>**p;
	if(!find(x,p))return 0;
	Node<T>* t=*p;
	*p=t-> m_next;
	delete t;
	return 1;
}

template<class T,class Op>
bool Lista<T,Op>::print(){
	Node<T>**p = &m_head;
	while(*p){
		cout<<(*p)->m_x<<' ';
		p=&((*p)->m_next);
	}
	return 1;
}

int main() {
	Lista<int,CLess<int> > l;
	/*l.insert(1);
	l.print();
	cout <<" "<<endl;
	l.insert(1);
	l.print();
	cout <<" "<<endl;
	l.insert(3);
	l.print();
	cout <<" "<<endl;
	l.insert(1);
	l.print();
	cout <<" "<<endl;*/
	cout <<"LISTA ENLAZADA DOBLE PUNTERO"<<endl;
	unsigned int n, n2;
	int num,num2;
	cout <<"Ingrese cuantos elementos quiere agregar : ";
	cin >> n;
	///cout <<" "<<endl;
	for(unsigned int i =0; i<n; i++){
        cout<<"Ingrese un numero :";
        cin >> num;
        cout <<" "<<endl;
        l.insert(num);
        cout <<"List : ";
        l.print();
        cout <<" "<<endl;
	}
	cout <<"Ingrese cuantos elementos quiere eliminar : ";
	cin >> n2;
	for(unsigned int i =0; i<n2; i++){
        cout<<"Ingrese un numero :";
        cin >> num2;
        cout <<" "<<endl;
        l.remove(num2);
        cout <<"List : ";
        l.print();
        cout <<" "<<endl;
	}
	return 0;
}
