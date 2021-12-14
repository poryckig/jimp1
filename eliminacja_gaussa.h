#ifndef _ELIMINACJA_GAUSSA_H
#define _ELIMINACJA_GAUSSA_H

typedef struct {
    int n;   // liczba równań
    double *a; // macierz
    double *b; // wektor prawych stron
} * ur_t;


void eliminacja_gaussa(ur_t ur);

#endif

