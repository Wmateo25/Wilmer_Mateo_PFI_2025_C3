#include <stdio.h>

const int MAX = 10;

void lectura (int VEC[], int T);
void imprime(int VEC[], int T);
void producto(int *X, int *Y, int *Z, int T);


void main (void)
{
    int VE1 [MAX], VE2[MAX], VE3[MAX];
    lectura(VE1, MAX);
    lectura(VE2, MAX);
    producto (VE1, VE2, VE3, MAX);
    printf("\nProducto de los vectores");
    imprime (VE3, MAX);
}


void lectura(int VEC[], int T)
{
    int I; 
    printf("\n");
    for(I=0; I<T; I++)
    {
        printf("Ingrese el elemento %d:"), I+1;
        scanf("%d", &VEC[I]);
    }
}

void imprime (int VEC[], int T)

{
    int I;
    for(I=0; I<T; I++)
    printf("\nVEC[%d]: %d", I+1, VEC[I]);
}


void producto(int *X, int *Y, int *Z, int T)
{
    int I;
    for(I=0; I<T; I++)
    Z[I] = X[I] * Y[I];
}