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
	   int mx = k;
	   for (int w = k + 1; w < n; w++)
		if( A[w][k] > A[mx][k])
		   mx = w;
	  if ( mx != k){
<<<<<<< HEAD
		double *tmp1 = A[k];
		A[k] = A[mx];
		A[mx] = tmp1;
		tmp1 = b[k];
		b[k] = b[mx];
		b[mx] = tmp1;
=======
		double *tmp = A[k];
		A[k] = A[mx];
		A[mx] = tmp;
		tmp = b[k];
		b[k] = b[mx];
		b[mx] = tmp;
		
>>>>>>> 18c7a9cf04b773b5910f9c4ea4c7415c29e0444c
	  }
        for( int w= k+1; w < n; w++ ) {
	    if(A[k][k] == 0) return 1;
            double q = A[w][k] / A[k][k];    
	    for( int i= k; i < n; i++ )
                A[w][i] -= q * A[k][i];
            b[w][0] -= q*b[k][0] ;
        }
    }                           


return 0;
}



