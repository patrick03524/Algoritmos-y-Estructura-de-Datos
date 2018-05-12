#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

unsigned long inicio,fin,t;

template <class T>
void swap_p(T &a, T &b);

template <class T>
void crear_aroi(T *aroi, int num_elem);

template <class T>
void ord_Cocktail(T *a, int n);

template <class T>
void printArray(T *a, int n);

template<class T>
struct CMenor{
    inline bool operator()(T a, T b){return a>b;}
};
template<class T>
struct CMayor{
    inline bool operator()(T a, T b){return a<b;}
};

template <class T>
void swap_p(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <class T>
void crear_aroi(T *aroi, int num_elem){ ///solo int's
    srand(time(NULL));
    int numero_aleatorio;
    int *lim = aroi + num_elem;
    for(;aroi<lim;aroi++){
        numero_aleatorio=1+rand()%(101-1);  ///numeros entre 1-100
        *aroi=numero_aleatorio;
    }
}

template <class T, class Op>
void ord_Cocktail(T *a, int n)
{                           ///ar_start=n-1 & ar_end=0 ascendente
    Op o;
    bool comp = true;
    int *ar_start  = a;
    int *ar_end = a+n-1;

    while (comp == true)
    {
        comp = false;
        for (int *i = ar_start ; i < ar_end; i++){
            if (o(*(i), *(i+1))){
                swap_p((i), (i+1));
                comp = true;
            }
        }
        if (comp == false){
                break;
        }
        --ar_end;
        comp = false;
        for (int *i = ar_end - 1; i >= ar_start ; i--){
            if (o(*(i), *(i+1))){
                swap_p((i), (i+1));
                comp = true;
            }
        }
        ++ar_start ;
    }
}
template <class T>
void printArray(T *a, int n)
{
    int *cont = a+n;
    cout << "{ ";
    for (; a<cont; a++){
        cout <<*a<<" ";
    }
    cout <<"}"<<endl;
}

int main()
{
    const int numero_de_elementos = 10;
    int *arr =NULL;
    arr= new int[numero_de_elementos];

    crear_aroi<int>(arr,numero_de_elementos); ///cantidad de elementos del Array*/
    cout <<"Array Ingresado :";
    printArray<int>(arr,numero_de_elementos);
    ord_Cocktail<int, CMenor<int> >(arr,numero_de_elementos);
    /*inicio=clock();
    ord_Cocktail<int, CMenor<int> >(arr,numero_de_elementos);
    fin=clock();
    double t=(double(fin-inicio)/CLOCKS_PER_SEC);
	cout << "Tiempo: " << t << " seg" << endl;*/
	cout <<"Array Ordenado :";
    printArray<int>(arr,numero_de_elementos);

    delete[] arr;
    arr = 0;
    return 0;
}
