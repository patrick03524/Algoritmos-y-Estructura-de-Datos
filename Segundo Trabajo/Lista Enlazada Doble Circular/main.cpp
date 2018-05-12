/*#include <iostream>
using namespace std;
*/
#include "Lista_Enlazada_Circular.h"
int main()
{
    Lista_Enlazada_Circular<int,CLess<int> > l;
	cout <<"LISTA ENLAZADA DOBLE CIRCULAR"<<endl;
	unsigned int n, n2;
	int num,num2;
	cout <<"Ingrese cuantos elementos quiere agregar : ";
	cin >> n;
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
}
