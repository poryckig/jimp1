#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char **argv ) {
    int n = argc > 1 ? atoi( argv[1] ) : 10;

    srand(time(NULL));

    // Generujemy układ równań o postaci A x = b
  // tworzymy losową macierz A i dobieramy wektor b tak, by x[0] = 0, x[1] = 1, .... x[n-1] = n-1

    double *a = malloc( n*n * sizeof *a );
    double *r = malloc( n * sizeof *r );

    if( a == NULL || r == NULL ) {
        fprintf( stderr, "%s: pamięci nie ma i nie będzie!\n", argv[0] );
        return EXIT_FAILURE;
    }

    for( int w= 0; w < n; w++ ) {
        *(r+w) = 0.0;
        for( int k= 0; k < n; k++ ) {
            *(a+w*n+k) = (double)rand()/RAND_MAX;
            *(r+w) += k* *(a+w*n+k);
        }
    }

    printf( "%d\n", n );
    for( int w= 0; w < n; w++ ) {
        for( int k= 0; k < n; k++ )
            printf( "%g ", *(a+w*n+k) );
        printf( "\n" );
    }
    for( int w= 0; w < n; w++ )
        printf( "%g\n", *(r+w) );
    
    return EXIT_SUCCESS;
}

