#include <iostream>
#include<stdlib.h>
#include<time.h>

unsigned long inicio,fin,t;
///faltan new y pointos :v
using namespace std;

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

template<class T>
void borrar_aroi(T *aroi, int num_elem){
    for(int i=0; i< num_elem; i++){
        delete aroi;
    }
    aroi = 0;
    cout <<"aroi borra3"<<endl;
}

template <class T>
void swap_p(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void ord_Cocktail(T *a, int n)
{                           ///ar_start=n-1 & ar_end=0 ascendente
    bool comp = true;
    int ar_start  = 0;          ///0
    int ar_end = n-1;           ///n-1

    while (comp == true)
    {
        comp = false;
        for (int i = ar_start ; i < ar_end; i++){
            if (*(a+i) > *(a+i+1)){
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
            if (*(a+i) > *(a+i+1)){
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
    const int numero_de_elementos = 1000;
    ///int *aroi = NULL;
    int *arr =NULL;
    arr= new int[numero_de_elementos];

    crear_aroi<int>(arr,numero_de_elementos); ///cantidad de elementos del Array*/
    ///int arr[] = {6,8,1,3,4,2,5,10,9,7};
    ///int arr[] = {1,2,3,4,5,6};
    ///int n = sizeof(arr)/ sizeof(arr[0]);
    ///int *p = arr;
    /*cout <<"Array Ingresado :";
    printArray<int>(arr,numero_de_elementos);*/
    inicio=clock();
    ord_Cocktail<int>(arr,numero_de_elementos);
    fin=clock();
    double t=(double(fin-inicio)/CLOCKS_PER_SEC);
	cout << "Tiempo: " << t << " seg" << endl;
    /*cout <<"Array Ordenado :";
    printArray<int>(arr,numero_de_elementos);
    ///borrar_aroi<int>(p,n);*/
    delete[] arr;
    arr = 0;

    return 0;
}
