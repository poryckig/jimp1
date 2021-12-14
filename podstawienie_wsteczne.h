#ifndef _PODSTAWIENIE_WSTECZNE_H
#define _PODSTAWIENIE_WSTECZNE_H
#include "eliminacja_gaussa.h"
/*
typedef struct {
    int n;   // liczba równań
    double *a; // macierz
    double *b; // wektor prawych stron
} * ur_t;
*/

void podstawienie_wsteczne(ur_t ur, double *x);

#endif

