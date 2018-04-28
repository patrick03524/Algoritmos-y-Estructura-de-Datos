
#include <utility>
#include <iostream>
using namespace std;

class Nodo{
public:
	Nodo *next;
	int val;
};

class LinkedList{
private:
	Nodo *first;
public:

	void del(int i){

	}
	void print(){

	}
	LinkedList operator+(const LinkedList &B){

	}
	void concatenar(LinkedList B){

	}
};

LinkedList Josephus(int muertos, int soldados){
	LinkedList A;
	for (int i = 1; i <= soldados; i++)
	A.append(i);
	int ded = (muertos-1) % soldados;
	for (soldados; soldados > 2; soldados--){
	//if (soldados == 3) break;
	A.del(ded);
	ded = ded + (muertos-1);
	ded = ded % (soldados-1);
	}
	return A;
}
int main(int argc, char *argv[]) {
	LinkedList A, B;
	//LinkedList A;
	A.append(1);
	A.append(4);
	A.append(8);
	A.append(9);
	A.append(10);
	A.append(11);
	//A->append(5);
	//A->append(2);
	//A->append(4);
	A.print();
	B.append(2);
	B.append(3);
	B.append(5);
	B.append(7);
	B.append(15);
	B.append(16);
	B.append(18);
	B.print();
	//C = A + B;
	//A += B;
	A.concatenar(B);
	A.print();
	LinkedList Jos;
	Jos = Josephus(3, 40);
	cout << "Quedan los soldados: ";
	Jos.print();
	//delete A;
	return 0;
}
