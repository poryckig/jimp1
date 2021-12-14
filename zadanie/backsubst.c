#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    int w;
    int n = mat->r;
    if (b->r != n) return 2;
    if (mat->c != n) return 2;
    for (w = n-1; w >= 0; w-- ){
        if(mat->data[w][w] == 0) return 1;
        double s = 0;
        for (int k = w+1; k < n; k++){
            s += mat->data[w][k] * x->data[k][0];
        }
        x->data[w][0] = ( b->data[w][0] - s) / mat->data[w][w];
    }


    return 0;
}
