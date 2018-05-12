#include <iostream>
#include <Lista_enlazada_circular.h>
using namespace std;


Lista_enlazada_circular Josephus(int muertos, int soldados){
	Lista_enlazada_circular A;
	for (int i = 0; i < soldados; i++)
		A.append(i);
	int sold_dead = muertos-1;
	for (soldados; soldados > 2; soldados--){
		if (soldados == 3)
            break;
		A.del(sold_dead);
		sold_dead = sold_dead + (muertos-1);
		cout << "soldado muerto: " << sold_dead << endl;
		cout << "soldados: " << soldados-1 << endl;
		sold_dead = sold_dead % (soldados-1);
		cout << "soldados muertos mod soldados: " << sold_dead << endl;
	}
	return A;
}

int main(int argc, char *argv[]) {
	Lista_enlazada_circular jos;
	jos.append(1);
	jos.print();
	jos.append(3);
	jos.print();
	jos.append(5);
	jos.print();
	jos = Josephus(3, 9);
	jos.print();
	return 0;
}
