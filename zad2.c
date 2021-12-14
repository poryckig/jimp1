#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eliminacja_gaussa.h"
#include "podstawienie_wsteczne.h"

/*
typedef struct {
    int n;   // liczba równań
    double *a; // macierz
    double *b; // wektor prawych stron
} * ur_t;
*/
ur_t czytaj( char *nazwa_pliku ) {
    FILE *in = fopen( nazwa_pliku, "r" );
    int n = 0;
    if( fscanf( in, "%d", &n ) != 1 || n <= 0 )
        return NULL;
    
    ur_t u = malloc( sizeof *u );

    if( u == NULL )
        return NULL;

    u->a = malloc( n*n * sizeof *(u->a) );
    u->b = malloc( n * sizeof *(u->b) );
    if( u->a == NULL || u->b == NULL ) {
        free( u->b );
        free( u->a );
        free( u );
        return NULL;
    }

    u->n = n;
    for( int i= 0; i < n*n; i++ ) {
        if( fscanf( in, "%lf", u->a+i ) != 1 ) {
            free( u->b );
            free( u->a );
            free( u );
            return NULL;
        }
    }
    for( int i= 0; i < n; i++ ) {
    if( fscanf( in, "%lf", u->b+i ) != 1 ) {
      free( u->b );
      free( u->a );
      free( u );
      return NULL;
    }
    }

    return u;
}
/*
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
*/
/*
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
*/
double *solve( ur_t ur ) {
    int n = ur->n;
    if( n <= 0 )
        return NULL;
    double *x = malloc( n * sizeof *x );
    double *A = ur->a;
    double *b = ur->b;
    //eliminacja_gaussa(ur);              //*********************


    for( int k= 0; k < n-1; k++ ) {
            // Częściowy wybór elementu dominującego w k-tej kolumnie i zamiana równań
        int mx = k;
        for( int w= k+1; w < n; w++ ){
            if( A[w][k] > A[mx][k] ){
                mx = w;
            }
        }
    // Teraz sprawdzam, czy mx jest nierówne k i jeśli jest, zamieniam wiersze k i mx miejscami
        if( mx != k ) {
            double *tmp = A[k];
            A[k] = A[mx];
            A[mx] = tmp;
            double tr = b[k];
            b[k] = b[mx];
            b[mx] = tr;
        }
        for( int w= k+1; w < n; w++ ) {
            double q = A[w][k] / A[k][k];  
            for( int i= k; i < n; i++ )
                A[w][i] -= q * A[k][i];
            b[w] -= q*b[k] ;
        }
    }

    // Przekształcam u tak, aby A stała się macierzą górną trójkątną    //***METODA ELIMINACJI GAUSSA(macierz gorna trojka)
    /*
    double *A = ur->a;
    double *b = ur->b;
    for( int k= 0; k < n-1; k++ ) {
        for( int w= k+1; w < n; w++ ) {
            double q = A[w*n+k] / A[k*n+k];     // A[i*n+j] to A(i,j)
            for( int i= k; i < n; i++ )
                A[w*n+i] -= q * A[k*n+i];
            b[w] -= q*b[k] ;
        }
    } */
    podstawienie_wsteczne(ur, x);
/*                                          ****PODSTAWIENIE WSTECZNE***
    for( int w= n-1; w >= 0; w-- ) {
        double s = 0;
        for( int k= w+1; k < n; k++ )
            s += A[w*n+k]*x[k];
        x[w] = ( b[w] - s ) / A[w*n+w];
    }
*/
    return x;
}

int main( int argc, char **argv ) {
    ur_t ur = czytaj( argv[1] );

    printf( "Macierz:\n" );
    for( int i= 0; i < ur->n; i++ ) {
        for( int j= 0; j < ur->n; j++ )
            printf( "\t%g", *(ur->a+i*ur->n+j) );
        printf( "\n" );
    }
    printf( "Wektor prawych stron:\n" );
    for( int i= 0; i < ur->n; i++ )
        printf( "%g\n", *(ur->b+i) );
    

    double *x = solve( ur );

    if( x != NULL ) {
        printf( "Rozwiązanie:\n" );
        for( int i= 0; i < ur->n; i++ )
            printf( "%g\n", x[i] );
    } else {
        printf( "%s: NIE UMIEM rozwiązać tego układu!\n", argv[0] );
    }

/*
    //dodaje
    for( int i= 0; i < ur->n; i++ )
        free( ur->a[i] );
    free( ur->a );
    free( ur->b );
    free( ur );
    free( x );
*/
    return EXIT_SUCCESS;
}

