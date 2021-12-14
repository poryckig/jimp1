#include "podstawienie_wsteczne.h"
#include "eliminacja_gaussa.h"

void podstawienie_wsteczne(ur_t ur, double *x){
    int n = ur->n;
    double *A = ur->a;
    double *b = ur->b;
    for( int w= n-1; w >= 0; w-- ) {
        double s = 0;
        for( int k= w+1; k < n; k++ )
            s += A[w*n+k]*x[k];
        x[w] = ( b[w] - s ) / A[w*n+w];
    }
}

