#include "eliminacja_gaussa.h"
/*
typedef struct {
    int n;   // liczba równań
    double *a; // macierz
    double *b; // wektor praiwych stron
} * ur_t;

*/
void eliminacja_gaussa(ur_t ur){
    int n = ur->n;
    double *A = ur->a;
    double *b = ur->b;
    for( int k= 0; k < n-1; k++ ) {
        for( int w= k+1; w < n; w++ ) {
            double q = A[w*n+k] / A[k*n+k];     // A[i*n+j] to A(i,j)
            for( int i= k; i < n; i++ )
                A[w*n+i] -= q * A[k*n+i];
            b[w] -= q*b[k] ;
        }
    }                           
}

