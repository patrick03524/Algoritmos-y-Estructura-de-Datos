#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void crear_aroi(int *aroi, int num_elem){
    srand(time(NULL));
    int numero_aleatorio;
    for(int i=0;i<num_elem;i++){
        numero_aleatorio=1+rand()%(101-1);  ///numeros entre 1-100
        *aroi=numero_aleatorio;
        aroi++;
    }
}

void swap_p(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

class BubbleSortOp
{
public:
    inline bool operator()(int a, int b){
        if(a>b){
            return true;}
        else
            return false;
    }
};

void BubbleSort(int tam, int *aroi){
    bool num_a_comp;
    for(int i = 0; i<tam; i++){
        for (int j = 1;j<tam; j++){
            num_a_comp= BubbleSortOp(*(aroi),*(aroi+1));
            if(num_a_comp==true){
                swap(*(aroi),*(aroi+1));
            }
            aroi++;
        }
    }
    cout <<"Aroi Ordena3"<<endl;
}

int main()
{
    cout << "Cuack!" << endl;
    int numero_de_elementos = 1000;
    int arr[numero_de_elementos];
    crear_aroi(arr,numero_de_elementos); ///cantidad de elementos del Array
    int n = sizeof(arr)/ sizeof(arr[0]);
    int *p = arr;
    BubbleSort(numero_de_elementos,p);
    return 0;
}

/*
#include <iostream>
inline void mi_funcion()
{
    std::cout << "me gustan los tapires" << std::endl;
}
class mi_estructura_t
{
protected:
    int x;
public:
    mi_estructura_t(int x0):x(x0){}
    inline int get_x() const{ return x; }
};
int main()
{
    mi_funcion();
    mi_estructura_t s(7);
    std::cout << s.get_x() << std::endl;
    return 0;
}*/
