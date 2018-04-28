#include <Lista_enlazada.h>

int main ()
{
    Lista_enlazada A;
    A.print();
	A.append(1);
	A.print();
	A.append(4);
	A.print();
	A.append(9);
	A.print();
	A.append(24);
	A.print();
	A.append(10);
	A.print();
	A.append(8);
	A.print();
	A.borrar(24);
	A.print();
	A.borrar(10);
	A.print();
	//C = A + B;
	//A += B;

	///delete A;
	return 0;
}
