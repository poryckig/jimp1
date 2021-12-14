#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *bb){
    int n = mat->r;
    double **A = mat->data;
    double **b = bb->data;
    for( int k= 0; k < n-1; k++ ) {
        for( int w= k+1; w < n; w++ ) {
        if(A[k][k] == 0) return 1;
            double q = A[w][k] / A[k][k];     // A[i*n+j] to A(i,j)
            for( int i= k; i < n; i++ )
                A[w][i] -= q * A[k][i];
            b[w][0] -= q*b[k][0] ;
        }
    }                           


return 0;
}


