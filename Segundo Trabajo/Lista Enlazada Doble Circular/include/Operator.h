#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
using namespace std;

template <class T>
struct CLess{
    inline bool operator()(T a, T b){return a<b;}
} ;

template <class T>
struct CGreater{
    inline bool operator()(T a, T b){return a>b;}
} ;

#endif // OPERATOR_H
