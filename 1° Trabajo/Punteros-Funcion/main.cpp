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
bool Menor(T a, T b){
    return a<b;
}
template<class T>
bool Mayor(T a, T b){
    return a>b;
}

template <class T>
void swap_p(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void crear_aroi(T *aroi, int num_elem){ ///solo int's
    srand(time(NULL));
    int numero_aleatorio;
    for(int i=0;i<num_elem;i++){
        numero_aleatorio=1+rand()%(101-1);  ///numeros entre 1-100
        *aroi=numero_aleatorio;
        aroi++;
    }
}
template <class T>
void ord_Cocktail(T *a, int n, bool (*o)( T, T ))
{                           ///ar_start=n-1 & ar_end=0 ascendente
    ///o=Menor;
    bool comp = true;
    int ar_start  = 0;          ///0
    int ar_end = n-1;           ///n-1

    while (comp == true)
    {
        comp = false;
        for (int i = ar_start ; i < ar_end; i++){
            if ((o)(*(a+i), *(a+i+1))){
                swap_p(*(a+i), *(a+i+1));
                comp = true;
            }
        }
        if (comp == false){
                break;
        }
        --ar_end;
        comp = false;
        for (int i = ar_end - 1; i >= ar_start ; i--){
            if ((o)(*(a+i), *(a+i+1))){
                swap_p(*(a+i), *(a+i+1));
                comp = true;
            }
        }
        ++ar_start ;
    }
}

template <class T>
void printArray(T *a, int n)
{
    cout << "{ ";
    for (int i=0; i<n; i++){
        cout <<*(a+i)<<" ";
    }
    cout <<"}"<<endl;
}

int main()
{
    const int numero_de_elementos = 500000;
    int *arr =NULL;
    arr= new int[numero_de_elementos];

    crear_aroi<int>(arr,numero_de_elementos); ///cantidad de elementos del Array*/
    bool (*p)(int,int);
    p=Menor;
    inicio=clock();
    ord_Cocktail<int>(arr,numero_de_elementos, p);
    fin=clock();
    double t=(double(fin-inicio)/CLOCKS_PER_SEC);
	cout << "Tiempo: " << t << " seg" << endl;

    delete[] arr;
    arr = 0;
    return 0;
}
