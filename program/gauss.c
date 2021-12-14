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
		double *tmp = b[k];
		b[k] = b[mx];
		b[mx] = tmp;
		tmp = A[k];
		A[k] = A[mx];
		A[mx] = tmp;

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


