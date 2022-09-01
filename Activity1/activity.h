#include <iostream>
#include <cmath>
// =================================================================
//
// File: activity.h
// Author: Pablo Javier Arreola Velasco A01747824
// Date:26 de Agosto de 2022
//
// =================================================================
#ifndef ACTIVITY_H
#define ACTIVITY_H

// =================================================================
// sumaIterativa. Calculate the sum from 1 to n with an iterative
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	Linear -> O(n)
// =================================================================
unsigned int sumaIterativa(unsigned int n)
{
    if (n == 1){
        return 1;
    }
    int suma = 0;
    for (int i = 0; i <= n; i++)
    {
        suma = suma + i;
    } // La complejidad es O(n)
    return suma;
}


// =================================================================
// sumaRecursiva. Calculate the sum from 1 to n with an recursive
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	Linear -> O(n)
// =================================================================
unsigned int sumaRecursiva(unsigned int n)
{
    if (n == 1){
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    else
    {
        // La complejidad es O(n)
        return n + sumaRecursiva(n - 1);
    }
}
// =================================================================
// sumaDirecta. Calculate the sum from 1 to n with a mathematical
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	Constant -> O(1)
// =================================================================
unsigned int sumaDirecta(unsigned int n) {
    if (n == 1){
        return 1;
    }
    double half = n / 2;
    half = ceil(half);
    return ((n * half) + half);
}

#endif /* ACTIVITY_H */