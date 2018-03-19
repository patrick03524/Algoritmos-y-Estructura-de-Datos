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

void ord_Cocktail(int *a, int n)
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

void printArray(int *a, int n)
{
    cout << "{ ";
    for (int i=0; i<n; i++){
        cout <<*(a+i)<<" ";
    }
    cout <<"}"<<endl;
}

int main()
{
    /*int numero_de_elementos = 1000;
    int arr[numero_de_elementos];
    crear_aroi(arr,numero_de_elementos); ///cantidad de elementos del Array*/
    int arr[] = {6,8,1,3,4,2,5,10,9,7};
    ///int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int *p = arr;
    cout <<"Array Ingresado :";
    printArray(p,n);
    ord_Cocktail(p,n);
    cout <<"Array Ordenado :";
    printArray(p,n);

    return 0;
}
