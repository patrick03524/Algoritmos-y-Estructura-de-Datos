#include <iostream>
#include <Lista_enlazada_circular.h>

using namespace std;

int main(int argc, char *argv[]) {
	Lista_enlazada_circular l;

	cout <<"LISTA ENLAZADA DOBLE CIRCULAR"<<endl;
	unsigned int n, n2;
	int num,num2;
	cout <<"Ingrese cuantos elementos quiere agregar : ";
	cin >> n;
	for(unsigned int i =0; i<n; i++){
        cout<<"Ingrese un numero :";
        cin >> num;
        cout <<" "<<endl;
        l.append(num);
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
        l.del(num2);
        cout <<"List : ";
        l.print();
        cout <<" "<<endl;
	}
	return 0;
}
