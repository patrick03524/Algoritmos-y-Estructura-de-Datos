#include "CBinTree.h"
int main()
{
    ///cout << "IM NEVER ALONE, IM ALONE ALL THE TIME!" << endl;
    CBinTree <int, CLess<int> > t;
    cout <<"ARBOL BINARIO PAPO"<<endl;
    unsigned int n, n2;
	int num,num2;
	cout <<"Ingrese cuantos elementos quiere agregar : ";
	cin >> n;
	for(unsigned int i =0; i<n; i++){
        cout<<"Ingrese un numero :";
        cin >> num;
        cout <<" "<<endl;
        t.insert(num);
        cout <<"ARBOL - IN ORDER : ";
        t.InOrder(t.m_root);
        cout <<" "<<endl;
	}
	cout <<"Ingrese cuantos elementos quiere eliminar : ";
	cin >> n2;
	for(unsigned int i =0; i<n2; i++){
        cout<<"Ingrese un numero :";
        cin >> num2;
        cout <<" "<<endl;
        t.remove(num2);
        cout <<"ARBOL - IN ORDER : ";
        t.InOrder(t.m_root);
        cout <<" "<<endl;
	}

    return 0;
}
